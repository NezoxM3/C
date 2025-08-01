#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Перше Завдання
struct Complex {
    double real;
    double imag;

    Complex add(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    }

    Complex subtract(const Complex& other) const {
        return {real - other.real, imag - other.imag};
    }

    Complex multiply(const Complex& other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    Complex divide(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return {
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        };
    }

    void print() const {
        cout << real;
        if (imag >= 0) cout << "+";
        cout << imag << "i" << endl;
    }
};

//Друге завдання
struct Car {
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    string transmission;

    void input() {
        cout << "Довжина: "; cin >> length;
        cout << "Кліренс: "; cin >> clearance;
        cout << "Об'єм двигуна: "; cin >> engineVolume;
        cout << "Потужність двигуна: "; cin >> enginePower;
        cout << "Діаметр коліс: "; cin >> wheelDiameter;
        cin.ignore();
        cout << "Колір: "; getline(cin, color);
        cout << "Тип коробки передач: "; getline(cin, transmission);
    }

    void display() const {
        cout << "Авто:\n";
        cout << "Довжина: " << length << " м\n";
        cout << "Кліренс: " << clearance << " см\n";
        cout << "Об'єм двигуна: " << engineVolume << " л\n";
        cout << "Потужність: " << enginePower << " к.с.\n";
        cout << "Діаметр коліс: " << wheelDiameter << " дюймів\n";
        cout << "Колір: " << color << "\n";
        cout << "Коробка передач: " << transmission << "\n";
    }
};

void searchByColor(const vector<Car>& cars, const string& colorToFind) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.color == colorToFind) {
            car.display();
            cout << "------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Автомобілів з кольором \"" << colorToFind << "\" не знайдено.\n";
    }
}

int main() {
    cout << "\nПерше Завдання\n";
    Complex a, b;
    cout << "Введіть дійсну та уявну частину першого числа: ";
    cin >> a.real >> a.imag;
    cout << "Введіть дійсну та уявну частину другого числа: ";
    cin >> b.real >> b.imag;

    cout << "Сума: "; a.add(b).print();
    cout << "Різниця: "; a.subtract(b).print();
    cout << "Добуток: "; a.multiply(b).print();
    cout << "Частка: "; a.divide(b).print();

    cout << "\n//Друге завдання\n";
    int n;
    cout << "Скільки автомобілів ввести? ";
    cin >> n;

    vector<Car> garage;
    for (int i = 0; i < n; ++i) {
        cout << "\nВведення авто #" << (i + 1) << ":\n";
        Car temp;
        temp.input();
        garage.push_back(temp);
    }

    string colorSearch;
    cout << "\nВведіть колір для пошуку: ";
    getline(cin, colorSearch);
    if (colorSearch.empty()) getline(cin, colorSearch);

    cout << "\nРезультати пошуку:\n";
    searchByColor(garage, colorSearch);

    return 0;
}