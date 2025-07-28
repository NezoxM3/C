#include <iostream>
#include <string>
#include <map>
#include <cctype>

void replaceAllWords(std::string& text, const std::string& from, const std::string& to) {
    std::size_t pos = 0;
    while ((pos = text.find(from, pos)) != std::string::npos) {
        text.replace(pos, from.length(), to);
        pos += to.length();
    }
}

void capitalizeSentences(std::string& text) {
    bool capitalizeNext = true;
    for (std::size_t i = 0; i < text.length(); ++i) {
        if (capitalizeNext && std::isalpha(static_cast<unsigned char>(text[i]))) {
            text[i] = std::toupper(static_cast<unsigned char>(text[i]));
            capitalizeNext = false;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            capitalizeNext = true;
        }
    }
}

void countLetters(const std::string& text, std::map<char, int>& letterCount) {
    for (char ch : text) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            letterCount[std::tolower(static_cast<unsigned char>(ch))]++;
        }
    }
}

void countDigits(const std::string& text, std::map<char, int>& digitCount) {
    for (char ch : text) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            digitCount[ch]++;
        }
    }
}

int main() {
    std::string text;
    std::cout << "Введіть текст:\n";
    std::getline(std::cin, text);

    std::string wordToFind, wordToReplace;
    std::cout << "Слово для заміни: ";
    std::cin >> wordToFind;
    std::cout << "Замінити на: ";
    std::cin >> wordToReplace;

    replaceAllWords(text, wordToFind, wordToReplace);

    capitalizeSentences(text);

    std::map<char, int> letterCount;
    countLetters(text, letterCount);

    std::map<char, int> digitCount;
    countDigits(text, digitCount);

    std::cout << "\n=== Оброблений текст ===\n" << text << std::endl;

    std::cout << "\n=== Кількість літер ===\n";
    for (const auto& pair : letterCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "\n=== Кількість цифр ===\n";
    for (const auto& pair : digitCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}