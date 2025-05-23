#include <stdio.h>
#include <stdlib.h>
#include "User-Interaction/encrypt_caeser.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include "User-Interaction/break_caesar.h"
#include "User-Interaction/decrypt_vigenere.h"
#include "User-Interaction/encrypt_vigenere.h"
#include "User-Interaction/break_vigenere.h"
#include "User-Interaction/user_interaction.h"
#include "User-Interaction/decrypt_caesar.h"


int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    while (1)
    {
        char input[256];
        int encryption_method = 0;
        int mode = 0;

        printf("Wähle zwischen [1] Cäsar- und [2] Vigenère-Chiffre:\n");
        fgets(input, 250, stdin);
        fflush(stdin);
        encryption_method = atoi(input);

        while (encryption_method != 1 && encryption_method != 2)
        {
            printf("Eingabefehler, wähle zwischen: [1] Cäsar- oder [2] Vigenère-Chiffre:\n");
            fgets(input, 250, stdin);
            fflush(stdin);
            encryption_method = atoi(input);
        }

        printf("Wähle zwischen [1] Verschlüsselung, [2] Entschlüsselung oder [3] Brechen:\n");
        fgets(input, 250, stdin);
        fflush(stdin);
        mode = atoi(input);

        while (mode != 1 && mode != 2 && mode != 3)
        {
            printf("Eingabefehler, wähle zwischen[1] Verschlüsselung, [2] Entschlüsselung oder [3] Brechen:\n");
            fgets(input, 250, stdin);
            fflush(stdin);
            mode = atoi(input);
        }

        if (encryption_method == 1)
        {
            if (mode == 1) encrypt_caesar();
            else if (mode == 2) decrypt_caesar();
            else if (mode == 3) break_cäsar();
        }

        if (encryption_method == 2)
        {
            if (mode == 1) encrypt_vigenere();
            else if (mode == 2) decrypt_vigenere();
            else if (mode == 3) break_vigenere();
        }
        printf(
            "\nWillst du weitermachen oder das Programm so beenden? \"Y\" für weitermachen und \"N\" für Programm beenden.\n");
        char user_choice = get_user_choice();
        if (user_choice == 'n') break;
    }
    return 0;
}
