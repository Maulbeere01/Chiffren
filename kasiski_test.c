//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "check_if_cracked.h"
#include "frequency_analysis.h"
#include "letter_sequences.h"
#include "find_key_length.h"
#include "split_into_n_strings.h"
#include "string_operations.h"
#include "shift_values_to_word.h"
#include "Vignere-Chiffre/Decryption/decryption.h"
#include <math.h>

void kasiski_test(char *input_text, const char *letter_only, const unsigned long int len_letters_only)
{
    int *triplet_distances = find_letter_sequences(letter_only, len_letters_only);

    if (triplet_distances == NULL)
    {
        return;
    }

    int key_length = find_key_length(triplet_distances);
    free(triplet_distances);
    if (key_length == -1)
    {
        return;
    }

    char *secret_key = NULL;

    // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
    char **sub_strings = split_into_n_strings(letter_only, key_length, len_letters_only);

    if (sub_strings == NULL)
    {
        free(secret_key);
        return;
    }

    //erstellen eines arrays, indem die Verschiebewerte der Buchstaben im Geheimwort gespeichert werden koennen
    int *shift_values = malloc((key_length * sizeof(int)));

    if (shift_values == NULL)
    {
        free(secret_key);
        free(shift_values);
        return;
    }

    for (int i = 0; i < key_length; i++)
    {
        shift_values[i] = frequencyAnalysis(sub_strings[i]);
    }

    for (int i = 0; i < key_length; i++)
    {
        free(sub_strings[i]);
    }
    free(sub_strings);

    /*printf("\n");
    for (int i = 0; i < key_Size; i++) {
       printf("%d ", shiftValues[i]);
    }
    printf("\n");*/

    secret_key = shift_values_to_word(shift_values, key_length);
    free(shift_values);
    if (secret_key == NULL)
    {
        free(secret_key);
        return;
    }
    printf("\nGeheimwort ist: %s\n\n", secret_key);

    decrypt_vignere(input_text, secret_key, key_length);
    free(secret_key);
}
