#include <stdio.h>
#include <math.h>
// Wir bestimmen die Verteilung der Häufigkeit jedes Buchstabens im Geheimtext. Diese Verteilung vergleichen wir mit der Häufigkeitsverteilung der Buchstaben in der deutschen Sprache. Wir verschieben dafür unsere Häufigkeitsverteilung 26-mal und bestimmen, wo die Abweichung von der Standardverteilung der deutschen Sprache am geringsten ist
int frequencyAnalysis(const char *text)
{
    // Array um die Häufigkeit jedes Buchstaben zu zählen, index 0 steht für a, index 1 steht für b, etc.
    double letter_count[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        letter_count[i] = 0;
    }

    // Wir zahlen fur jeden Buchstaben die complementary Stelle im letter-count Array hoch
    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter_count[text[i] - 'a'] += 1;
        }

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter_count[text[i] - 'A'] += 1;
        }
    }

    // wir zählen wie viele Buchstaben in letter_count gezählt wurden
    double size_letter_count = 0;
    for (int i = 0; i < 26; i++)
    {
        size_letter_count += letter_count[i];
    }

    // wir berechnen den prozentualen Anteil jedes Buchstabens in letter_count und speichern den Wert am gleichen Index in letter_count
    for (int i = 0; i < 26; i++)
    {
        letter_count[i] = letter_count[i] / size_letter_count;
    }
    // Die Häufigkeit jedes Buchstabens der deutschen Sprache:
    const double probability_distribution_german[26] = {
        0.0651, 0.0189, 0.0306, 0.0508, 0.1740, 0.0166, 0.0301, 0.0476, 0.0755, 0.0027, 0.0121, 0.0344, 0.0253, 0.0978,
        0.0251, 0.0079, 0.0002, 0.0700, 0.0727, 0.0615, 0.0435, 0.0067, 0.0189, 0.0003, 0.0004, 0.0113
    };

    // In diesem Array speichern wir die Differenz der Häufigkeit jedes Buchstabens in letter_count zu der Häufigkeit jedes Buchstabens der deutschen Sprache
    double shift_probability[26];
    for (int i = 0; i < 26; i++)
    {
        shift_probability[i] = 0;
    }

    // wir verschieben unsere Verteilung in letter_count 25-mal um 1 und schauen bei welcher Verschiebung die Verteilung am ähnlichsten mit der deutschen Sprache ist
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            // fabs() ist aus math.h und gibt den absoluten Differenzwert zurück, da wir ja keine negativen Werte wollen
            shift_probability[i] += fabs(letter_count[(j + i) % 26] - probability_distribution_german[j]);
        }
        /*printf("%d: %lf\n",i, shift_probability[i]);*/
    }

    // geringste Abweichung finden:
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
    /*printf("index smallest difference: %d\n", index_smallest);*/

    /*printf("\nshift value: %d", index_smallest);*/

    return index_smallest;

    /*
    //
    int highest = 0;
    int index = 0;
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

    // bestimmt aus dem häufigst vorkommenden Buchstaben den Verschiebe Wert, mithilfe des in der deutschen Sprache am häufigst genutzten Buchstaben 'e'.
    int decryptedShiftValue = (index - ('e' - 'a') + 26) % 26;
    // // +26, da für häufigster buchstaben a bis d für -(e - a(4)) negative Werte herauskommen; -4 + 26 = Verschiebung um 22. Und mod 26, da Werte größer null dann z.b. 3 + 26 = 29 mod 26 = 3 wieder werden.

    //printf("Die Buchstaben wurden um %d verschoben.\n\n", decryptedShiftValue);

    return decryptedShiftValue;*/
}
