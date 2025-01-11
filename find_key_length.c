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


    /*printf("max in smallestDivisors is: %d", max);*/

    /*int count_array[max];
    for (int i = 0; i < max; i++)
    {
        count_array[i] = 0;
    }

    for (int i = 0; smallestDivisors[i] != 0; i++)
    {
        count_array[smallestDivisors[i]]++;
    }

    int key_length = find_biggest_most_common_element(count_array, max);

    printf("\nkey length is %d\n", key_length);

    return key_length;*/
}

/*int find_biggest_most_common_element(const int *count_array, int length)
{
    int biggest_element = 0;
    int index_element = -1;
    // i > 2 würde die Schlüssellänge 2 ignoriert werden, der Text würde trotzdem korrekt entschlüsselt werden(da Schlüssel dann einfach zb bebe wäre), aber der ausgegebene Schlüssel wäre falsch
    for (int i = length - 1; i > 1; i--)
    {
        if (count_array[i] > biggest_element)
        {
            biggest_element = count_array[i];
            index_element = i;
        }
    }
    return index_element;
}*/


/*int find_max(const int *arr)
{
    int max = 0;
    for (int i = 0; arr[i] != 0; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}*/
