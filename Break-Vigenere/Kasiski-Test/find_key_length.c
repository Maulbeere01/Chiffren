//
// Created by benwe on 06.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "weighted_biggest_divisor.h"

//Bestimmt die Schlüssellänge, indem der häufigste und grösste vorkommende Teiler der Abstände bestimmt wird. Die Größe der Teiler wird positiv gewichtet, heißt ein großer Teiler kann, obwohl er nicht am häufigsten vorkommt bevorzugt werden.
int find_key_length(const int *distances)
{
    int *divisors = NULL; // Array um alle Teiler der Abstände, welche aus distances berechnet werden zu speichern
    int index = 0;

    /*printf("\nTeiler der Abstände sind:\n");*/
    for (int i = 0; distances[i] != 0; i++)
    {
        for (int j = 1; j < distances[i]; j++) // nested loop, für jeden Abstand werden alle Teiler gesucht
        {
            if (distances[i] % j == 0) // Alle Teiler der Abstände werden bestimmt
            {
                int *temp = realloc(divisors, (index + 1) * sizeof(int));
                // bei jedem gefundenen Teiler wird das Array um 1 Wert vergrössert, in temp Zeiger zwischenspeichern um zu prüfen ob Speicheranfrage erfolgreich, ansonsten geht der Zugriff auf den ursprünglichen Speicher verloren.
                if (temp == NULL)
                {
                    printf("Speicherzuweisung Fehler in find_key_length");
                    free(divisors);
                    exit(-1);
                }
                divisors = temp;
                divisors[index] = j; // Der gefundene Teiler wird in divisors gespeichert
                /*printf("%d ", divisors[index]);*/
                index++;
            }
        }
        /*printf("\n");*/
    }
    int *temp = realloc(divisors, (index + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Speicherzuweisung Fehler in find_key_length");
        free(divisors);
        exit(-1);
    }
    divisors = temp;
    divisors[index] = 0;

    const unsigned long int length = index;
    /*printf("length smallest Divisors is: %d\n", length);*/

    return find_largest_divisor_weighted(divisors, length);
}
