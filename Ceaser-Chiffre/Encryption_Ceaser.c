// Nimmt einen Text und verschlüsselt ihn, indem jeder Buchstabe um den shiftValue verschoben wird. Bei shiftValue = 1 wird a zu b, und z zu a. Genauso wie A zu B wird

void CaeserChiffreEncryption(char *text, int shiftValue)
{

    for (int i = 0; text[i] != '\0'; i++)                                         //Wir interieren durch den Text Buchstabe für Buchstabe
    {
        if (text[i] >= 'a' && text[i] <= 'z')                                     //Für die Buchstaben a bis z machen wir:
        {
            text[i] = (text[i] - 'a' + shiftValue) % 26 + 'a';                    // 'e' ACSII 101 minus 'a' ASCII 97 = 4 + shiftValue von 1 = 5 mod 26 = 5 + 'a' = 'f'ASCII 102
        }                                                                        // das mod ist für große Werte von 'z' ASCII 122 minus 'a' = 25 + shiftValue = 26 mod 26 = 0 + 'a' wird zu 'a' ASCII 97, somit wird z zu a umgewandelt ohne mod 26 würden wir bei { rauskommen ASCII 123, regelt auch bei größeren shiftValues, dass wir in der Range von a bis z bleiben

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + shiftValue) % 26 + 'A';                    // das gleiche nur für Großbuchstaben
        }
    }
}




    /*
    char userChoice;
    printf("Wollen sie einen eigenen Wert zum Verschlüsseln wählen [Y], oder soll mit einem zufälligem Wert verschlüsselt werden [N]?\n");

    do {
        scanf(" %c", &userChoice);
        userChoice = toupper(userChoice);
        if (userChoice != 'Y' && userChoice != 'N') {
            printf("Wähle einen gültigen Wert [Y] für eigenen Wert oder [N] um mit einem zufälligen Wert zu verschlüsseln:\n");
        }
    } while (userChoice != 'Y' && userChoice != 'N');

    if (userChoice == 'Y') {
        printf("Geben Sie einen Wert von 1 bis 25 ein, um wie viele Stellen die Buchstaben verschoben werden sollen:\n");
        do {
            scanf("%d", &shiftValue);
            if (shiftValue < 1 || shiftValue > 25) {
                printf("Wähle einen gültigen Wert von 1 bis 25:\n");
            }
        } while (shiftValue < 1 || shiftValue > 25);
    } else if (userChoice == 'N') {
        srand(time(0));
        shiftValue = (rand() % 25) + 1;
    }

    printf("Gewählter Verschiebewert: %d\n", shiftValue);
    */


