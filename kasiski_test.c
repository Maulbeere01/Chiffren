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

void kasiski_test(const char *input_text)
{
    const unsigned long int length_encrypted_text = strlen(input_text);
    /*printf("\nlength of encrypted text is %ld\n", length_encrypted_text);*/

    char encrypted_text[length_encrypted_text];
    strcpy(encrypted_text, input_text);

    char mutable_text[length_encrypted_text]; // diese Kopie des Textes wird manipuliert um den Schlüssel herauszufinden
    strcpy(mutable_text, input_text);

    str_lower(mutable_text);
    extract_letters(mutable_text);
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int length = strlen(mutable_text);
    /*printf("\nlength of cleaned text is %ld\n", length);*/

    int *distances = find_letter_sequences(mutable_text, length);

    if (distances == NULL)
    {
        return;
    }

    int key_length = find_key_length(distances);
    free(distances);
    if (key_length == -1)
    {
        return;
    }

    float german_similarity = -1;

    // muss erhalten bleiben, da moeglicherweise die Vielfachen der urspruenglichen Schluessellaenge genutzt werden muessen
    // mit weighted biggest divisor, wenn nicht korrekt, dann bei Schluessellaenge 1 anfangen und bruteforcen


    char *secret_word = NULL;

        strcpy(encrypted_text, input_text);

        // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
        char **strings = split_into_n_strings(mutable_text, key_length, length);

        if (strings == NULL)
        {
            return;
        }

        //erstellen eines arrays, indem die Verschiebewerte der Buchstaben im Geheimwort gespeichert werden koennen
        int *shiftValues = malloc((key_length * sizeof(int)));

        if (shiftValues == NULL)
        {
            return;
        }

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

        secret_word = shift_values_to_word(shiftValues, key_length);
        free(shiftValues);
        if (secret_word == NULL)
        {
            return;
        }
        //printf("\nGeheimwort ist: %s\n\n", secret_word);

        decrypt_vignere(encrypted_text, secret_word, key_length);

        german_similarity = check_if_cracked(encrypted_text);


        //printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);

    //falls text nicht geknackt, dann brute force Methode: Schluesselaenge = 1 und fuer jeden Durchlauf ++
    int counter = 1;
    if (german_similarity < 25)
    {
        printf("Kassiski-Test fehlgeschlagen \nBrute-Force-Methode folgt\n");
        do
        {
            strcpy(encrypted_text, input_text);

            // Wir erstellen ein array welches wiederum so viele strings enthält, wie der Geheimschlüssel Buchstaben hat
            char **strings = split_into_n_strings(mutable_text, counter, length);

            if (strings == NULL)
            {
                return;
            }

            //erstellen eines arrays, indem die Verschiebewerte der Buchstaben im Geheimwort gespeichert werden koennen
            int *shiftValues = malloc((counter * sizeof(int)));

            if (shiftValues == NULL)
            {
                return;
            }

            for (int i = 0; i < counter; i++)
            {
                shiftValues[i] = frequencyAnalysis(strings[i]);
            }

            for (int i = 0; i < counter; i++)
            {
                free(strings[i]);
            }
            free(strings);

            /*printf("\n");
            for (int i = 0; i < key_Size; i++) {
               printf("%d ", shiftValues[i]);
            }
            printf("\n");*/

            secret_word = shift_values_to_word(shiftValues, counter);
            free(shiftValues);
            if (secret_word == NULL)
            {
                return;
            }
            //printf("\nGeheimwort ist: %s\n\n", secret_word);

            decrypt_vignere(encrypted_text, secret_word, counter);

            german_similarity = check_if_cracked(encrypted_text);
            /*printf("counter: %d\n", counter);*/
            counter++;
        }while (german_similarity < 25 && german_similarity != -1 && counter <= 256);

    }
    if (german_similarity == -1)
    {
        printf("\n\nCodebrechen konnte moeglicherweise nicht korrekt durchgefuehrt werden, da Datei mit den 1000 hauefigsten Woertern nicht geoeffnet werden konnte.\n");
        printf("\nDer entschluesselte Text koennte sein:\n%s\n", encrypted_text);
        printf("\nDas Geheimwort koennte sein: %s\n\n", secret_word);
    }

    if (german_similarity != -1)
    {
        printf("\nGeheimwort ist: %s\n\n", secret_word);

        /*printf("Entschlüsselter Text ist: \n%s", encrypted_text);*/
        printf("Der entschluesselte Text ist:\n%s\n", encrypted_text);
    }

    if (german_similarity < 25 && german_similarity != -1 && counter > 256)
    {
        printf("\nCodebrechen war nicht erfolgreich\n");
    }

    free(secret_word);
}
