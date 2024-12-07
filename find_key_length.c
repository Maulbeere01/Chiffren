//
// Created by benwe on 06.12.2024.
//


#include <stdio.h>
#include <stdlib.h>

int find_key_size(int *distances, const int length) {
    // wir berechnen jeweils den kleinsten Teiler fuer jeden Abstand LOGIKFEHLER: ich muss den kleinsten in allen vorkommenden Teiler finden, er muss nicht in allen vorkommenden sein, aber er sollte in den meisten vorkommen
    int *smallestDivisors = NULL;
    int index = 0;

    printf("kleinste gemeinsame Teiler sind: ");
    for(int i = 0; distances[i] != 0; i++) {
        for(int j = 2; j < length; j++) {
            if(distances[i] % j == 0 ) {
                smallestDivisors = realloc(smallestDivisors, (index + 1) * sizeof(int));
                smallestDivisors[index] = j;
                printf("%d ", smallestDivisors[index]);
                index++;
                break;
            }
        }
    }
    smallestDivisors = realloc(smallestDivisors, (index + 1) * sizeof(int));
    smallestDivisors[index] = 0;

    // wir berrechnen den kgT aller Teiler
    int kgT = -1;
    for(int i = 0; smallestDivisors[i] != 0; i++) {
        if(smallestDivisors[i] > kgT){
            kgT = smallestDivisors[i];
        }
    }
    printf("\nkgT aller Abstände ist %d", kgT);
    free(smallestDivisors);
    return kgT;
}
