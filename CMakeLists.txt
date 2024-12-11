cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c Ceaser-Chiffre/Encryption_Ceaser.c Frequency_Analasys.c Ceaser-Chiffre/Encryption_Ceaser.h Frequency_Analasys.h
        Ceaser-Chiffre/Ceaser_Decryption.c
        Ceaser-Chiffre/Ceaser_Decryption.h
        Vigenere_Encryption.c
        Vigenere_Encryption.h
        Kasiski_Test.c
        Kasiski_Test.h
        Letter_Sequences.c
        Letter_Sequences.h
        find_key_length.c
        find_key_length.h
        split_into_n_strings.c
        split_into_n_strings.h
        string_operations.c
        string_operations.h
        Shift_Values_to_Word.c
        Shift_Values_to_Word.h
        Decryption_Vigenere.c
        Decryption_Vigenere.h
        check_if_cracked.c
        check_if_cracked.h)


