# Classical Cipher Toolkit

[![Made with C](https://img.shields.io/badge/Made%20with-C-blue.svg)](https://www.cprogramming.com/)

Ein CLI C-Programm zur Ver- und Entschlüsselung sowie zum Brechen von klassischen Chiffren wie Cäsar und Vigenère. Dieses Projekt dient als praktische Demonstration kryptographischer Grundprinzipien und Analysemethoden.

## Inhaltsverzeichnis

1.  [Funktionen](#funktionen)
2.  [Kernalgorithmen](#kernalgorithmen)
3.  [Voraussetzungen](#voraussetzungen)
5.  [Benutzung](#benutzung)


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
*   Die Textdateien müssen im selben Verzeichnis wie die ausführbare Datei liegen, damit das Programm korrekt funktioniert.

## Schnellstart: Installation und Ausführung

1. **Repository klonen**

   Klone das Projekt-Repository:
    ```sh
    git clone git@github.com:Maulbeere01/Chiffren.git
    cd Chiffren
    ```

2. **(Optional) Abhängigkeiten installieren**

   Stelle sicher, dass ein C-Compiler (z.B. `gcc`) und `make` installiert sind.  
   UNIX:
    ```sh
    sudo apt update
    sudo apt install build-essential
    ```

3. **Projekt kompilieren**

    ```sh
    make
    ```

4. **Programm ausführen**

    ```sh
    ./cipher_tool
    ```

5. **(Optional) Aufräumen**

   Um alle erzeugten Objektdateien (`.o`) und die .exe zu löschen:
    ```sh
    make clean
    ```

> **Hinweis:**  
> Stelle sicher, dass sich die benötigten Textdateien (`caeser_chiffre_decrypted.txt`, `caeser_chiffre_encrypted.txt`, `vigenere_chiffre_decrypted.txt`, `vigenere_chiffre_encrypted.txt`, `words.txt`) im selben Verzeichnis wie das Executable befinden oder passe die Pfade im Code entsprechend an.


## Benutzung

1.  Starten Sie die kompilierte Datei (`cipher_tool.exe` unter Windows oder `cipher_tool` unter Linux.
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

    



