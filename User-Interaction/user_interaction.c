//
// Created by benwe on 15.01.2025.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../string_operations.h"

char *read_file_to_string(const char *filename)
{
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
        printf("Fehler beim öffnen von %s", filename);
        exit(-1);
    }
    char *string = malloc(50000 * sizeof(char));
    if (string == NULL)
    {
        printf("Fehler bei der Speicherzuweisung in user_interaction->read_file_to_string");
        exit(-1);
    }
    string[0] = '\0';
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), input_file) != NULL)
    {
        strcat(string, buffer); //
    }

    fclose(input_file);
    return string;
}

char get_user_choice()
{
    char user_choice = 'x';
    while (user_choice != 'y' && user_choice != 'n')
    {
        printf("Nutze \"Y\" für Ja oder \"N\" für Nein\n[Y/N]: ");
        scanf("%1c", &user_choice);
        fflush(stdin);
        user_choice = (char) tolower(user_choice);
    }
    return user_choice;
}

void write_string_to_file(const char *filename, char *string)
{
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL)
    {
        printf("Fehler beim öffnen von %s", filename);
        exit(-1);
    }
    fprintf(output_file, "%s", string);
    printf("Der verschlüsselte Text wurde in %s gespeichert.", filename);
    fclose(output_file);
}

int get_valid_shift_value()
{
    char input[256];
    fgets(input, 250, stdin);
    fflush(stdin);

    int shift_value = atoi(input);
    while (shift_value <= 0 || shift_value > 25)
    {
        printf("Ungültige Eingabe, wähle eine Zahl von 1 bis 25:\n");
        fgets(input, 250, stdin);
        fflush(stdin);
        shift_value = atoi(input);
    }
    return shift_value;
}

int is_key_valid(const char *key)
{
    if (key == NULL)return -1;
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (key[i] < 'a' || key[i] > 'z')
        {
            return -1;
        }
    }
    return 1;
}

char *get_secret_word()
{
    char *key = malloc(256 * sizeof(char));
    while (1)
    {
        printf("Es sind nur Buchstaben von a-z erlaubt, keine Sonderzeichen, etc.\n");
        fgets(key, 256, stdin);
        fflush(stdin);
        str_lower(key);
        unsigned long long int len_key = strlen(key);
        if (len_key > 0 && key[len_key - 1] == '\n')
        {
            key[len_key - 1] = '\0';
        }
        if (is_key_valid(key) == 1)break;
    }
    return key;
}
