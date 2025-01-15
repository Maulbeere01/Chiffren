//
// Created by benwe on 15.01.2025.
//

#include "decrypt_vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_interaction.h"
#include "Vignere-Chiffre/Decryption/decryption.h"

void decrypt_vigenere()
{
    printf("Du hast Vigenère-Entschlüsselung gewählt.\nDer zu entschlüsselnde Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon dort hinterlegten Text.\n");
    printf("Gebe zunächst dein Geheimwort ein, mit dem der Text verschlüsselt wurde.\n");

    char *key = get_secret_word();
    printf("Geheimwort ist %s\n", key);
    const int key_length = strlen(key);
    printf("keylength is %d\n", key_length);

    char *vigenere_text = read_file_to_string("encrypted.txt");
    printf("Der verschlüsselte Text ist:\n%s\n", vigenere_text);

    decrypt_vignere(vigenere_text, key, key_length);
    free(key);
    printf("Der entschlüsselte Text ist:\n%s", vigenere_text);

    printf("\nWillst du den Text in der decrypted.txt Datei speichern? [Y/N]\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("decrypted.txt", vigenere_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in encrypted.txt gespeichert.\n");
    }
    free(vigenere_text);
}
