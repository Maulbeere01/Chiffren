//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "check_if_cracked.h"
#include "Häufigkeitsanalyse.h"
#include "Letter_Sequences.h"
#include "find_key_length.h"
#include "split_into_n_strings.h"
#include "string_operations.h"
#include "shiftValues_to_word.h"
#include "Decryption_Vigenere.h"

void kasiski_test(char *input_text) {

    const unsigned long int length_encrypted_text = strlen(input_text);
    /*printf("\nlength of encrypted text is %ld\n", length_encrypted_text);*/
    char encrypted_text[length_encrypted_text];
    strcpy(encrypted_text, input_text);

    char mutable_text[length_encrypted_text]; // diese Kopie des Textes wird manipuliert um den Schlüssel herauszufinden
    strcpy(mutable_text, input_text);

    strlower(mutable_text);

    extract_letters(mutable_text);

    /*
    printf("%s\n", text);
    */

    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int length = strlen(mutable_text); // Länge des Strings berechnen
    /*printf("\nlength of cleaned text is %ld\n", length);*/

    int *distances = find_letter_sequences(mutable_text, length);
    int key_Size = find_key_size(distances, length);
    free(distances);

    // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
    char **strings = split_into_n_strings(mutable_text, key_Size, length);

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
    free(shiftValues);

    decrypt_vignere(encrypted_text, secret_word, key_Size);

    float german_similarity = check_if_cracked(encrypted_text);

    printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);

    int initial_key_size = key_Size;

    while(german_similarity < 25) {
        key_Size += initial_key_size;
        strcpy(encrypted_text, input_text);

        char **strings = split_into_n_strings(mutable_text, key_Size, length);

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
        free(shiftValues);

        decrypt_vignere(encrypted_text, secret_word, key_Size);

        german_similarity = check_if_cracked(encrypted_text);

        printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);
    }
    /*printf("Der entschluesselte Text ist:\n%s\n", encrypted_text);*/
    }

