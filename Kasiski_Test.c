//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Häufigkeitsanalyse.h"
#include "Letter_Sequences.h"
#include "find_key_length.h"
#include "split_into_n_strings.h"

void kasiski_test(char *text) {

    strlwr(text);

    for (int i = 0; text[i] != '\0'; i++)
        {
        if(text[i] < 'a' || text[i] > 'z')
            {
            for (int j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j + 1];
            }
            i--;
        }
    }
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    int length = strlen(text); // Länge des Strings berechnen

    int *distances = find_letter_sequences(text, length);
    int key_Size = find_key_size(distances, length);

    // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
    char **strings = split_into_n_strings(text, key_Size, length);




    int *shiftValues = malloc((key_Size * sizeof(int)));

    for (int i = 0; i < key_Size; i++) {
        shiftValues[i] = frequencyAnalysis(strings[i]);
    }

    for (int i = 0; i < key_Size; i++) {
        free(strings[i]);
    }
    free(strings);

    for (int i = 0; i < key_Size; i++) {
       printf("%d ", shiftValues[i]);
    }


    free(distances);
    free(shiftValues);
}

