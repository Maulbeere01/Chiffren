cmake_minimum_required(VERSION 3.29)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c Encryption.c Häufigkeitsanalyse.c Encryption.h Häufigkeitsanalyse.h
        Decryption.c
        Decryption.h
        VigenereEncryption.c
        VigenereEncryption.h)


