# Name der Ausgabedatei
TARGET = cipher_tool

CC = gcc
CFLAGS = -Wall -Wextra -O2 -I.

SRCS = \
    main.c \
    string_operations.c \
    frequency_analysis.c \
    User-Interaction/user_interaction.c \
    User-Interaction/encrypt_caeser.c \
    User-Interaction/decrypt_caesar.c \
    User-Interaction/break_caesar.c \
    User-Interaction/encrypt_vigenere.c \
    User-Interaction/decrypt_vigenere.c \
    User-Interaction/break_vigenere.c \
    Break-Vigenere/brute_force.c \
    Break-Vigenere/get_word_match_percentage.c \
    Break-Vigenere/Kasiski-Test/kasiski_test.c \
    Break-Vigenere/Kasiski-Test/find_triplets.c \
    Break-Vigenere/Kasiski-Test/find_key_length.c \
    Break-Vigenere/Kasiski-Test/weighted_biggest_divisor.c \
    Break-Vigenere/Kasiski-Test/split_into_n_strings.c \
    Break-Vigenere/Kasiski-Test/shift_values_to_word.c \
    Ceaser-Chiffre/Encryption_Logic/caeser_encryption_logic.c \
    Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.c \
    Vignere-Chiffre/Encryption_Logic/vigenere_encryption_logic.c \
    Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.c


OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
