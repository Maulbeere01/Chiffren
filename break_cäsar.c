//
// Created by benwe on 14.01.2025.
//

#include "break_cäsar.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency_analysis.h"
#include "Ceaser-Chiffre/c_decryption.h"

void break_cäsar()
{

    printf("Du hast Cäsar-Brechen gewählt.\nDer zu brechende Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\nBereit?\n<press any button to continue>");
    scanf("%*c");

    FILE *input_file = fopen("encrypted.txt", "r");
    if (input_file == NULL)
    {
        printf("Fehler beim öffnen von encrypted.txt");
        exit(-1);
    }

    char cäsar_text[50000];
    cäsar_text[0] = '\0';
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), input_file) != NULL)
    {
        strcat(cäsar_text, buffer); //
    }

    fclose(input_file);
    printf("Der verschlüsselte Text ist\n%s\n", cäsar_text);

    int decrypted_shift_value = frequencyAnalysis(cäsar_text);

    c_decryption(cäsar_text, decrypted_shift_value);

    printf("\nDer entschlüsselte Text ist:\n%s\n", cäsar_text);


    printf("\nWillst du den Text in der decrypted.txt Datei speichern? [Y/N]\n");
    char user_choice = 'x';
    while (user_choice != 'y' && user_choice != 'n')
    {
        printf("Nutze Y für Ja oder N für Nein\n");
        scanf("%1c", &user_choice);
        fflush(stdin);
        user_choice = (char)tolower(user_choice);
    }

    if (user_choice == 'y')
    {
        FILE *output_file = fopen("decrypted.txt", "w");
        if (output_file == NULL)
        {
            printf("Fehler beim öffnen von decrypted.txt");
            exit(-1);
        }
        fprintf(output_file, "%s", cäsar_text);
        printf("Der verschlüsselte Text wurde in decrypted.txt gespeichert.\n");
        fclose(output_file);
    }
}
