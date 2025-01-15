//
// Created by benwe on 14.01.2025.
//


#include <stdio.h>
#include <stdlib.h>
#include "user_interaction.h"
#include "Ceaser-Chiffre/Encryption_Logic/caeser_encryption_logic.h"

void encrypt_caesar()
{
    printf("Du hast Cäsar-Verschlüsselung gewählt.\nDer zu verschlüsselnde Text wird aus caeser_chiffre_decrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\n");
    printf("Gebe zunächst deinen geheimen Wert ein, um den jeder Buchstaben verschoben werden soll:\n");

    int shift_value = get_valid_shift_value();

    char *cäsar_text = read_file_to_string("caeser_chiffre_decrypted.txt");

    printf("%s", cäsar_text);
    caeser_encryption_logic(cäsar_text, shift_value);
    printf("Dein verschlüsselter Text ist:\n%s", cäsar_text);

    printf("\nWillst du den Text in der caeser_chiffre_encrypted.txt Datei speichern? [Y/N]\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
     write_string_to_file("caeser_chiffre_encrypted.txt", cäsar_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in caeser_chiffre_encrypted.txt gespeichert.\n");
    }
    free(cäsar_text);
}
