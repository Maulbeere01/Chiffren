//
// Created by benwe on 14.01.2025.
//

#include "break_caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include "../frequency_analysis.h"
#include "../Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.h"
#include "user_interaction.h"

void break_cäsar()
{
    printf("Du hast Cäsar-Brechen gewählt.\nDer zu brechende Text wird aus caeser_chiffre_encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\nBereit?\n<press any button to continue>");
    scanf("%*c");

    char *cäsar_text = read_file_to_string("data/caeser_chiffre_encrypted.txt");

    printf("\nDer verschlüsselte Text ist\n\n%s", cäsar_text);

    const int decrypted_shift_value = frequency_analysis(cäsar_text);
    caeser_decryption_logic(cäsar_text, decrypted_shift_value);
    printf("\n\n\nDer entschlüsselte Text ist:\n\n%s\n\n", cäsar_text);
    printf("\nDie Buchstaben waren jeweils um %d Stelle(n) verschoben\n", decrypted_shift_value);

    printf("\nWillst du den Text in der caeser_chiffre_decrypted.txt Datei speichern?\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("data/caeser_chiffre_decrypted.txt", cäsar_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in caeser_chiffre_decrypted.txt gespeichert.\n");
    }
    free(cäsar_text);
}
