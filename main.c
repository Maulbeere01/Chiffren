#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Encryption.h"
#include "VigenereEncryption.h"
#include "Häufigkeitsanalyse.h"
#include "Decryption.h"

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

    char tempText[strlen(VigenereText)]; // | temp array anlegen, dass man modifizieren kann, um Schlüsselänge zu finden
    strcpy(tempText, VigenereText);     //  |

    strlwr(tempText);                                                                 //  | macht den text zu Kleinbuchstaben und löscht alle zeichen die nicht a bis z sind
                                                                                     //   | **Optimierung: nested loop eliminieren
    for (int i = 0; tempText[i] != 0; i++)                                          //    |
        {                                                                          //     |
        if(tempText[i] < 'a' || tempText[i] > 'z')                                //      |
            {                                                                    //       |
            for (int j = i; tempText[j] != 0; j++)                              //        |
            {                                                                  //         |
                tempText[j] = tempText[j + 1];                                //          |
            }                                                                //           |
            i--;                                                            //            |
        }                                                                  //             |
    }                                                                     //              |

    //printf("\ntemp Vigenere Text:%s", tempText);





    int length = strlen(tempText); // Länge des Strings berechnen
    int distances[length];            // Array für die Abstände, hier kann ich noch distances mit NULL initialisieren und fuer jeden gefunden Abstand mit realloc das array vergroessern um Speicherplatzverschwendung zu vermeiden


    for (int i = 0; i < length; i++) {
        distances[i] = 0;
    }
    // Schritt 1: Abstände berechnen. Manche Abstände werden doppelt gezählt
    for (int i = 0; i <= length - 3; i++) {
        for (int j = i + 3; j <= length - 3; j++) {
            if (tempText[i] == tempText[j] &&
                tempText[i + 1] == tempText[j + 1] &&
                tempText[i + 2] == tempText[j + 2]) {

                int k = 0;
                while(distances[k] != 0) {
                    k++;
                }
                distances[k] = j - i;
                printf("Abstand von %c%c%c (an Stelle %d) zur Wiederholung ist %d und an Index %d in distances gespeichert\n", tempText[i],tempText[i+1], tempText[i+2], i, distances[k], k);
                }
        }
    }
    // wir berechnen jeweils den kleinsten Teiler fuer jeden Abstand
    int smallestDivisors[100];

    for (int i = 0; i < 100; i++) {
        smallestDivisors[i] = 0;
    }

    printf("kleinste gemeinsame Teiler sind: ");
    for(int i = 0; distances[i] != 0; i++) {
        for(int j = 2; j < length; j++) {
            if(distances[i] % j == 0) {
                smallestDivisors[i] = j;
                printf("%d ", smallestDivisors[i]);
                break;
            }
        }
    }
    // wir berrechnen den kgT aller Teiler
    int kgT = -1;
    for(int i = 0; smallestDivisors[i] != 0; i++) {
        if(smallestDivisors[i] > kgT){
            kgT = smallestDivisors[i];
        }
    }
    printf("\nkgT aller Abstände ist %d", kgT);

    // Wir erstellen ein array welches wiederum strings enthält

    char **strings = malloc((kgT * sizeof(char *)));

    for (int i = 0; i < kgT; i++) {
        strings[i] = malloc(((length / kgT) + 2) * sizeof(char));
    }

    if (strings == NULL) {
        printf("speicherzuweisung fehlgeschlagen\n");
        return 1;
    }

    for (int i = 0; i < kgT; i++) {
        int j = 0;
        for (int k = i; k < length; k += kgT) { // i bestimmt den String in den geschrieben wird, j bestimmt den Platz des Characters im string,
            strings[i][j] = tempText[k];
            j++;
        }
        strings[i][j] = '\0';
    }
    for (int i = 0; i < kgT; i++) {
        printf("\n%s\n", strings[i]);
    }


    int *shiftValues = malloc((kgT * sizeof(int)));

    for (int i = 0; i < kgT; i++) {
        shiftValues[i] = frequencyAnalysis(strings[i]);
    }

    for (int i = 0; i < kgT; i++) {
        free(strings[i]);
    }
    free(strings);

    for (int i = 0; i < kgT; i++) {
       printf("%d ", shiftValues[i]);
    }



    free(shiftValues);
}






