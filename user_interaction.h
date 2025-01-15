//
// Created by benwe on 15.01.2025.
//

#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

char *read_file_to_string(const char* filename);
char get_user_choice();
void write_string_to_file(const char* filename, char *string);
int get_valid_shift_value();
char *get_secret_word();
int is_key_valid(const char *key);
#endif //USER_INTERACTION_H
