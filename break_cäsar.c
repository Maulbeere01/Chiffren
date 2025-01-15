//
// Created by benwe on 14.01.2025.
//

#include "break_cäsar.h"
#include <stdio.h>
#include <stdlib.h>
#include "frequency_analysis.h"
#include "Ceaser-Chiffre/c_decryption.h"
#include "user_interaction.h"

void break_cäsar()
{
    printf("Du hast Cäsar-Brechen gewählt.\nDer zu brechende Text wird aus encrypted.txt gelesen. Lege dort deinen Text ab oder nutze den schon vorhandenen Text.\nBereit?\n<press any button to continue>");
    scanf("%*c");

    char *cäsar_text = read_file_to_string("encrypted.txt");
    printf("Der verschlüsselte Text ist\n%s\n", cäsar_text);

    const int decrypted_shift_value = frequencyAnalysis(cäsar_text);
    c_decryption(cäsar_text, decrypted_shift_value);
    printf("\nDer entschlüsselte Text ist:\n%s\n", cäsar_text);

    printf("\nWillst du den Text in der decrypted.txt Datei speichern? [Y/N]\n");
    const char user_choice = get_user_choice();

    if (user_choice == 'y')
    {
        write_string_to_file("decrypted.txt", cäsar_text);
    }
    else
    {
        printf("Der verschlüsselte Text wurde NICHT in decrypted.txt gespeichert.\n");
    }
    free(cäsar_text);
}
