//
// Created by benwe on 11.11.2024.
//
#include <stdio.h>

// Entschlüsselt einen Geheimtext, welcher mit Cäsar-Chiffre verschlüsselt wurde, mit einem Verschiebe-Wert
void caeser_decryption_logic(char *text, const int decrypted_shift_value)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char) ((text[i] - 'a' - decrypted_shift_value + 26) % 26 + 'a');
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char) ((text[i] - 'A' - decrypted_shift_value + 26) % 26 + 'A');
        }
    }
    //printf("Der entschlüsselte Text lautet:\n%s\n", text);
}
