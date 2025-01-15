cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c
        Ceaser-Chiffre/Encryption_Logic/caeser_encryption_logic.c
        frequency_analysis.c
        Ceaser-Chiffre/Encryption_Logic/caeser_encryption_logic.h
        frequency_analysis.h
        Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.c
        Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.h
        Vignere-Chiffre/Encryption_Logic/vigenere_encryption_logic.c
        Vignere-Chiffre/Encryption_Logic/vigenere_decryption_logic.h
        string_operations.c
        string_operations.h
        Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.c
        Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.h
        Break-Vigenere/Kasiski-Test/kasiski_test.c
        Break-Vigenere/Kasiski-Test/kasiski_test.h
        Break-Vigenere/Kasiski-Test/split_into_n_strings.c
        Break-Vigenere/Kasiski-Test/split_into_n_strings.h
        Break-Vigenere/Kasiski-Test/shift_values_to_word.h
        Break-Vigenere/Kasiski-Test/shift_values_to_word.c
        Break-Vigenere/get_word_match_percentage.c
        Break-Vigenere/get_word_match_percentage.h
        Break-Vigenere/brute_force.c
        Break-Vigenere/brute_force.h
        Break-Vigenere/Kasiski-Test/find_triplets.c
        Break-Vigenere/Kasiski-Test/find_triplets.h
        Break-Vigenere/Kasiski-Test/find_key_length.c
        Break-Vigenere/Kasiski-Test/find_key_length.h
        Break-Vigenere/Kasiski-Test/weighted_biggest_divisor.c
        Break-Vigenere/Kasiski-Test/weighted_biggest_divisor.h
        User-Interaction/break_caesar.c
        User-Interaction/break_caesar.h
        User-Interaction/break_vigenere.c
        User-Interaction/break_vigenere.h
        User-Interaction/decrypt_caesar.c
        User-Interaction/decrypt_caesar.h
        User-Interaction/decrypt_vigenere.c
        User-Interaction/decrypt_vigenere.h
        User-Interaction/encrypt_caeser.h
        User-Interaction/encrypt_caeser.c
        User-Interaction/encrypt_vigenere.c
        User-Interaction/encrypt_vigenere.h
        User-Interaction/user_interaction.c
        User-Interaction/user_interaction.h
)

target_link_libraries(untitled2 m)
