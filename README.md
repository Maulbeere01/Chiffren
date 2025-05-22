# Classical Cipher Toolkit

[![Made with C](https://img.shields.io/badge/Made%20with-C-blue.svg)](https://www.cprogramming.com/)

Ein CLI C-Programm zur Ver- und Entschlüsselung sowie zum Brechen von klassischen Chiffren wie Cäsar und Vigenère. Dieses Projekt dient als praktische Demonstration kryptographischer Grundprinzipien und Analysemethoden.

## Inhaltsverzeichnis

1.  [Funktionen](#funktionen)
2.  [Kernalgorithmen](#kernalgorithmen)
3.  [Voraussetzungen](#voraussetzungen)
4.  [Kompilierung](#kompilierung)
5.  [Benutzung](#benutzung)
6.  [Dateistruktur](#dateistruktur)
7.  [Bekannte Einschränkungen](#bekannte-einschränkungen)
8.  [Mögliche Erweiterungen](#mögliche-erweiterungen)

## Funktionen

*   **Cäsar-Chiffre:**
    *   Verschlüsselung von Klartext
    *   Entschlüsselung von Geheimtext mit bekanntem Schlüssel
    *   Automatisches Brechen von Geheimtext mittels Frequenzanalyse
*   **Vigenère-Chiffre:**
    *   Verschlüsselung von Klartext mit einem Schlüsselwort
    *   Entschlüsselung von Geheimtext mit bekanntem Schlüsselwort
    *   Automatisches Brechen von Geheimtext mittels:
        *   Kasiski-Test zur Bestimmung der Schlüssellänge
        *   Frequenzanalyse auf Teiltexten
        *   Brute-Force-Ansatz für Schlüssellängen (falls Kasiski-Test nicht eindeutig)
        *   Abgleich mit einer deutschen Wortliste zur Validierung des Klartextes
*   **Datei-Interaktion:**
    *   Liest zu ver-/entschlüsselnde Texte aus vordefinierten Dateien
    *   Speichert Ergebnisse optional in Ausgabedateien
    *   Verwendet eine externe Wortliste (`words.txt`) für die Kryptoanalyse der Vigenère-Chiffre

## Kernalgorithmen

Das Programm implementiert und nutzt folgende kryptographische Techniken:

*   **Cäsar-Chiffre:**
    *   **Verschiebechiffre:** Jeder Buchstabe wird um einen festen Wert im Alphabet verschoben.
    *   **Frequenzanalyse:** Die Häufigkeitsverteilung der Buchstaben im Geheimtext wird mit der bekannten Häufigkeitsverteilung der deutschen Sprache verglichen, um den wahrscheinlichsten Verschiebewert zu ermitteln.
*   **Vigenère-Chiffre:**
    *   **Polyalphabetische Substitution:** Nutzt ein Schlüsselwort, um für jeden Buchstaben des Klartextes eine andere Cäsar-Verschiebung anzuwenden.
    *   **Kasiski-Test:** Identifiziert wiederholte Zeichensequenzen im Geheimtext. Die Abstände zwischen diesen Sequenzen sind oft Vielfache der Schlüssellänge. Die Schlüssellänge wird durch gewichtete Analyse der Teiler dieser Abstände geschätzt.
    *   **Frequenzanalyse auf Teiltexten:** Nachdem eine wahrscheinliche Schlüssellänge `k` ermittelt wurde, wird der Geheimtext in `k` Teiltexte aufgeteilt. Jeder Teiltext wurde effektiv mit einer einfachen Cäsar-Chiffre verschlüsselt und kann individuell per Frequenzanalyse gebrochen werden, um die einzelnen Buchstaben des Schlüsselwortes zu finden.
    *   **Brute-Force (für Schlüssellänge/Schlüssel):** Falls der Kasiski-Test keine eindeutige Schlüssellänge liefert oder die Entschlüsselung fehlschlägt, testet das Programm systematisch verschiedene Schlüssellängen. Für jede Länge wird versucht, den Schlüssel mittels Frequenzanalyse zu rekonstruieren.
    *   **Wortlistenabgleich:** Zur Validierung eines potenziell entschlüsselten Textes wird dieser gegen eine Liste häufiger deutscher Wörter (`words.txt`) geprüft. Ein hoher Prozentsatz an Übereinstimmungen deutet auf eine erfolgreiche Entschlüsselung hin. Dies wird mittels einer Hashtabelle für effiziente Wortsuche implementiert.
*   **Textvorverarbeitung:**
    *   Umwandlung in Kleinbuchstaben (`str_lower`)
    *   Entfernung von Nicht-Buchstaben-Zeichen (`extract_letters`) für die Analyse

## Voraussetzungen

*   Ein C-Compiler (z.B. GCC, Clang, MSVC)
*   Standard C-Bibliotheken (`stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `math.h`)
*   Die Datei `words.txt` muss im selben Verzeichnis wie die ausführbare Datei liegen, damit das Brechen der Vigenère-Chiffre korrekt funktioniert. Diese Datei sollte eine Liste häufiger Wörter der Zielsprache (hier Deutsch), ein Wort pro Zeile, enthalten.

## Kompilierung

1.  Stellen Sie sicher, dass alle Quelldateien (`.c` und `.h`) in der korrekten Verzeichnisstruktur vorliegen, wie in den `#include`-Anweisungen referenziert.
    *   `main.c` im Hauptverzeichnis.
    *   Weitere Logik- und Hilfsfunktionen in Unterverzeichnissen wie `User-Interaction/`, `User-Interaction/Ceaser-Chiffre/`, `User-Interaction/Vignere-Chiffre/`, etc.

2.  Öffnen Sie ein Terminal oder eine Kommandozeile.

3.  Kompilieren Sie das Projekt. Ein Beispiel mit GCC (Pfade ggf. anpassen):
    ```bash
    gcc main.c \
        User-Interaction/user_interaction.c \
        User-Interaction/string_operations.c \
        User-Interaction/frequency_analysis.c \
        User-Interaction/Ceaser-Chiffre/Encryption_Logic/caeser_encryption_logic.c \
        User-Interaction/Ceaser-Chiffre/Decryption_Logic/caeser_decryption_logic.c \
        User-Interaction/encrypt_caesar.c \
        User-Interaction/decrypt_caesar.c \
        User-Interaction/break_caesar.c \
        User-Interaction/Vignere-Chiffre/Encryption_Logic/vigenere_encryption_logic.c \
        User-Interaction/Vignere-Chiffre/Decryption_Logic/vigenere_decryption_logic.c \
        User-Interaction/encrypt_vigenere.c \
        User-Interaction/decrypt_vigenere.c \
        User-Interaction/break_vigenere.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/kasiski_test.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/find_triplets.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/find_key_length.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/weighted_biggest_divisor.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/split_into_n_strings.c \
        User-Interaction/Break-Vigenere/Kasiski-Test/shift_values_to_word.c \
        User-Interaction/Break-Vigenere/brute_force.c \
        User-Interaction/Break-Vigenere/get_word_match_percentage.c \
        -o cipher_tool -lm -I.
    ```
    *   `-lm` wird für die mathematischen Funktionen aus `math.h` benötigt.
    *   `-I.` fügt das aktuelle Verzeichnis zum Include-Pfad hinzu, falls Header-Dateien relativ zum Projektstammverzeichnis eingebunden werden.
    *   Für ein Projekt dieser Größe empfiehlt sich die Verwendung eines `Makefile`.

## Benutzung

1.  Starten Sie die kompilierte Anwendung (`cipher_tool.exe` unter Windows oder `cipher_tool` unter Linux/macOS, falls plattformunabhängig kompiliert).
2.  Folgen Sie den Anweisungen im Menü:
    *   Wählen Sie die Chiffre (Cäsar oder Vigenère).
    *   Wählen Sie den Modus (Verschlüsseln, Entschlüsseln, Brechen).
3.  Texteingabe:
    *   Für **Verschlüsselung**: Legen Sie Ihren Klartext in `caeser_chiffre_decrypted.txt` bzw. `vigenere_chiffre_decrypted.txt` ab.
    *   Für **Entschlüsselung/Brechen**: Legen Sie Ihren Geheimtext in `caeser_chiffre_encrypted.txt` bzw. `vigenere_chiffre_encrypted.txt` ab.
4.  Schlüsseleingabe:
    *   Bei Bedarf werden Sie zur Eingabe eines numerischen Schlüssels (Cäsar) oder eines Schlüsselwortes (Vigenère) aufgefordert.
5.  Ergebnisausgabe:
    *   Der ver-/entschlüsselte Text wird in der Konsole angezeigt.
    *   Sie werden gefragt, ob das Ergebnis in der entsprechenden Datei (`..._encrypted.txt` oder `..._decrypted.txt`) gespeichert werden soll.
6.  Wiederholung:
    *   Nach jeder Operation können Sie wählen, ob Sie eine weitere Operation durchführen oder das Programm beenden möchten.


## Bekannte Einschränkungen

*   **Windows-Abhängigkeit:** Die Konsolenausgabe für Umlaute ist Windows-spezifisch.
*   **Feste Dateinamen:** Das Programm verwendet hartkodierte Dateinamen für Ein- und Ausgabe.
*   **Speicherverwaltung:** Obwohl `malloc` und `free` verwendet werden, könnten bei sehr großen Eingabetexten oder in Extremsituationen Speicherprobleme auftreten. Eine gründlichere Prüfung auf Speicherlecks und -effizienz wäre für Produktionscode notwendig.
*   **Robustheit der Kryptoanalyse:** Die Kryptoanalyse-Methoden sind für Lehrzwecke implementiert und funktionieren gut für Standardfälle. Bei sehr kurzen Texten, ungewöhnlichen Sprachstatistiken oder sehr langen Vigenère-Schlüsseln in Abhängigkeit zu einem kurzen Text können sie an ihre Grenzen stoßen.



