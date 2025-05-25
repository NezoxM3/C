#include <iostream>

using namespace std;

const int MAX_PRODUCTS = 10;
string names[MAX_PRODUCTS];
double prices[MAX_PRODUCTS];
int counts[MAX_PRODUCTS];
int productCount = 0;

void showMenu() {
    cout << "\n      МЕНЮ \n";
    cout << "1 - Додати товар\n";
    cout << "2 - Показати список товарів\n";
    cout << "3 - Конвертувати ціну товару в іншу валюту\n";
    cout << "4 - Перевірити товар на акцію\n";
    cout << "5 - Оформити замовлення\n";
    cout << "6 - Вийти\n";
    cout << "Ваш вибір: ";
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Досягнуто межі кількості товарів\n";
        return;
    }
    cout << "Введіть назву товару: ";
    cin >> names[productCount];
    cout << "Введіть ціну товару: ";
    cin >> prices[productCount];
    cout << "Введіть кількість товару: ";
    cin >> counts[productCount];
    productCount++;
    cout << "Товар додано!\n";
}

void showProducts() {
    if (productCount == 0) {
        cout << "Список товарів порожній\n";
        return;
    }
    cout << "\nСписок товарів:\n";
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << names[i] << " - "
             << fixed << prices[i] << " грн - "
             << counts[i] << " шт" << endl;
    }
}

void convertPrice() {
    int index;
    cout << "Виберіть товар (номер): ";
    cin >> index;
    if (index < 1 || index > productCount) {
        cout << "Неправильний номер товару.\n";
        return;
    }
    int currency;
    cout << "Оберіть валюту:\n1 - Долари\n2 - Євро\nВаш вибір: ";
    cin >> currency;
    double converted = 0;
    if (currency == 1) {
        converted = prices[index - 1] / 40.0;
        cout << "Ціна у доларах: $" << fixed << converted << endl;
    } else if (currency == 2) {
        converted = prices[index - 1] / 43.0;
        cout << "Ціна у євро: €" << fixed << converted << endl;
    } else {
        cout << "Невірна валюта.\n";
    }
}

void checkDiscount() {
    int index;
    cout << "Введіть номер товару для перевірки: ";
    cin >> index;
    if (index < 1 || index > productCount) {
        cout << "Невірний номер товару.\n";
        return;
    }
    if (prices[index - 1] < 50) {
        cout << "Товар \"" << names[index - 1] << "\" є акційним!\n";
    } else {
        cout << "Цей товар не підпадає під акцію.\n";
    }
}

void processOrder() {
    double total = 0;
    for (int i = 0; i < productCount; i++) {
        int quantity;
        cout << "Скільки одиниць товару \"" << names[i] << "\" бажаєте купити? ";
        cin >> quantity;
        if (quantity > counts[i]) {
            cout << "Недостатньо товару на складі! Доступно: " << counts[i] << endl;
            quantity = counts[i];
        }
        total += prices[i] * quantity;
    }

    cout << "Сума замовлення: " << fixed << total << " грн\n";

    if (total > 1000) {
        double discount = total * 0.1;
        total -= discount;
        cout << "Застосовано знижку 10%: -" << discount << " грн\n";
    }

    cout << "Підсумкова сума до оплати: " << fixed << total << " грн\n";
    cout << "Дякуємо за покупку!\n";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addProduct(); break;
            case 2: showProducts(); break;
            case 3: convertPrice(); break;
            case 4: checkDiscount(); break;
            case 5: processOrder(); break;
            case 6: cout << "Бувай!\n"; break;
            default: cout << "Вибери щось зі списку\n";
        }
    } while (choice != 6);
    return 0;
}