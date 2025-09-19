#include <iostream>
#include <string>
using namespace std;

// Функція для позиціонування курсору за координатами (x, y)
void setCursorPosition(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

// Функція для зміни кольору тексту
void setTextColor(int color) {
    cout << "\033[" << color << "m";
}

// Функція для зміни кольору фону
void setBackgroundColor(int color) {
    cout << "\033[" << color << "m";
}

// Функція для скидання кольорів до стандартних
void resetColors() {
    cout << "\033[0m";
}

// Функція для очищення екрана
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void createFrame(int width, int height, char symbol, int textColor, int backgroundColor) {
    setTextColor(textColor);
    setBackgroundColor(backgroundColor);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << symbol;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    resetColors();
}

int main() {
    int w, h;
    char symbol;
    int textColor, backgroundColor;

    cout << "Введіть ширину рамки: ";
    cin >> w;
    cout << "Введіть висоту рамки: ";
    cin >> h;
    cout << "Введіть символ рамки: ";
    cin >> symbol;
    cout << "Введіть код кольору тексту: ";
    cin >> textColor;
    cout << "Введіть код кольору фону: ";
    cin >> backgroundColor;

    clearScreen();
    createFrame(w, h, symbol, textColor, backgroundColor);

    return 0;
}