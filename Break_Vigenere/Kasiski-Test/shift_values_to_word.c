//
// Created by ben10 on 12/8/24.
//
#include <stdio.h>
#include <stdlib.h>
// Übersetzt die Verschiebewerte des Geheimwortes in eine Buchstabenfolge
char *shift_values_to_word(const int *shiftValues, int key_size)
{
    char *secret_word = (char *) malloc((key_size + 1) * sizeof(char));
    if (secret_word == NULL)
    {
        printf("\nFehlerhafte Speicheranfrage in shift_values_to_word\n");
        free(secret_word);
        exit(-1);
    }
    int j = 0;
    for (int i = 0; i < key_size; i++)
    {
        secret_word[i] = (char) (shiftValues[i] + 'a');
        j++;
    }
    secret_word[key_size] = '\0';

    return secret_word;
}
