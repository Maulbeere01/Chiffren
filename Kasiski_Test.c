//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "check_if_cracked.h"
#include "Frequency_Analasys.h"
#include "Letter_Sequences.h"
#include "Find_Key_Length.h"
#include "Split_into_n_Strings.h"
#include "String_Operations.h"
#include "Shift_Values_to_Word.h"
#include "Decryption_Vigenere.h"

void kasiski_test(char *input_text)
{
    const unsigned long int length_encrypted_text = strlen(input_text);
    /*printf("\nlength of encrypted text is %ld\n", length_encrypted_text);*/

    char encrypted_text[length_encrypted_text];
    strcpy(encrypted_text, input_text);

    char mutable_text[length_encrypted_text]; // diese Kopie des Textes wird manipuliert um den Schlüssel herauszufinden
    strcpy(mutable_text, input_text);

    strlower(mutable_text);
    extract_letters(mutable_text);
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int length = strlen(mutable_text);
    /*printf("\nlength of cleaned text is %ld\n", length);*/

    int *distances = find_letter_sequences(mutable_text, length);
    int key_length = find_key_size(distances, length);
    free(distances);


    float german_similarity = -1;


    int intial_key_length = key_length;

    char *secret_word = NULL;

    do
    {
        if (german_similarity != -1)
        {
            key_length += intial_key_length;
        }
        strcpy(encrypted_text, input_text);

        // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
        char **strings = split_into_n_strings(mutable_text, key_length, length);

        int *shiftValues = malloc((key_length * sizeof(int)));

        for (int i = 0; i < key_length; i++)
        {
            shiftValues[i] = frequencyAnalysis(strings[i]);
        }


        for (int i = 0; i < key_length; i++)
        {
            free(strings[i]);
        }
        free(strings);

        /*printf("\n");
        for (int i = 0; i < key_Size; i++) {
           printf("%d ", shiftValues[i]);
        }
        printf("\n");*/

        secret_word = shiftValues_to_word(shiftValues, key_length);
        free(shiftValues);
        //printf("\nGeheimwort ist: %s\n\n", secret_word);

        decrypt_vignere(encrypted_text, secret_word, key_length);

        german_similarity = check_if_cracked(encrypted_text);

        //printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);
    } while (german_similarity < 25);

    printf("\nGeheimwort ist: %s\n\n", secret_word);
    free(secret_word);

    printf("Entschlüsselter Text ist: \n%s", encrypted_text);
    /*printf("Der entschluesselte Text ist:\n%s\n", encrypted_text);*/
}
