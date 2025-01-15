cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c
        Ceaser-Chiffre/c_encryption.c
        frequency_analysis.c
        Ceaser-Chiffre/c_encryption.h
        frequency_analysis.h
        Ceaser-Chiffre/c_decryption.c
        Ceaser-Chiffre/c_decryption.h
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
        encrypt_cäser.c
        encrypt_cäser.h
        decrypt_cäsar.c
        decrypt_cäsar.h
        break_cäsar.c
        break_cäsar.h
        encrypt_vigenere.c
        encrypt_vigenere.h
        user_interaction.c
        user_interaction.h
        decrypt_vigenere.c
        decrypt_vigenere.h
        break_vigenere.c
        break_vigenere.h
)

target_link_libraries(untitled2 m)
