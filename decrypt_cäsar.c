//
// Created by benwe on 14.01.2025.
//
#include <ctype.h>

#include "Ceaser-Chiffre/c_decryption.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt_cäsar()
{
    char input[256];

    printf("Du hast Cäsar-Entschlüsselung gewählt.\nDer zu entschlüsselnde Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\n");
    printf("Gebe den Wert ein, mit dem der Text verschlüsselt wurde:\n");

    fgets(input, 250, stdin);

    int shift_value = atoi(input);
    while (shift_value <= 0 || shift_value > 25)
    {
        printf("Ungültige Eingabe, wähle eine Zahl von 1 bis 25:\n");
        fgets(input, 250, stdin);

        shift_value = atoi(input);
    }

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
    printf("%s", cäsar_text);

    c_decryption(cäsar_text, shift_value);
    printf("Dein verschlüsselter Text ist:\n%s", cäsar_text);

    printf("\nWillst du den Text in der encrypted.txt Datei speichern? [Y/N]\n");
    char user_choice = 'x';
    scanf("%1c", &user_choice);
    user_choice = (char)tolower(user_choice);
    while (user_choice != 'y' && user_choice != 'n')
    {
        printf("Nutze Y für Ja oder N für Nein\n");
        scanf("%1c", &user_choice);
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


