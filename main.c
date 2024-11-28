#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Encryption.h"
#include "VigenereEncryption.h"
#include "Häufigkeitsanalyse.h"
#include "Decryption.h"

#define MAX_DIVISOR 1000 // Maximale Größe für Divisoren-Zählung

// Funktion, um den größten gemeinsamen Teiler (GCD) zu berechnen
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    /*
        int shiftValue = 22;
        char text[] = "Mein bester Freund die Ente";
        CaeserChiffreEncryption(text, shiftValue);
        printf("Geheim Text:\n%s\n\n", text);

        int decryptedShiftValue = frequencyAnalysis(text);

        CaeserChiffreDecryption(text, decryptedShiftValue); */

    /*char VigenereText[] = "Es ist ein paradiesmatisches Land, in dem einem gebratene Satzteile in den Mund fliegen. Nicht einmal von der allmächtigen Interpunktion werden die Blindtexte beherrscht";
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

    printf("\ntemp Vigenere Text:%s", tempText);*/




char tempText[] = "fiqfiqiouoelothfiqttxoshseloijmaqejxdhhfddtelohrsnzvrgfghgelfrwguhsdlfshfiqjgxogxodijngftvjckiexueofigfrqjckumhirofbhodlhsrodhsndmszbpsfnwjeujngjevfrhjnpbllheqgldhgh";

    int length = strlen(tempText); // Länge des Strings berechnen
    int arr[100];                  // Array für Indizes von j
    int distances[100];            // Array für die Abstände
    int arrCount = 0;              // Zähler für gespeicherte Werte in arr

    // Schritt 1: Abstände berechnen
    for (int i = 0; i <= length - 3; i++) {
        for (int j = i + 3; j <= length - 3; j++) {
            if (tempText[i] == tempText[j] &&
                tempText[i + 1] == tempText[j + 1] &&
                tempText[i + 2] == tempText[j + 2]) {

                // Überprüfen, ob j schon im Array vorhanden ist
                int alreadyInArray = 0;
                for (int k = 0; k < arrCount; k++) {
                    if (arr[k] == j) {
                        alreadyInArray = 1;
                        break;
                    }
                }

                // Nur weiter verarbeiten, wenn j noch nicht im Array ist
                if (!alreadyInArray) {
                    distances[arrCount] = j - i;
                    arr[arrCount] = j;
                    arrCount++;
                }
            }
        }
    }

    // Schritt 2: Häufigkeiten der Teiler berechnen
    int divisorCount[MAX_DIVISOR] = {0}; // Array für Teiler-Häufigkeiten
    for (int i = 0; i < arrCount; i++) {
        for (int d = 2; d <= distances[i]; d++) {
            if (distances[i] % d == 0) {
                divisorCount[d]++;
            }
        }
    }

    // Schritt 3: Häufigsten Teiler finden
    int mostFrequentDivisor = 1;
    int highestFrequency = 0;
    for (int d = 1; d < MAX_DIVISOR; d++) {
        if (divisorCount[d] > highestFrequency) {
            mostFrequentDivisor = d;
            highestFrequency = divisorCount[d];
        }
    }

    // Ergebnis ausgeben
    printf("\nGespeicherte Abstände in distances[]: ");
    for (int k = 0; k < arrCount; k++) {
        printf("%d ", distances[k]);
    }

    printf("\nDer häufigste gemeinsame Teiler ist: %d (Häufigkeit: %d)\n", mostFrequentDivisor, highestFrequency);

    return 0;
}






/*
#define MAX_FOLGEN 100 // Maximale Anzahl an einzigartigen Dreierfolgen


        char tempText[] = "fiqfiqiouoelothfiqttxoshseloijmaqejxdhhfddtelohrsnzvrgfghgelfrwguhsdlfshfiqjgxogxodijngftvjckiexueofigfrqjckumhirofbhodlhsrodhsndmszbpsfnwjeujngjevfrhjnpbllheqgldhgh";

        int length = strlen(tempText); // Länge des Strings vorab berechnen
        char processed[MAX_FOLGEN][4]; // Array für bereits verarbeitete Dreierfolgen
        int processedCount = 0; // Zähler für einzigartige Dreierfolgen

        // Maximale Anzahl an möglichen Abständen
        const int maxOccurrences = 100;
        int distances[maxOccurrences]; // Array für Abstände
        int distancesCount = 0; // Zähler für die Abstände

        for (int i = 0; i <= length - 3; i++) { // Länge-3, um nicht über den Bereich zu gehen
            // Dreierfolge extrahieren
            char current[4] = { tempText[i], tempText[i + 1], tempText[i + 2], '\0' };

            // Prüfen, ob die Dreierfolge bereits verarbeitet wurde
            bool alreadyProcessed = false;
            for (int k = 0; k < processedCount; k++) {
                if (strcmp(processed[k], current) == 0) {
                    alreadyProcessed = true;
                    break;
                }
            }

            // Überspringen, wenn die Dreierfolge schon verarbeitet wurde
            if (alreadyProcessed) {
                continue;
            }

            // Neue Dreierfolge in die Liste der verarbeiteten Folgen hinzufügen
            strcpy(processed[processedCount++], current);

            // Abstände für die aktuelle Dreierfolge berechnen
            distancesCount = 0; // Zurücksetzen des Zählers für jede neue Dreierfolge
            for (int j = i + 3; j <= length - 3; j++) {
                if (tempText[i] == tempText[j] &&
                    tempText[i + 1] == tempText[j + 1] &&
                    tempText[i + 2] == tempText[j + 2]) {

                    // Abstand berechnen und speichern
                    distances[distancesCount++] = j - i;
                    }
            }

            // Nur ausgeben, wenn mindestens ein Abstand gefunden wurde
            if (distancesCount > 0) {
                printf("\nDreierfolge %s gefunden bei Index %d. Abstände: ",
                       current, i);

                for (int k = 0; k < distancesCount; k++) {
                    printf("%d ", distances[k]);
                }
            }
        }

        return 0;
    }
    */
