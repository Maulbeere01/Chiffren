//
// Created by benwe on 14.01.2025.
//

#include "encrypt_vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include "user_interaction.h"
#include "Vignere-Chiffre/Encryption_Logic/vigenere_decryption_logic.h"

void encrypt_vigenere()
{
    printf("Du hast Vigenère-Verschlüsselung gewählt.\nDer zu verschlüsselnde Text wird aus vigenere_chiffre_decrypted.txt gelesen. Lege dort deinen Text ab oder nutze den dort schon hinterlegten Text.\n");
    printf("Gebe zunächst dein Geheimwort ein, mit dem der Text verschlüsselt werden soll.\n");

    char *key = get_secret_word();
    printf("Geheimwort ist %s\n", key);

    char *vigenere_text = read_file_to_string("vigenere_chiffre_decrypted.txt");
    printf("Der Text ist:\n%s\n", vigenere_text);

    vigenere_encryption(vigenere_text, key);
    free(key);
    printf("Der verschlüsselte Text ist:\n%s", vigenere_text);

    printf("\nWillst du den Text in der vigenere_chiffre_encrypted.txt Datei speichern? [Y/N]\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("vigenere_chiffre_encrypted.txt", vigenere_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in vigenere_chiffre_encrypted.txt gespeichert.\n");
    }
    free(vigenere_text);
}
