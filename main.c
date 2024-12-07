#include <stdio.h>
#include <string.h>
#include "Encryption.h"
#include "VigenereEncryption.h"
#include "Häufigkeitsanalyse.h"
#include "Decryption.h"
#include "Kasiski_Test.h"

// fuer linux:  git config --global core.autocrlf input

int main() {
    /*
        int shiftValue = 22;
        char text[] = "Mein bester Freund die Ente";
        CaeserChiffreEncryption(text, shiftValue);
        printf("Geheim Text:\n%s\n\n", text);

        int decryptedShiftValue = frequencyAnalysis(text);

        CaeserChiffreDecryption(text, decryptedShiftValue); */

    char VigenereText[] = "Es ist ein paradiesmatisches Land, in dem einem gebratene Satzteile in den Mund fliegen. Nicht einmal von der allmächtigen Interpunktion werden die Blindtexte beherrscht";
    char secretKey[] = "Berta";
   
    VigenereEncryption(VigenereText, secretKey);

    kasiski_test(VigenereText);

}






