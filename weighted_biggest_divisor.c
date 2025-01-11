//
// Created by ben10 on 12/23/24.
//
#include <stdio.h>
#include <math.h>

int find_biggest_element(const double *number_of_elements)
{
    double biggest_element = 0;
    int index_element = -1;
    for (int i = 0; i <= 256; i++)
    {
        if (number_of_elements[i] > biggest_element)
        {
            biggest_element = number_of_elements[i];
            index_element = i;
        }
    }
    return index_element;
}
//zählt die Häufigkeit jedes Teilers und multipliziert ihn mit der Wurzel seines Index, um ein gewichtetes Ergebnis zu erhalten. Das heisst es wird das häufigste und größte Element, abhängig von einer bestimmten Gewichtung bestimmt.
int find_largest_divisor_weighted(const int *count_array, const unsigned long int length)
{
    //erstelle ein array, um die Häufigkeiten der Teiler zu zählen
    double number_of_elements[257];
    for (int i = 0; i <= 256; i++)
    {
        number_of_elements[i] = 0;
    }

    //zählen der Teiler
    for (int i = 0; i < length; i++)
    {
        if (count_array[i] <= 256)
        {
            number_of_elements[count_array[i]]++;
        }
    }

    /*for (int i = 0; i <= 256; i++)
    {
        printf("%d:%.0lf  ", i, number_of_elements[i]);
    }
    printf("\n");*/

    for (int i = 0; i <= 256; i++)
    {
        number_of_elements[i] = number_of_elements[i] * sqrt(i);
        /*printf("%d:%.0lf  ", i, number_of_elements[i]);*/
    }
    int max = find_biggest_element(number_of_elements);
    printf("\nmax is(key length): %d", max);

    return max;
}
