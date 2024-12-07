//
// Created by ben10 on 12/7/24.
//
#include <ctype.h>

char *strlower(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower(string[i]);
    }
    return string;
}

// entfernt alle Zeichen ausser a bis z
char *extract_letters(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] < 'a' || text[i] > 'z')
        {
            for (int j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j + 1];
            }
            i--;
        }
    }
    return text;
}