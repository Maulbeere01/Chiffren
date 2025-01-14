//
// Created by benwe on 12.11.2024.
//
#include <stdio.h>
#include <string.h>
#include "../../string_operations.h"

// braucht ein Schlüssel mit dem Geheimtext verschlüsselt wird. Dabei wird der Index der Buchstaben im Alphabet des Schlüssels verwendet um die Verschiebung der Buchstaben im Geheimtext zu bestimmen.
// ist der Schlüssel tom so wird der erste Buchstabe im Text um 20 (t ist der 20te Buchstabe im Alphabet) verschoben, der zweite Buchstabe um 15 und der dritte um 13. Der vierte Buchstabe wird dann wieder um den ersten Buchstabe des Schlüssels verschoben
// Die Verschlüsselung wird mit zunehmender Länge des Schlüssels und abnehmender Länge des Textes schwieriger zu knacken


void VigenereEncryption(char *text, char *secretKey)
{
    const char *tempSecretKey = str_lower(secretKey);
    const unsigned int lengthSecretKey = strlen(tempSecretKey);
    int keyIndex = 0;

    //printf("\nLength of key is %d\n", lengthSecretKey);
    //printf("\nOriginal Text: %s\n", text);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            // Der Text wird verschlüsselt, indem jeder Buchstabe im Text um den Buchstaben im Schlüssel verschoben wird. Ist das Ende des Schluessels erreicht, beginnt man wieder am Anfang des Schluessels, dieser wird also immer wieder verwendet
            text[i] =(char)( (text[i] - 'a' + (tempSecretKey[keyIndex % lengthSecretKey] - 'a')) % 26 + 'a');
            keyIndex++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char)((text[i] - 'A' + (tempSecretKey[keyIndex % lengthSecretKey] - 'a')) % 26 + 'A');
            keyIndex++;
        }
    }
    //printf("\nEncrypted Text: %s\n", text);
}
