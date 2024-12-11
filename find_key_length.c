//
// Created by benwe on 06.12.2024.
//


#include <stdio.h>
#include <stdlib.h>

int find_biggest_most_common_element(int *count_array, int length)
{
    int biggest_element = 0;
    int index_element = -1;
    for (int i = length - 1; i > 2; i--)
    {
        if (count_array[i] > biggest_element)
        {
            biggest_element = count_array[i];
            index_element = i;
        }
    }
    return index_element;
}


int find_max(int *arr)
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
}

int find_key_size(int *distances, const int length)
{
    // wir berechnen jeweils den kleinsten Teiler fuer jeden Abstand LOGIKFEHLER: ich muss den groessten in allen vorkommenden Teiler finden, er muss nicht in allen vorkommenden sein, aber er sollte in den meisten vorkommen
    int *smallestDivisors = NULL;
    int index = 0;

    /*printf("\nTeiler der Abstaende sind:\n ");*/
    for (int i = 0; distances[i] != 0; i++)
    {
        for (int j = 2; j < distances[i]; j++)
        {
            if (distances[i] % j == 0)
            {
                smallestDivisors = realloc(smallestDivisors, (index + 1) * sizeof(int));
                smallestDivisors[index] = j;
                /*printf("%d ", smallestDivisors[index]);*/
                index++; // hier den
            }
        }
    }
    smallestDivisors = realloc(smallestDivisors, (index + 1) * sizeof(int));
    smallestDivisors[index] = 0;


    // wir berrechnen den groessten, am hauefigst vorkommenden Teiler.
    // Wir erstellen ein array von so vielen Plaetzen die wir braucen und zaehelen am passenden Index hoch wenn das element in den Teiler der Abstaende vorkommt.
    // dann iterieren wir rueckwaerts durchs array und bestimmmen mit if( >= ) den am hauefigst vorkommenden groessten Teiler, bei Schluessellaenge 4 sollte die 4 so ueber der 2 ausgewaehlt werden.
    // trotzdem kann failen, da ein Abstand nicht durch Schluessellaenge teilbar aber durch 2 ==> 2 gibt es mehr als 4

    int max = find_max(smallestDivisors);
    /*printf("max in smallestDivisors is: %d", max);*/

    int count_array[max];
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

    return key_length;


    /*int kgT = -1;
    for(int i = 0; smallestDivisors[i] != 0; i++) {
        if(smallestDivisors[i] > kgT){
            kgT = smallestDivisors[i];
        }
    }
    printf("\n\nkgT aller Abstände ist %d\n", kgT);
    free(smallestDivisors);
    return kgT;*/
}
