//
// Created by benwe on 15.01.2025.
//

#include "decrypt_vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_interaction.h"
#include "../Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.h"

void decrypt_vigenere()
{
    printf("Du hast Vigenère-Entschlüsselung gewählt.\nDer zu entschlüsselnde Text wird aus vigenere_chiffre_encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon dort hinterlegten Text.\n");
    printf("Gebe zunächst dein Geheimwort ein, mit dem der Text verschlüsselt wurde.\n");

    char *key = get_secret_word();
    const int key_length = strlen(key);

    char *vigenere_text = read_file_to_string("vigenere_chiffre_encrypted.txt");
    printf("\nDer verschlüsselte Text ist:\n\n%s", vigenere_text);

    vigenere_decryption_logic(vigenere_text, key, key_length);
    free(key);
    printf("\n\n\nDer entschlüsselte Text ist:\n\n%s\n\n", vigenere_text);

    printf("\nWillst du den Text in der vigenere_chiffre_decrypted.txt Datei speichern?\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("vigenere_chiffre_decrypted.txt", vigenere_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in vigenere_chiffre_decrypted.txt gespeichert.\n");
    }
    free(vigenere_text);
}
