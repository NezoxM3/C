#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// ------------ ПОКАЖЧИКИ -----------

// Завдання 1

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divi(double a, double b) {
    if (b != 0) return a / b;
    cout << "Ділення на нуль!" << endl;
    return 0;
}

int PointerCalculator() {
    typedef double (*Operation)(double, double);
    Operation operations[256] = {};

    operations['+'] = add;
    operations['-'] = sub;
    operations['*'] = mul;
    operations['/'] = divi;

    char op;
    double x, y;

    cout << "Введіть вираз (наприклад 5 + 2): ";
    cin >> x >> op >> y;

    if (operations[op]) {
        double result = operations[op](x, y);
        cout << "Результат: " << result << endl;
    } else {
        cout << "Невідома операція" << endl;
    }

    return 0;
}

// Завдання 2

void SumArrays(int *A, int *B, int *C, int size) {
    for (int i = 0; i < size; ++i)
        *(C + i) = *(A + i) + *(B + i);
}

int PointerSumArrays() {
    const int SIZE = 5;
    int A[SIZE], B[SIZE], C[SIZE];

    cout << "Введіть 5 чисел для масиву A: ";
    for (int i = 0; i < SIZE; ++i)
        cin >> A[i];

    cout << "Введіть 5 чисел для масиву B: ";
    for (int i = 0; i < SIZE; ++i)
        cin >> B[i];

    SumArrays(A, B, C, SIZE);

    cout << "Результат (масив C): ";
    for (int i = 0; i < SIZE; ++i)
        cout << C[i] << " ";
    cout << endl;

    return 0;
}

// ----------- РЯДКИ ------------

// Завдання 1

int ReplaceSpacesWithTabs() {
    char str[256];
    cout << "Введіть рядок: ";
    cin.ignore();
    cin.getline(str, 256);

    for (int i = 0; str[i]; ++i) {
        if (str[i] == ' ')
            str[i] = '\t';
    }

    cout << "Результат: " << str << endl;
    return 0;
}

// Завдання 2

int CountLettersDigitsOther() {
    char str[256];
    cout << "Введіть рядок: ";
    cin.ignore();
    cin.getline(str, 256);

    int letters = 0, digits = 0, other = 0;

    for (int i = 0; str[i]; ++i) {
        if (isalpha(str[i])) ++letters;
        else if (isdigit(str[i])) ++digits;
        else ++other;
    }

    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших: " << other << endl;
    return 0;
}

// Завдання 3

int CountWordsInSentence() {
    char str[256];
    cout << "Введіть речення: ";
    cin.ignore();
    cin.getline(str, 256);

    int words = 0;
    bool inWord = false;

    for (int i = 0; str[i]; ++i) {
        if (!isspace(str[i]) && !inWord) {
            inWord = true;
            ++words;
        } else if (isspace(str[i])) {
            inWord = false;
        }
    }

    cout << "Кількість слів: " << words << endl;
    return 0;
}

// Завдання 4

bool isPalindrome(const char* str) {
    int len = strlen(str);
    int left = 0, right = len - 1;

    while (left < right) {
        while (!isalnum(str[left]) && left < right) ++left;
        while (!isalnum(str[right]) && left < right) --right;

        if (tolower(str[left]) != tolower(str[right]))
            return false;

        ++left;
        --right;
    }
    return true;
}

int CheckPalindrome() {
    char str[256];
    cout << "Введіть рядок: ";
    cin.ignore();
    cin.getline(str, 256);

    if (isPalindrome(str))
        cout << "Це паліндром." << endl;
    else
        cout << "Це не паліндром." << endl;

    return 0;
}

int main() {
    while (true) {
        cout << "\nМеню:\n"
             << "1. Калькулятор (використовуючи масив покажчиків на функції)\n"
             << "2. Сума масивів A і B у масив C (використовуючи покажчики)\n"
             << "3. Замінити пробіли на табуляцію\n"
             << "4. Підрахунок літер, цифр та інших символів\n"
             << "5. Підрахунок кількості слів у реченні\n"
             << "6. Перевірка, чи є рядок паліндромом\n"
             << "0. Вихід\n"
             << "Ваш вибір: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: PointerCalculator(); break;
            case 2: PointerSumArrays(); break;
            case 3: ReplaceSpacesWithTabs(); break;
            case 4: CountLettersDigitsOther(); break;
            case 5: CountWordsInSentence(); break;
            case 6: CheckPalindrome(); break;
            case 0: cout << "Вихід з програми.\n"; return 0;
            default: cout << "Невірний вибір.\n";
        }
    }

    return 0;
}