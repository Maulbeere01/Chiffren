#include <stdio.h>
#include <string.h>
#include "Encryption.h"
#include "VigenereEncryption.h"
#include "Häufigkeitsanalyse.h"
#include "Ceaser-Chiffre/Ceaser_Decryption.h"
#include "Kasiski_Test.h"

// fuer linux:  git config --global core.autocrlf input

int main()
{
    /*
        int shiftValue = 22;
        char text[] = "Mein bester Freund die Ente";
        CaeserChiffreEncryption(text, shiftValue);
        printf("Geheim Text:\n%s\n\n", text);

        int decryptedShiftValue = frequencyAnalysis(text);

        CaeserChiffreDecryption(text, decryptedShiftValue); */

    char VigenereText[] =
            "das leben ist ein unaufhörliches spiel von licht und schatten, ein ständig wechselndes panorama von eindrücken, emotionen und gedanken, das uns in seinem strom mitreißt und niemals stillsteht, während wir versuchen, ihm einen sinn abzugewinnen. jeder tag birgt neue herausforderungen, jeder moment verlangt entscheidungen, und doch ist es diese ständige bewegung, die uns antreibt, die uns dazu bringt, immer weiter nach vorne zu blicken, selbst wenn die zukunft ungewiss ist und die vergangenheit schwer auf uns lasten kann. die natur zeigt uns dabei ihre eigene art der fortwährenden erneuerung, sei es im flüstern des windes durch die blätter, im sanften plätschern eines baches oder in der kraft eines gewitters, das den himmel teilt und die erde erzittern lässt, um schließlich in einem beruhigenden regen zu münden. menschen suchen in diesem chaos oft nach halt, nach ritualen und strukturen, die ihnen das gefühl geben, dass ihr dasein nicht völlig im freien fall ist, dass es ein system gibt, eine ordnung, die über das hinausgeht, was sie direkt sehen und fühlen können, doch dieser glauben wird immer wieder herausgefordert von ereignissen, die sich unserer kontrolle entziehen. es ist dieses ständige hin und her zwischen dem wünschen und dem akzeptieren, dem kämpfen und dem loslassen, das uns zu dem macht, was wir sind: wesen, die ständig nach bedeutung streben, auch wenn wir wissen, dass diese bedeutung niemals vollständig greifbar sein wird. in dieser suche nach sinn liegt eine gewisse schönheit, eine art zu sagen, dass wir trotz aller widrigkeiten bereit sind, weiterzumachen, neue wege zu gehen, unbekanntes zu erkunden und vielleicht sogar ein wenig frieden in der unbeständigkeit zu finden, die das leben ausmacht.";
    // waehle einen schluessel laenger als 2
    char secretKey[] = "linuxe";

    VigenereEncryption(VigenereText, secretKey);
    /*
    printf("\n%s\n", VigenereText);
    */
    kasiski_test(VigenereText);
}
