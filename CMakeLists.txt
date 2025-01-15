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
        encrypt_caeser.c
        encrypt_caeser.h
        decrypt_caesar.c
        decrypt_caesar.h
        break_caesar.c
        break_caesar.h
        encrypt_vigenere.c
        encrypt_vigenere.h
        user_interaction.c
        user_interaction.h
        decrypt_vigenere.c
        decrypt_vigenere.h
        break_vigenere.c
        break_vigenere.h
        Break_Vigenere/Kasiski-Test/kasiski_test.c
        Break_Vigenere/Kasiski-Test/kasiski_test.h
        Break_Vigenere/Kasiski-Test/split_into_n_strings.c
        Break_Vigenere/Kasiski-Test/split_into_n_strings.h
        Break_Vigenere/Kasiski-Test/shift_values_to_word.h
        Break_Vigenere/Kasiski-Test/shift_values_to_word.c
        Break_Vigenere/get_word_match_percentage.c
        Break_Vigenere/get_word_match_percentage.h
        Break_Vigenere/brute_force.c
        Break_Vigenere/brute_force.h
        Break_Vigenere/Kasiski-Test/find_triplets.c
        Break_Vigenere/Kasiski-Test/find_triplets.h
        Break_Vigenere/Kasiski-Test/find_key_length.c
        Break_Vigenere/Kasiski-Test/find_key_length.h
        Break_Vigenere/Kasiski-Test/weighted_biggest_divisor.c
        Break_Vigenere/Kasiski-Test/weighted_biggest_divisor.h


)

target_link_libraries(untitled2 m)
