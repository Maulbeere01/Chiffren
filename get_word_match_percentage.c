//
// Created by benwe on 10.01.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 49999
// 0 für hash table existiert nicht und muss erstellt werden und 1 für hash table schon erstellt, ansonsten wird bei der Brute-Force-Methode für jede Schlüssellänge die gleiche hashtable neu erstellt werden.
int is_hash_table_created = 0;

typedef struct node {
    char *word;
    struct node *next;
} node;

node *hash_table[SIZE];

unsigned int hash_function(const char *word)
{
    unsigned int index = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = (index * 53) + word[i];
        // durch Ausprobieren hat die Primzahl 53 in diesem Beispiel die besten Ergebnisse gebracht (Kollisionsarm und geringste maximale Länge eines buckets)
    }
    return index % SIZE;
}

void add_node(const char *word)
{
    const unsigned int index = hash_function(word);
    node *current_node = hash_table[index];

    while (current_node != NULL) // wenn schon belegt dann:
    {
        current_node = current_node->next; // Liste abarbeiten bis ein Platz frei ist
    }
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Fehler Speicherzuweisung in hash_map_check_if_cracked");
        exit(-1);
    }

    new_node->word = malloc(strlen(word) + 1);
    if (new_node->word == NULL)
    {
        printf("Fehler Speicherzuweisung in hash_map_check_if_cracked");
        exit(-1);
    }
    strcpy(new_node->word, word);
    new_node->next = hash_table[index];
    // Ist der Index leer, zeigt next jetzt auf NULL, ist schon ein Element im bucket, dann zeigt next jetzt auf dieses
    hash_table[index] = new_node;
    // am index steht jetzt der neue Knoten und der next Zeiger zeigt auf NULL oder das nächste Element (was der vorherige Knoten an dem Index war), wir haben am Index der Kollision eine Liste erstellt
}

void create_hash_table()
{
    for (int i = 0; i < SIZE; i++)
    {
        hash_table[i] = NULL;
    }

    FILE *file = fopen("words.txt", "r");

    if (file == NULL)
    {
        printf("Wörterbuch konnte nicht geöffnet werden");
        exit(-1);
    }

    char word[30];

    while (fscanf(file, "%30s", word) != EOF)
    {
        add_node(word);
    }
    is_hash_table_created = 1;
    /*print_hash_table();*/
}

void print_hash_table()
{
    int max_length = 0;
    int collisions = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int length_node = 0;
        node *current = hash_table[i];
        while (current != NULL)
        {
            length_node++;
            current = current->next;
        }

        if (length_node > 1)
        {
            collisions += (length_node - 1); // length = 1 ist keine Kollision, length = 2 ist 1 Kollision usw.
        }

        if (length_node > max_length)
        {
            max_length = length_node;
        }
    }
    printf("Maximale Listenlänge: %d\n", max_length);
    printf("Gesamtanzahl der Kollisionen: %d\n", collisions);

    for (int i = 0; i < SIZE; i++)
    {
        if (hash_table[i] != NULL)
        {
            printf("%d: ", i);
            node *current = hash_table[i];

            while (current != NULL)
            {
                printf("%s ", current->word);
                current = current->next;
            }
            printf("\n");
        }
    }
}

void free_hash_table()
{
    for (int i = 0; i < SIZE; i++)
    {
        node *current_node = hash_table[i];

        while (current_node != NULL)
        {
            node *next_node = current_node->next;
            if (current_node->word != NULL)
            {
                /*printf("%s erfolgreich gelöscht\n", current_node->word);*/
                free(current_node->word);
            }
            free(current_node);
            current_node = next_node;
        }
        /*printf("%d erfolgreich gelöscht\n", i);*/
    }
}

// bestimmt wie viele Übereinstimmungen der übergebene Text hat mit ca. 10.000 Wörtern der deutschen Sprache hat und gibt den prozentual Anteil zurück. Die Funktion benutzt dabei eine hash table um einen Zugriff auf die Daten in O(1) zu haben
float get_word_match_percentage(const char *text)
{
    if (is_hash_table_created != 1)
    {
        create_hash_table();
        /*print_hash_table();*/
    }

    int matches = 0; // zählt die Treffer in der Hashtabelle
    int word_count = 0; // zählt die Anzahl wörter in unserem Text, um später den prozentualen Anteil zu bestimmen
    unsigned int index = 0; // wir suchen nach dem Wort in der Hashtable
    node *current_node = NULL;
    char word[30];
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ')
        {
            word[j] = text[i];
            j++;
            word[j] = '\0';
        }
        else if (j > 0) // verhindern, dass z.B. im text 2 Leerzeichen hintereinander sind und ein wort 2x gezählt wird
        {
            word_count++;
            index = hash_function(word);
            current_node = hash_table[index];
            while (current_node != NULL) // wir durchsuchen den ganzen bucket
            {
                if (strcasecmp(word, current_node->word) == 0)
                {
                    matches++;
                    /*printf("wort: \"%s\" gefunden in der hashtable an Index %d\n", word, index);*/
                    break;
                }
                current_node = current_node->next; // nächstes element im bucket checken
            }
            j = 0;
        }
    }

    const float german_similarity = (float) matches / (float) word_count * 100;
    if (german_similarity > 25)
    {
        free_hash_table();
        is_hash_table_created = 0;
    }
    return german_similarity;
}
