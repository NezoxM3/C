#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

//Завдання 1
void compareFiles(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    if (!f1 || !f2) {
        cout << "[Помилка] Не вдалося відкрити один з файлів для порівняння.\n";
        return;
    }

    string line1, line2;
    int lineNumber = 1;
    bool allMatch = true;

    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Рядок " << lineNumber << " не збігається:\n";
            cout << "Файл 1: " << line1 << "\n";
            cout << "Файл 2: " << line2 << "\n";
            allMatch = false;
        }
        lineNumber++;
    }

    while (getline(f1, line1)) {
        cout << "Додатковий рядок у файлі 1: " << line1 << "\n";
        allMatch = false;
    }

    while (getline(f2, line2)) {
        cout << "Додатковий рядок у файлі 2: " << line2 << "\n";
        allMatch = false;
    }

    if (allMatch) {
        cout << "Усі рядки збігаються.\n";
    }
}

//Завдання 2
bool isVowel(char c) {
    string vowels = "aeiouаеёиіоуюяєAEIOUАЕЁИІОУЮЯЄ";
    return vowels.find(c) != string::npos;
}

bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
}

void analyzeFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in || !out) {
        cout << "[Помилка] Не вдалося відкрити файл для аналізу.\n";
        return;
    }

    int charCount = 0, lineCount = 0, vowels = 0, consonants = 0, digits = 0;
    string line;

    while (getline(in, line)) {
        lineCount++;
        for (char c : line) {
            charCount++;
            if (isdigit(c)) digits++;
            else if (isVowel(c)) vowels++;
            else if (isConsonant(c)) consonants++;
        }
    }

    out << "Кількість символів: " << charCount << "\n";
    out << "Кількість рядків: " << lineCount << "\n";
    out << "Кількість голосних: " << vowels << "\n";
    out << "Кількість приголосних: " << consonants << "\n";
    out << "Кількість цифр: " << digits << "\n";

    cout << "Статистика записана в файл: " << outputFile << "\n";
}

//Завдання 3
char shiftChar(char c, int key) {
    if ((c >= 'A' && c <= 'Z')) {
        return 'A' + (c - 'A' + key) % 26;
    } else if ((c >= 'a' && c <= 'z')) {
        return 'a' + (c - 'a' + key) % 26;
    } else if ((c >= 'А' && c <= 'Я')) {
        return 'А' + (c - 'А' + key) % 32;
    } else if ((c >= 'а' && c <= 'я')) {
        return 'а' + (c - 'а' + key) % 32;
    } else {
        return c;
    }
}

void caesarCipher(const string& inputFile, const string& outputFile, int key) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in || !out) {
        cout << "[Помилка] Не вдалося відкрити файл для шифрування.\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        for (char& c : line) {
            c = shiftChar(c, key);
        }
        out << line << "\n";
    }

    cout << "Шифрування завершено. Результат у файлі: " << outputFile << "\n";
}

int main() {
    cout << "=== Завдання 1: Порівняння файлів ===\n";
    compareFiles("file1.txt", "file2.txt");

    cout << "\n=== Завдання 2: Статистика тексту ===\n";
    analyzeFile("input.txt", "stats.txt");

    cout << "\n=== Завдання 3: Шифр Цезаря ===\n";
    caesarCipher("plain.txt", "encrypted.txt", 3); // зсув = 3

    return 0;
}