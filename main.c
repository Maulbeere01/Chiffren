#include <stdio.h>
#include <string.h>
#include "Ceaser-Chiffre/encryption_ceaser.h"
#include "Vignere-Chiffre/Encryption/encryption.h"
#include "frequency_analysis.h"
#include "Ceaser-Chiffre/ceaser_decryption.h"
#include "kasiski_test.h"
#include <math.h>
#include "check_if_cracked.h"
#include "brute_force.h"
#include "string_operations.h"

// fuer linux:  git config --global core.autocrlf input

int main()
{
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
    char vigenere_text[] =
            "das leben ist ein unaufhörliches spiel von licht und schatten, ein ständig wechselndes panorama von eindrücken, emotionen und gedanken, das uns in seinem strom mitreißt und niemals stillsteht, während wir versuchen, ihm einen sinn abzugewinnen.jeder tag birgt neue herausforderungen, jeder moment verlangt entscheidungen, und doch ist es diese ständige bewegung, die uns antreibt, die uns dazu bringt, immer weiter nach vorne zu blicken, selbst wenn die zukunft ungewiss ist und die vergangenheit schwer auf uns lasten kann. die natur zeigt uns dabei ihre eigene art der fortwährenden erneuerung, sei es im flüstern des windes durch die blätter, im sanften plätschern eines baches oder in der kraft eines gewitters, das den himmel teilt und die erde erzittern lässt, um schließlich in einem beruhigenden regen zu münden. menschen suchen in diesem chaos oft nach halt, nach ritualen und strukturen, die ihnen das gefühl geben, dass ihr dasein nicht völlig im freien fall ist, dass es ein system gibt, eine ordnung, die über das hinausgeht, was sie direkt sehen und fühlen können, doch dieser glauben wird immer wieder herausgefordert von ereignissen, die sich unserer kontrolle entziehen. es ist dieses ständige hin und her zwischen dem wünschen und dem akzeptieren, dem kämpfen und dem loslassen, das uns zu dem macht, was wir sind: wesen, die ständig nach bedeutung streben, auch wenn wir wissen, dass diese bedeutung niemals vollständig greifbar sein wird. in dieser suche nach sinn liegt eine gewisse schönheit, eine art zu sagen, dass wir trotz aller widrigkeiten bereit sind, weiterzumachen, neue wege zu gehen, unbekanntes zu erkunden und vielleicht sogar ein wenig frieden in der unbeständigkeit zu finden, die das leben ausmacht.";

    char secretKey[] = "abcdefghijklmnopqra";

    VigenereEncryption(vigenere_text, secretKey);

    printf("Der verschluesselte Text ist:\n%s\n", vigenere_text);

    // Erstellen einer Kopie des Original Textes
    unsigned long long int len_org_text = strlen(vigenere_text) + 1;
    char original_backup[len_org_text];
    strcpy(original_backup, vigenere_text);

    // letters only enthaelt nur die Buchstaben des verschluesselten Textes
    char letters_only[len_org_text]; // diese Kopie des Textes wird manipuliert um den Schlüssel herauszufinden
    strcpy(letters_only, vigenere_text);
    str_lower(letters_only);
    extract_letters(letters_only);
    //printf("\nText aus nur kleinen Buchstaben: %s\n", text);

    const unsigned long int len_letters_only = strlen(letters_only) + 1;
    /*printf("\nlength of cleaned text is %ld\n", length);*/

    kasiski_test(vigenere_text, letters_only, len_letters_only);

    float german_similarity = -1;
    german_similarity = check_if_cracked(vigenere_text);
    printf("german_similarity: %.2f\n", german_similarity);

    //printf("\nDer entschlüsselte Text besteht zu %.2f Prozent aus den 1000 häufigst genutzten Wörter der deutschen Sprache \n", german_similarity);
    if (german_similarity < 25)
    {
        printf("Kassiski-Test fehlgeschlagen \nBrute-Force-Methode folgt\n");
        german_similarity = brute_force(original_backup, german_similarity, len_org_text, letters_only,
                                        len_letters_only);

        if (german_similarity == -1)
        {
            printf("\n\nCodebrechen ist fehlgeschlagen\n");
        }

        if (german_similarity >= 25)
        {
            printf("Der entschluesselte Text ist:\n%s\n", original_backup);
        }

        if (german_similarity < 25 && german_similarity != -1)
        {
            printf("\nCodebrechen war nicht erfolgreich\n");
        }
    }
    else
    {
        printf("Der entschluesselte Text ist:\n%s\n", vigenere_text);
    }
}
