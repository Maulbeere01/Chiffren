#include <stdio.h>
#include <math.h>
// Häufigkeitsanalyse: erstellt ein array mit 26 Elementen. Für jeden Buchstaben im Geheimtext wird am passenden Index im array um eins erhöht, um am Ende die Anzahl jedes einzelnen Buchstaben im Geheimtext zu haben. Also an Stelle 0 wird für a gezählt, an Stelle 1 für b, etc.  int letterCount[26] = { 'a' : 3, 'b' : 2, ...}
int frequencyAnalysis(char *text)
{
    //Array um die Häufigkeit jedes Buchstaben zu zählen, index 0 steht für a, index 1 steht für b, etc.
    double letterCount[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        letterCount[i] = 0;
    }

    int highest = 0;
    int index = 0;

    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letterCount[text[i] - 'a'] += 1;
        }

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letterCount[text[i] - 'A'] += 1;
        }
    }

    // wir zählen wie viele Buchstaben in letterCount gezählt wurden
    double size_letter_count = 0;
    for (int i = 0; i < 26; i++)
    {
        size_letter_count += letterCount[i];
    }

    // wir berechnen den prozentualen Anteil jedes Buchstabens in lettercount und speichern den Wert am gleichen Index in lettercount
    for (int i = 0; i < 26; i++)
    {
        letterCount[i] = letterCount[i] / size_letter_count;
    }

    double probability_distribution_german[26] = {
        0.0651, 0.0189, 0.0306, 0.0508, 0.1740, 0.0166, 0.0301, 0.0476, 0.0755, 0.0027, 0.0121, 0.0344, 0.0253, 0.0978,
        0.0251, 0.0079, 0.0002, 0.0700, 0.0727, 0.0615, 0.0435, 0.0067, 0.0189, 0.0003, 0.0004, 0.0113
    };

    double shift_probability[26];
    for (int i = 0; i < 26; i++)
    {
        shift_probability[i] = 0;
    }

    //die differenz von jedem Buchstaben zur Wahrscheinlichkeitsverteilung im deutschen berechnen, diese alle addieren und dann ist der Index des niedrigsten Wert der Verschiebewert
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            shift_probability[i] += fabs(letterCount[(j + i) % 26] - probability_distribution_german[j]);
        }
        /*printf("%d: %lf\n",i, shift_probability[i]);*/
    }

    double smallest_element = 9999999;
    int index_smallest = -1;
    for (int i = 0; i < 26; i++)
    {
        if (shift_probability[i] < smallest_element)
        {
            smallest_element = shift_probability[i];
            index_smallest = i;
        }
    }
    /*printf("index smallest difference: %d", index_smallest);*/


    /*printf("\nshift value: %d", index_smallest);*/

    return index_smallest;

    /*
    // Findet den am häufigsten vorkommenden Buchstaben und speichert den Index (Index 0 = häufigster Buchstabe ist a, Index 1 = häufigster Buchstabe ist b, etc.)
    for (int i = 0; i < 26; i++)
    {
        if (letterCount[i] > highest)
        {
            highest = letterCount[i];
            index = i;
        }
    }

    //printf("Der meist auftauchende Buchstabe im geheim Text ist: %c\n", index + 'a');

    // bestimmt aus dem häufigst vorkommenden Buchstaben den Verschiebewert, mithilfe des in der deutschen Sprache am häufigst genutzten Buchstaben 'e'.
    int decryptedShiftValue = (index - ('e' - 'a') + 26) % 26;
    // // +26, da für häufigster buchstaben a bis d für -(e - a(4)) negative Werte rauskommen; -4 + 26 = Verschiebung um 22. Und mod 26, da Werte größer null dann z.b 3 + 26 = 29 mod 26 = 3 wieder werden.

    //printf("Die Buchstaben wurden um %d verschoben.\n\n", decryptedShiftValue);

    return decryptedShiftValue;*/
}
