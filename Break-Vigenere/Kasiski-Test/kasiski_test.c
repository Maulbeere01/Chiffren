//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../frequency_analysis.h"
#include "find_triplets.h"
#include "find_key_length.h"
#include "split_into_n_strings.h"
#include "shift_values_to_word.h"
#include "../../Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.h"

void kasiski_test(char *input_text, const char *letter_only, const unsigned long int len_letters_only)
{
    int *triplet_distances = find_triplets(letter_only, len_letters_only);

    if (triplet_distances == NULL)
    {
        free(triplet_distances);
        return;
    }

    const int key_length = find_key_length(triplet_distances);
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
        free(sub_strings);
        return;
    }

    //erstellen eines arrays, indem die Verschiebe werte der Buchstaben im Geheimwort gespeichert werden können
    int *shift_values = malloc((key_length * sizeof(int)));

    if (shift_values == NULL)
    {
        free(sub_strings);
        free(shift_values);
        return;
    }

    for (int i = 0; i < key_length; i++)
    {
        shift_values[i] = frequency_analysis(sub_strings[i]);
    }

    for (int i = 0; i < key_length; i++)
    {
        free(sub_strings[i]);
    }
    free(sub_strings);

    /*printf("\n");
    for (int i = 0; i < key_length; i++) {
       printf("%d ", shift_values[i]);
    }
    printf("\n");*/

    secret_key = shift_values_to_word(shift_values, key_length);
    free(shift_values);
    if (secret_key == NULL)
    {
        free(secret_key);
        return;
    }
    printf("\nGeheimwort, mit dem der Text verschlüsselt wurde, ist: %s\n", secret_key);

    vigenere_decryption_logic(input_text, secret_key, key_length);

    free(secret_key);
    /*printf("\nDer mit Kasiski entschlüsselte Text ist: \n%s\n\n", input_text);*/
}
