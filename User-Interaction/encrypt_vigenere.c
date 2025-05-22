//
// Created by benwe on 14.01.2025.
//

#include "encrypt_vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include "user_interaction.h"
#include "../Vignere-Chiffre/Encryption_Logic/vigenere_encryption_logic.h"

void encrypt_vigenere()
{
    printf("Du hast Vigenère-Verschlüsselung gewählt.\nDer zu verschlüsselnde Text wird aus vigenere_chiffre_decrypted.txt gelesen. Lege dort deinen Text ab oder nutze den dort schon hinterlegten Text.\n");
    printf("Gebe zunächst dein Geheimwort ein, mit dem der Text verschlüsselt werden soll.\n");

    char *key = get_secret_word();

    char *vigenere_text = read_file_to_string("data/vigenere_chiffre_decrypted.txt");
    printf("\nDer zu verschlüsselnde Text ist:\n\n%s", vigenere_text);

    vigenere_encryption(vigenere_text, key);
    free(key);
    printf("\n\n\nDein verschlüsselter Text ist:\n\n%s\n\n", vigenere_text);

    printf("\nWillst du den Text in der vigenere_chiffre_encrypted.txt Datei speichern?\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("data/vigenere_chiffre_encrypted.txt", vigenere_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in vigenere_chiffre_encrypted.txt gespeichert.\n");
    }
    free(vigenere_text);
}
