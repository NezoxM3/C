#include <iostream>
using namespace std;

void setCursorPosition(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

void drawField(char field[10][10], int startX, int startY) {
    for (int i = 0; i < 10; i++) {
        setCursorPosition(startX, startY + i);
        for (int j = 0; j < 10; j++) {
            if (field[i][j] == 'E')
                cout << "\033[44m  \033[0m";
            else if (field[i][j] == 'S')
                cout << "\033[47m  \033[0m";
            else if (field[i][j] == 'H')
                cout << "\033[41m  \033[0m";
        }
    }
}

int main() {
    char player[10][10] = {
        {'E','E','E','E','E','E','E','E','E','S'},
        {'S','E','E','S','S','S','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','S'},
        {'E','S','E','E','E','S','S','S','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'E','S','S','E','E','E','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'S','S','S','S','E','E','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'}
    };

    char computer[10][10] = {
        {'E','E','S','S','S','S','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'E','E','E','S','S','S','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'E','E','S','S','E','E','E','H','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'},
        {'E','E','E','E','E','S','E','E','E','E'},
        {'E','E','E','E','E','S','E','E','E','E'},
        {'E','E','E','E','E','S','E','E','E','E'},
        {'E','E','E','E','E','E','E','E','E','E'}
    };

    drawField(player, 5, 2);
    drawField(computer, 35, 2);

    cout << "\n\n";
    return 0;
}