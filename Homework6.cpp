#include <iostream>
using namespace std;

char names[100][31];
float prices[100];
int stock[100];
int sold[100];

int main() {

    int numberOfStocks;
    cout << "Введіть кількість іграшок: ";
    cin >> numberOfStocks;

    for (int i = 0; i < numberOfStocks; i++) {
        cout << "Іграшка " << i + 1 << ":\n";
        cout << "Назва: ";
        cin >> names[i];
        cout << "Ціна: ";
        cin >> prices[i];
        cout << "Кількість на складі: ";
        cin >> stock[i];
        cout << "Кількість проданих: ";
        cin >> sold[i];
    }

    cout << "\nНазва\t\tЦіна\tНа складі\tПродано\tПрибуток\n";
    cout << "--------------------------------------------------------\n";

    float totalProfit = 0;
    float maxProfit = 0;
    int maxIndex = 0;

    for (int i = 0; i < numberOfStocks; i++) {
        float profit = prices[i] * sold[i];
        totalProfit += profit;

        if (profit > maxProfit) {
            maxProfit = profit;
            maxIndex = i;
        }

        cout << names[i] << "\t\t\t" << prices[i] << "\t\t\t" << stock[i] << "\t\t\t" << sold[i] << "\t\t" << profit << "$" << endl;
    }

    cout << "\nЗагальний прибуток за день: " << totalProfit << " грн" << endl;
    cout << "Найбільший прибуток: " << maxProfit << " грн ("
         << names[maxIndex] << ")" << endl;

    cout << "\nІграшки, яких залишилося менше п'яти на складі:\n";
    bool lowStock = false;
    for (int i = 0; i < numberOfStocks; i++) {
        if (stock[i] < 5) {
            cout << names[i] << " залишилося: " << stock[i] << "\n";
            lowStock = true;
        }
    }
    if (!lowStock) {
        cout << "Усі іграшки мають достатній запас\n";
    }

    int unsoldToys = 0;
    for (int i = 0; i < numberOfStocks; i++) {
        if (sold[i] == 0) {
            unsoldToys++;
        }
    }

    cout << "Не проданих іграшок є: " << unsoldToys << " товару" << endl;

    return 0;
}