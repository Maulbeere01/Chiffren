//
// Created by benwe on 14.01.2025.
//

#include "encrypt_vigenere.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vignere-Chiffre/Encryption/encryption.h"
int is_key_valid(char *key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if(key[i] < 'a' ||  key[i] > 'z')
        {
            return -1;
        }
    }
    return 1;
}
void encrypt_vigenere()
{
    char key[256];

    printf("Du hast Vigenère-Verschlüsselung gewählt.\nDer zu verschlüsselnde Text wird aus decrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\n");

    while(1)
    {
        printf("Gebe zunächst dein Geheimwort ein, mit dem der Text verschlüsselt werden soll, es sind nur Buchstaben erlaubt, keine Sonderzeichen:\n");
        fgets(key, 256, stdin);
        strlwr(key);
        int len_key = strlen(key);
        if (len_key > 0 && key[len_key - 1] == '\n') {
            key[len_key - 1] = '\0';
        }
        if(is_key_valid(key) == 1)break;
    }

    printf("Geheimwort ist %s\n", key);
    FILE *input_file = fopen("decrypted.txt", "r");
    if (input_file == NULL)
    {
        printf("Fehler beim öffnen von entschlüsselt.txt");
        exit(-1);
    }

    char vigenere_text[50000];
    vigenere_text[0] = '\0';
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), input_file) != NULL)
    {
        strcat(vigenere_text, buffer); //
    }

    fclose(input_file);
    printf("Der Text ist:\n%s\n", vigenere_text);

    vigenere_encryption(vigenere_text, key);
    printf("Der verschlüsselte Text ist:\n%s", vigenere_text);

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
        FILE *output_file = fopen("encrypted.txt", "w");
        if (output_file == NULL)
        {
            printf("Fehler beim öffnen von verschlüsselt.txt");
            exit(-1);
        }
        fprintf(output_file, "%s", vigenere_text);
        printf("Der verschlüsselte Text wurde in encrypted.txt gespeichert.\n");
        fclose(output_file);
    }
}
