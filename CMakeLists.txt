cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c Encryption.c Häufigkeitsanalyse.c Encryption.h Häufigkeitsanalyse.h
        Decryption.c
        Decryption.h
        VigenereEncryption.c
        VigenereEncryption.h
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
        shiftValues_to_word.c
        shiftValues_to_word.h
        Decryption_Vigenere.c
        Decryption_Vigenere.h
        check_if_cracked.c
        check_if_cracked.h)


