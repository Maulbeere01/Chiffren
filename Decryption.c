//
// Created by benwe on 11.11.2024.
//
#include <stdio.h>

// Entschlüsselt den Geheimtext mit dem aus frequencyAnalysis erhaltenen Verschiebewert
void CaeserChiffreDecryption(char *text, int decryptedShiftValue)
{

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - decryptedShiftValue + 26) % 26 + 'a';
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' - decryptedShiftValue + 26) % 26 + 'A';
        }
    }

    //printf("Der entschlüsselte Text lautet:\n%s\n", text);
}