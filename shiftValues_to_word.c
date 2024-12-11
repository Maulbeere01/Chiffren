//
// Created by ben10 on 12/8/24.
//
#include <stdio.h>
#include <stdlib.h>

char *shiftValues_to_word(int *shiftValues, int key_size)
{
    char *secret_word = (char *) malloc((key_size + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < key_size; i++)
    {
        secret_word[i] = shiftValues[i] + 'a';
        j++;
    }
    secret_word[key_size] = '\0';

    return secret_word;
}
