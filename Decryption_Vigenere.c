//
// Created by ben10 on 12/8/24.
//

#include <stdio.h>
#include <string.h>
#include "check_if_cracked.h"

void decrypt_vignere(char *text, char *secret_key, int key_size)
{
    int keyIndex = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - (secret_key[keyIndex % key_size] - 'a') + 26) % 26 + 'a';
            keyIndex++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' - (secret_key[keyIndex % key_size] - 'a') + 26) % 26 + 'A';
            keyIndex++;
        }
    }
    /*
    printf("%s\n", text);
    */
}
