//
// Created by benwe on 07.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
// teilt den Geheimtext in so viele Strings wie der Schlüssel Buchstaben hat. In die Strings kommen dann jeweils die Buchstaben des Geheimtextes, die vom gleichen Buchstaben des Geheimwortes  verschlüsselt wurden
char **split_into_n_strings(char *text, int n, const unsigned long int length)
{
    // wir allokieren ein array mit so vielen Strings wie wir keys haben
    char **strings = malloc((n * sizeof(char *)));
    if (strings == NULL)
    {
        printf("speicherzuweisung Fehler\n");
        return NULL;
    }

    //wir allokieren strings mit passender Größe und speichern sie in dem array strings
    for (int i = 0; i < n; i++)
    {
        // allokiert speicher für jeden string mit der länge: ceil(length / n) + 1
        // (length + n - 1) / n ist eine integer-berechnung, die ceil(length / n) nachbildet.
        // das "+1" stellt sicher, dass genug platz für den null-terminator ('\0') vorhanden ist.
        strings[i] = malloc(((length + n - 1) / n + 1) * sizeof(char));

        if (strings[i] == NULL)
        {
            printf("speicherzuweisung Fehler\n");
            return NULL;
        }
    }
    // initialisieren der strings, jeweils nur die Buchstaben in einem String, welche mit dem gleichen Buchstaben verschoben wurden
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (int k = i; k < length; k += n)
        {
            // i bestimmt den String in den geschrieben wird, j bestimmt den Platz des Characters im string,
            strings[i][j] = text[k];
            j++;
        }

        strings[i][j] = '\0';
    }

    /*printf("\nAusgabe der Strings:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%s\n", strings[i]);
    }*/

    return strings;
}
