#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int showMenu(const vector<string>& items) {
    int active = 0;

    while (true) {
        system("cls");

        for (int i = 0; i < items.size(); i++) {
            if (i == active) {
                cout << "\033[1;32m";
                cout << "> " << items[i] << "\033[0m" << endl;
            } else {
                cout << "  " << items[i] << endl;
            }
        }

        int key = _getch();

        if (key == 0 || key == 224) {
            key = _getch();
            if (key == KEY_UP) {
                active = (active - 1 + items.size()) % items.size();
            } else if (key == KEY_DOWN) {
                active = (active + 1) % items.size();
            }
        } else if (key == KEY_ENTER) {
            return active + 1;
        }
    }
}

int main() {
    vector<string> menuItems = {
        "Нова гра",
        "Продовжити",
        "Налаштування",
        "Вихід"
    };

    int choice = showMenu(menuItems);
    cout << "Ви вибрали: " << menuItems[choice - 1] << endl;

    return 0;
}