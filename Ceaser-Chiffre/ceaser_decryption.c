//
// Created by benwe on 11.11.2024.
//
#include <stdio.h>

// Entschlüsselt einen Geheimtext, welcher mit Ceaser-Chiffre verschluesselt wurde, mit dem Verschiebewert
void caeser_chiffre_decryption(char *text, int decrypted_shift_value)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - decrypted_shift_value + 26) % 26 + 'a';
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' - decrypted_shift_value + 26) % 26 + 'A';
        }
    }
    //printf("Der entschlüsselte Text lautet:\n%s\n", text);
}
