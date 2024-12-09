//
// Created by benwe on 06.12.2024.
//

/*int distances[length];            // Array für die Abstände, hier kann ich noch *distances mit NULL initialisieren und fuer jeden gefunden Abstand mit realloc das array vergroessern um Speicherplatzverschwendung zu vermeiden

 for (int i = 0; i < length; i++) {
     distances[i] = 0;
 }*/

#include <stdio.h>
#include <stdlib.h>

int* find_letter_sequences(char *text, const unsigned long int length) {

    int *distances = NULL;  // leeres Array initialisieren
    int index = 0;             // zählt wie viele Elemente dem array hinzugefügt wurden

    // Schritt 1: Abstände berechnen. Manche Abstände werden doppelt gezählt, aber egal, da wir den häufigst gemeinsamen Teiler suchen
    for (int i = 0; i <= length - 3; i++) {
        for (int j = i + 3; j <= length; j++) {
            if (text[i] == text[j] &&
                text[i + 1] == text[j + 1] &&
                text[i + 2] == text[j + 2]) {

                distances = realloc(distances, (index + 1) * sizeof(int));
                distances[index] = j - i;
                /*
                printf("\nAbstand von %c%c%c (an Stelle %d) zur Wiederholung ist %d und an Index %d in distances gespeichert\n", text[i],text[i+1], text[i+2], i, distances[index], index);
                */
                index++;
                }
        }
    }
    distances = realloc(distances, (index + 1) * sizeof(int));
    distances[index] = 0;
    printf("die Abstaende sind:\n");
    for (int i = 0; distances[i] != 0; i++)
    {
        printf("%d ", distances[i]);
    }
    return distances;
}
