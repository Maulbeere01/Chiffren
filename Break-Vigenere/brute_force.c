//
// Created by benwe on 09.01.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_word_match_percentage.h"
#include "../frequency_analysis.h"
#include "Kasiski-Test/shift_values_to_word.h"
#include "Kasiski-Test/split_into_n_strings.h"
#include "../Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.h"

// Startet bei Schlüssellänge 1 und probiert alle möglichen Längen bis 256 aus
float brute_force(char *input_text, float german_similarity, unsigned long long int len_input_text,
                  const char *letter_only, const unsigned long int len_letters_only)
{
    char tmp_text[len_input_text];
    int key_length = 1;

    while (german_similarity < 25 && key_length <= 256)
    {
        strcpy(tmp_text, input_text);

        // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
        char **sub_strings = split_into_n_strings(letter_only, key_length, len_letters_only);

        if (sub_strings == NULL)
        {
            free(sub_strings);
            exit(-1);
        }

        //erstellen eines arrays, indem die Verschiebe Werte der Buchstaben im Geheimwort gespeichert werden können
        int *shift_values = malloc((key_length * sizeof(int)));

        if (shift_values == NULL)
        {
            free(shift_values);
            exit(-1);
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
        for (int i = 0; i < counter; i++) {
           printf("%d ", shift_values[i]);
        }
        printf("\n");*/

        char *secret_key = NULL;
        secret_key = shift_values_to_word(shift_values, key_length);
        free(shift_values);
        if (secret_key == NULL)
        {
            free(secret_key);
            exit(-1);
        }

        vigenere_decryption_logic(tmp_text, secret_key, key_length);

        german_similarity = get_word_match_percentage(tmp_text);
        // printf("Bei Schlüssellänge %d ist german_similarity bei %f\n\n", key_length, german_similarity);
        if (german_similarity >= 25)
        {
            printf("\nGeheim Schlüssel ist %s \n", secret_key);
        }

        free(secret_key);

        /*printf("counter: %d\n", counter);*/
        key_length++;
    }

    if (german_similarity >= 25)
    {
        strcpy(input_text, tmp_text);
        printf("Übereinstimmung mit der deutschen Sprache ist ca. [%.2f%%]\n", german_similarity);
    }
    return german_similarity;
}
