//
// Created by ben10 on 12/7/24.
//
#include <ctype.h>

//Macht alle Grossbuchstaben in einem String zu Kleinbuchstaben
char *str_lower(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = (char) (tolower(string[i]));
    }
    return string;
}

// entfernt alle Zeichen ausser a bis z, auch leerzeichen, etc.
char *extract_letters(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] < 'a' || string[i] > 'z')
        {
            for (int j = i; string[j] != '\0'; j++)
            {
                string[j] = string[j + 1];
            }
            i--;
        }
    }
    return string;
}
