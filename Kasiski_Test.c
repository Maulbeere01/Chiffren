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
#include "string_operations.h"
#include "shiftValues_to_word.h"
#include "Decryption_Vigenere.h"


void kasiski_test(char *encrypted_text) {

    const unsigned long int length_encrypted_text = strlen(encrypted_text);
    /*printf("\nlength of encrypted text is %ld\n", length_encrypted_text);*/

    char text[length_encrypted_text];
    strcpy(text, encrypted_text);

    strlower(text);

    extract_letters(text);

    /*
    printf("%s\n", text);
    */

    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int length = strlen(text); // Länge des Strings berechnen
    /*printf("\nlength of cleaned text is %ld\n", length);*/

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

    /*printf("\n");
    for (int i = 0; i < key_Size; i++) {
       printf("%d ", shiftValues[i]);
    }
    printf("\n");*/

    char *secret_word = shiftValues_to_word(shiftValues, key_Size);
    free(distances);
    free(shiftValues);

    decrypt_vignere(encrypted_text, secret_word, key_Size);

    printf("Der entschluesselte Text ist:\n%s\n", encrypted_text);
    }

