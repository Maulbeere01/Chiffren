//
// Created by benwe on 07.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
// teilt den Geheimtext in so viele Strings wie der Schlüssel lang ist. In die Strings kommen dann jeweils die Buchstaben, die vom gleichen Buchstaben verschlüsselt wurden

char **split_into_n_strings(char *text,int key_Size,int length) {

    // wir allokieren ein array mit so vielen Strings wie wir keys haben
    char **strings = malloc((key_Size * sizeof(char *)));

    if (strings == NULL) {
        printf("speicherzuweisung Fehler\n");
        return NULL;
    }
    //wir allokieren strings mit passender Größe und speichern sie in dem array strings
    for (int i = 0; i < key_Size; i++) {
        strings[i] = malloc(((length / key_Size) + 1) * sizeof(char));

        if (strings[i] == NULL) {
            printf("speicherzuweisung Fehler\n");
            return NULL;
        }
    }
    // initialisieren der strings, jeweils nur die Buchstaben in einem String, welche mit dem gleichen Buchstaben verschoben wurden
    for (int i = 0; i < key_Size; i++) {

        int j = 0;
        for (int k = i; k < length; k += key_Size) { // i bestimmt den String in den geschrieben wird, j bestimmt den Platz des Characters im string,
            strings[i][j] = text[k];
            j++;
        }

        strings[i][j] = '\0';
    }

    printf("Ausgabe der Strings:");
    for (int i = 0; i < key_Size; i++) {
        printf("\n%s\n", strings[i]);
    }

    return strings;
}
