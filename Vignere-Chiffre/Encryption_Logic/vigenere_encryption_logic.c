//
// Created by benwe on 12.11.2024.
//
#include <stdio.h>
#include <string.h>
#include "../../string_operations.h"

// braucht ein Schlüssel mit dem Geheimtext verschlüsselt wird. Dabei wird der Index der Buchstaben im Alphabet des Schlüssels verwendet, um die Verschiebung der Buchstaben im Geheimtext zu bestimmen.
// ist der Schlüssel tom so wird der erste Buchstabe im Text um 20 (t ist der 20te Buchstabe im Alphabet) verschoben, der zweite Buchstabe um 15 und der dritte um 13. Der vierte Buchstabe wird dann wieder um den ersten Buchstaben des Schlüssels verschoben
// die Verschlüsselung wird mit zunehmender Länge des Schlüssels und abnehmender Länge des Textes schwieriger zu knacken

void vigenere_encryption(char *text, char *secret_key)
{
    const char *temp_secret_key = str_lower(secret_key);
    const unsigned int length_secret_key = strlen(temp_secret_key);
    int key_index = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char) ((text[i] - 'a' + (temp_secret_key[key_index % length_secret_key] - 'a')) % 26 + 'a');
            key_index++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char) ((text[i] - 'A' + (temp_secret_key[key_index % length_secret_key] - 'a')) % 26 + 'A');
            key_index++;
        }
    }
}
