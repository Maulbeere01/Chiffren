//
// Created by ben10 on 12/9/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_count(char* string) {
    int whitespace_count = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] == ' ' && string[i-1] != ' ') {
            whitespace_count++;
        }
    }
    return whitespace_count;
}
//Gibt die prozentuale Uebereinstimmung des geknackten Textes mit den 1000 hauefigsten Woertern der deutschen Sprache zurueck
float check_if_cracked(char *text)
{
    
    FILE *file;
    file = fopen("words.txt", "r");

    if(file == NULL) {
        printf("Datei konnte nicht geöffnet werden");
        return -1;
    }

    int counter = 0; // zaehlt die Uebereinstimmungen
    int wordcount = word_count(text);
    char word[30];

    /*printf("length text is %d\n", length);*/

    // wir erstellen ein Array mit allen Woertern aus unserem Geheimtext
    int count_word_length = 0; //zählt die Wortlänge, da diese in jedem neuen String wieder bei 0 beginnen muss
    int index_words = 0; // zählt die Anzahl an gezählten Wörtern in words_in_text
    char **words_in_text = malloc((wordcount + 10) * sizeof(char *)); // +10 ist Puffer, da wordcount nicht 100% genau

    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] == ' ') {
            words_in_text[index_words][count_word_length] = '\0';
            index_words++;
            count_word_length = 0;
        }
        else {
            if (count_word_length == 0) {
                words_in_text[index_words] = malloc(20 * sizeof(char)); // z. b. 50 chars max für ein wort
            }
            words_in_text[index_words][count_word_length] = text[i];
            count_word_length++;
        }
    }
    words_in_text[index_words][count_word_length] = '\0';
    words_in_text[index_words + 1]= NULL;

    /*for(int i = 0;  words_in_text[i]!= NULL; i++) {
        printf("%s\n", words_in_text[i]);
    }*/

    // Prueft jedes Wort gegen jedes Wort in der File, bei einem Treffer wird counter hochgezaehlt und zum naechsten Wort uebergegangen
    for(int i = 0; words_in_text[i]!= NULL; i++) {
        rewind(file);
        while (fscanf(file, "%30s", word) != EOF) {
            if (strcasecmp (words_in_text[i], word) == 0) {
                counter++;
                break;
            }
            /*printf("%s ", word);*/
        }
    }
    //printf("\ncounter: %d", counter);

    for(int i = 0; words_in_text[i] != NULL; i++) {
        free(words_in_text[i]);
    }
    free(words_in_text);

    float german_similarity = (float) counter/wordcount * 100;

    return german_similarity;
}
