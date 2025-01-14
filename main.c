#include <stdio.h>
#include <string.h>
#include "Ceaser-Chiffre/encryption_ceaser.h"
#include "Vignere-Chiffre/Encryption/encryption.h"
#include "frequency_analysis.h"
#include "Ceaser-Chiffre/ceaser_decryption.h"
#include "kasiski_test.h"
#include <math.h>
#include <stdlib.h>

#include "brute_force.h"
#include "string_operations.h"
#include "get_word_match_percentage.h"





int main()
{
    /*char input[25];
    int decision = 0;

    printf("Wähle zwischen Ceaser[1]- und Vigenère-Chiffre[2]:");
    fgets(input, 25, stdin);

    while(decision != 1 && decision !=2)
    {
        printf("Eingabefehler, wähle zwischen 1 oder 2 für Ceaser[1]- oder Vigenère-Chiffre[2]:");
        fgets(input, 25, stdin);
        decision = atoi(input);
    }

    char input2[25];
    int decision2 = 0;

    printf("Wähle zwischen Verschlüsselung, Entschlüsselung oder Brechen");
    fgets(input, 25, stdin);

    while(decision != 1 && decision !=2)
    {
        printf("Eingabefehler, wähle zwischen 1 oder 2 für Ceaser[1]- oder Vigenère-Chiffre[2]:");
        fgets(input, 25, stdin);
        decision = atoi(input);
    }*/

    /*
    int shift_value = 2;
    char text[] = "das leben ist ein unaufhörliches spiel von licht und schatten, ein ständig wechselndes panorama von eindrücken, emotionen und gedanken";
    caeser_chiffre_encryption(text, shift_value);
    printf("Geheim Text:\n%s\n", text);

    int decrypted_shift_value = frequencyAnalysis(text);

    caeser_chiffre_decryption(text, decrypted_shift_value);
    printf("\nentschlüsselter Text:\n%s\n", text);
    */



    //  jeder tag birgt neue herausforderungen, jeder moment verlangt entscheidungen, und doch ist es diese ständige bewegung, die uns antreibt, die uns dazu bringt, immer weiter nach vorne zu blicken, selbst wenn die zukunft ungewiss ist und die vergangenheit schwer auf uns lasten kann. die natur zeigt uns dabei ihre eigene art der fortwährenden erneuerung, sei es im flüstern des windes durch die blätter, im sanften plätschern eines baches oder in der kraft eines gewitters, das den himmel teilt und die erde erzittern lässt, um schließlich in einem beruhigenden regen zu münden. menschen suchen in diesem chaos oft nach halt, nach ritualen und strukturen, die ihnen das gefühl geben, dass ihr dasein nicht völlig im freien fall ist, dass es ein system gibt, eine ordnung, die über das hinausgeht, was sie direkt sehen und fühlen können, doch dieser glauben wird immer wieder herausgefordert von ereignissen, die sich unserer kontrolle entziehen. es ist dieses ständige hin und her zwischen dem wünschen und dem akzeptieren, dem kämpfen und dem loslassen, das uns zu dem macht, was wir sind: wesen, die ständig nach bedeutung streben, auch wenn wir wissen, dass diese bedeutung niemals vollständig greifbar sein wird. in dieser suche nach sinn liegt eine gewisse schönheit, eine art zu sagen, dass wir trotz aller widrigkeiten bereit sind, weiterzumachen, neue wege zu gehen, unbekanntes zu erkunden und vielleicht sogar ein wenig frieden in der unbeständigkeit zu finden, die das leben ausmacht.
    char input_text[] =
            "das leben ist ein unaufhörliches spiel von licht und schatten, ein ständig wechselndes panorama von eindrücken, emotionen und gedanken, das uns in seinem strom mitreißt und niemals stillsteht, während wir versuchen, ihm einen sinn abzugewinnen.jeder tag birgt neue herausforderungen, jeder moment verlangt entscheidungen, und doch ist es diese ständige bewegung, die uns antreibt, die uns dazu bringt, immer weiter nach vorne zu blicken, selbst wenn die zukunft ungewiss ist und die vergangenheit schwer auf uns lasten kann. die natur zeigt uns dabei ihre eigene art der fortwährenden erneuerung, sei es im flüstern des windes durch die blätter, im sanften plätschern eines baches oder in der kraft eines gewitters, das den himmel teilt und die erde erzittern lässt, um schließlich in einem beruhigenden regen zu münden. menschen suchen in diesem chaos oft nach halt, nach ritualen und strukturen, die ihnen das gefühl geben, dass ihr dasein nicht völlig im freien fall ist, dass es ein system gibt, eine ordnung, die über das hinausgeht, was sie direkt sehen und fühlen können, doch dieser glauben wird immer wieder herausgefordert von ereignissen, die sich unserer kontrolle entziehen. es ist dieses ständige hin und her zwischen dem wünschen und dem akzeptieren, dem kämpfen und dem loslassen, das uns zu dem macht, was wir sind: wesen, die ständig nach bedeutung streben, auch wenn wir wissen, dass diese bedeutung niemals vollständig greifbar sein wird. in dieser suche nach sinn liegt eine gewisse schönheit, eine art zu sagen, dass wir trotz aller widrigkeiten bereit sind, weiterzumachen, neue wege zu gehen, unbekanntes zu erkunden und vielleicht sogar ein wenig frieden in der unbeständigkeit zu finden, die das leben ausmacht.";

    char secretKey[] = "abcdefghijklmnasldkfmsdlkflsadjflshdl";

    VigenereEncryption(input_text, secretKey);

    printf("Der verschlüsselte Text ist:\n%s\n", input_text);

    // Erstellen einer Kopie des Original Textes
    unsigned long long int len_org_text = strlen(input_text) + 1;
    char original_backup[len_org_text];
    strcpy(original_backup, input_text);

    // letters only enthält nur die Buchstaben des verschlüsselten Textes
    char letters_only[len_org_text]; // diese Kopie des Textes wird manipuliert um den Schlüssel herauszufinden
    strcpy(letters_only, input_text);
    str_lower(letters_only);
    extract_letters(letters_only);
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int len_letters_only = strlen(letters_only) + 1;
    /*
    printf("\nlength of cleaned text is %ld\n", len_letters_only);
    */

    kasiski_test(input_text, letters_only, len_letters_only);

    float german_similarity = get_word_match_percentage(input_text);
    printf("german_similarity: %.2f\n", german_similarity);

    //printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);
    if (german_similarity < 25)
    {
        printf("Kasiski-Test fehlgeschlagen \n"
               "Brute-Force-Methode folgt\n");
        german_similarity = brute_force(original_backup, german_similarity, len_org_text, letters_only, len_letters_only);

        if (german_similarity == -1)
        {
            printf("\n\nCodebrechen ist fehlgeschlagen\n");
        }

        if (german_similarity >= 25)
        {
            printf("Der entschlüsselte Text ist:\n%s\n", original_backup);
        }

        if (german_similarity < 25 && german_similarity != -1)
        {
            printf("\nKein passenden Schlüssel gefunden, Codebrechen war nicht erfolgreich\n"
                   "Der Schlüssel im Verhältnis zur Text Länge ist zu hoch um den Text mit Häufigkeitsanalyse zu brechen\n");
        }
    }
    else
    {
        printf("Der entschlüsselte Text ist:\n%s\n", input_text);
    }
}
