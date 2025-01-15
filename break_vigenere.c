//
// Created by benwe on 15.01.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brute_force.h"
#include "get_word_match_percentage.h"
#include "kasiski_test.h"
#include "string_operations.h"
#include "user_interaction.h"

void break_vigenere()
{
    printf("Du hast Vigenère-Brechen gewählt.\nDer zu brechende Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\nBereit?\n<press any button to continue>");
    scanf("%*c");

    char *input_text = read_file_to_string("encrypted.txt");
    printf("Der verschlüsselte Text ist:\n%s\n", input_text);

    // Erstellen einer Kopie des Originaltextes
    unsigned long long int len_org_text = strlen(input_text) + 1;
    char original_backup[len_org_text];
    strcpy(original_backup, input_text);

    // letters only enthält nur die Buchstaben des verschlüsselten Textes
    char letters_only[len_org_text]; // diese Kopie des Textes wird manipuliert, um den Schlüssel herauszufinden
    strcpy(letters_only, input_text);
    str_lower(letters_only);
    extract_letters(letters_only);
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int len_letters_only = strlen(letters_only) + 1;

    // printf("\nlength of cleaned text is %ld\n", len_letters_only);

    kasiski_test(input_text, letters_only, len_letters_only);

    float german_similarity = get_word_match_percentage(input_text);
    printf("german_similarity: %.2f\n", german_similarity);

    //printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);
    if (german_similarity < 25)
    {
        printf("Kasiski-Test fehlgeschlagen \nBrute-Force-Methode folgt\n");
        german_similarity = brute_force(original_backup, german_similarity, len_org_text, letters_only, len_letters_only);

        if (german_similarity == -1)
        {
            printf("\n\nCodebrechen ist fehlgeschlagen\n");
        }

        if (german_similarity >= 25)
        {
            printf("Der entschlüsselte Text ist:\n%s\n", original_backup);

            printf("\nWillst du den Text in der decrypted.txt Datei speichern? [Y/N]\n");
            const char user_choice = get_user_choice();

            if (user_choice == 'y')
            {
                write_string_to_file("decrypted.txt", input_text);
            }
            else
            {
                printf("Der verschlüsselte Text wurde NICHT in encrypted.txt gespeichert.\n");
            }
            free(input_text);
        }

        if (german_similarity < 25 && german_similarity != -1)
        {
            printf("\nKein passenden Schlüssel gefunden, Codebrechen war nicht erfolgreich\n"
                "Der Schlüssel im Verhältnis zur Text Länge ist zu hoch um den Text mit Häufigkeitsanalyse zu brechen\n");
        }
    }
    else
    {
        printf("Der entschlüsselte Text ist:\n%s\n", input_text);

        printf("\nWillst du den Text in der decrypted.txt Datei speichern? [Y/N]\n");
        const char user_choice = get_user_choice();

        if (user_choice == 'y')
        {
            write_string_to_file("decrypted.txt", input_text);
        }
        else
        {
            printf("Der verschlüsselte Text wurde NICHT in encrypted.txt gespeichert.\n");
        }
        free(input_text);
    }
}
