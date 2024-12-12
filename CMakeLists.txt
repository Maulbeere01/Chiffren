cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c Ceaser-Chiffre/Encryption_Ceaser.c frequency_analysis.c Ceaser-Chiffre/Encryption_Ceaser.h frequency_analysis.h
        Ceaser-Chiffre/Ceaser_Decryption.c
        Ceaser-Chiffre/Ceaser_Decryption.h
        Vignere-Chiffre/Encryption/Encryption.c
        Vignere-Chiffre/Encryption/Encryption.h
        Kasiski_Test.c
        Kasiski_Test.h
        Letter_Sequences.c
        Letter_Sequences.h
        Find_Key_Length.c
        Find_Key_Length.h
        Split_into_n_Strings.c
        Split_into_n_Strings.h
        String_Operations.c
        String_Operations.h
        Shift_Values_to_Word.c
        Shift_Values_to_Word.h
        Vignere-Chiffre/Decryption/Decryption.c
        Vignere-Chiffre/Decryption/Decryption.h
        check_if_cracked.c
        check_if_cracked.h)


