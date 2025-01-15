//
// Created by ben10 on 12/8/24.
//

#include <stdio.h>
#include <string.h>
// Entschlüsselt Vigenere, indem mit dem Verschlüsselwort, jeder Buchstabe im Geheimtext nach links verschoben wird
void vigenere_decryption_logic(char *text, const char *secret_key, const int key_size)
{
    int keyIndex = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char)((text[i] - 'a' - (secret_key[keyIndex % key_size] - 'a') + 26) % 26 + 'a');
            keyIndex++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char)((text[i] - 'A' - (secret_key[keyIndex % key_size] - 'a') + 26) % 26 + 'A');
            keyIndex++;
        }
    }
    /*
    printf("%s\n", text);
    */
}
