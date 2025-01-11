cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c
        Ceaser-Chiffre/encryption_ceaser.c
        frequency_analysis.c
        Ceaser-Chiffre/encryption_ceaser.h
        frequency_analysis.h
        Ceaser-Chiffre/ceaser_decryption.c
        Ceaser-Chiffre/ceaser_decryption.h
        Vignere-Chiffre/Encryption/encryption.c
        Vignere-Chiffre/Encryption/encryption.h
        kasiski_test.c
        kasiski_test.h
        letter_sequences.c
        letter_sequences.h
        find_key_length.c
        find_key_length.h
        split_into_n_strings.c
        split_into_n_strings.h
        string_operations.c
        string_operations.h
        shift_values_to_word.c
        shift_values_to_word.h
        Vignere-Chiffre/Decryption/decryption.c
        Vignere-Chiffre/Decryption/decryption.h
        weighted_biggest_divisor.c
        weighted_biggest_divisor.h
        brute_force.c
        brute_force.h
        get_word_match_percentage.c
        get_word_match_percentage.h
)

target_link_libraries(untitled2 m)
