//
// Created by benwe on 14.01.2025.
//
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include "user_interaction.h"
#include "../Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.h"

void decrypt_caesar()
{
    printf("Du hast Cäsar-Entschlüsselung gewählt.\nDer zu entschlüsselnde Text wird aus caeser_chiffre_encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\n");
    printf("Gebe den Wert ein, mit dem der Text verschlüsselt wurde:\n");

    int shift_value = get_valid_shift_value();
    char *cäsar_text = read_file_to_string("caeser_chiffre_encrypted.txt");
    printf("\nDer verschlüsselte Text ist:\n\n%s", cäsar_text);

    caeser_decryption_logic(cäsar_text, shift_value);
    printf("\n\n\nDer entschlüsselte Text ist:\n\n%s\n\n", cäsar_text);

    printf("\nWillst du den Text in der caeser_chiffre_decrypted.txt Datei speichern?\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("caeser_chiffre_decrypted.txt", cäsar_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in caeser_chiffre_decrypted.txt gespeichert.\n");
    }
    free(cäsar_text);
}
