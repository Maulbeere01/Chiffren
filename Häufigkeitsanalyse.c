#include <stdio.h>
// Häufigkeitsanalyse: erstellt ein array mit 26 Elementen. Für jeden Buchstaben im Geheimtext wird am passenden Index im array um eins erhöht, um am Ende die Anzahl jedes einzelnen Buchstaben im Geheimtext zu haben. Also an Stelle 0 wird für a gezählt, an Stelle 1 für b, etc.  int letterCount[26] = { 'a' : 3, 'b' : 2, ...}
int frequencyAnalysis(char *text)
{

    int letterCount[26] = {0};                                                    //Array um die Häufigkeit jedes Buchstaben zu zählen, index 0 steht für a, index 1 steht für b, etc.
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
    int decryptedShiftValue = (index - ('e' - 'a') + 26) % 26; // // +26, da für häufigster buchstaben a bis d für -(e - a(4)) negative Werte rauskommen; -4 + 26 = Verschiebung um 22. Und mod 26, da Werte größer null dann z.b 3 + 26 = 29 mod 26 = 3 wieder werden.

    //printf("Die Buchstaben wurden um %d verschoben.\n\n", decryptedShiftValue);

    return decryptedShiftValue;
}