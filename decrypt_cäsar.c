//
// Created by benwe on 14.01.2025.
//
#include <ctype.h>

#include "Ceaser-Chiffre/c_decryption.h"
#include <stdio.h>
#include <stdlib.h>
#include "user_interaction.h"

void decrypt_cäsar()
{
    printf("Du hast Cäsar-Entschlüsselung gewählt.\nDer zu entschlüsselnde Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\n");
    printf("Gebe den Wert ein, mit dem der Text verschlüsselt wurde:\n");

    int shift_value = get_valid_shift_value();
    char *cäsar_text = read_file_to_string("encrypted.txt");
    printf("%s", cäsar_text);

    c_decryption(cäsar_text, shift_value);
    printf("Dein verschlüsselter Text ist:\n%s", cäsar_text);

    printf("\nWillst du den Text in der encrypted.txt Datei speichern? [Y/N]\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("decrypted.txt", cäsar_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in decrypted.txt gespeichert.\n");
    }
    free(cäsar_text);
}


