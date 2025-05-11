#include <iostream>

using namespace std;

int main() {
    // 1.1 Завдання
    cout << "1.1 Завдання:" << endl;
    double R1 = 2.0;
    double R2 = 4.0;
    double R3 = 8.0;

    double totalSum = (1.0 / R1) + (1.0 / R2) + (1.0 / R3);

    double R0 = 1.0 / totalSum;

    cout << "R0 = " << R0 << endl;

    // 1.2 Завдання
    cout << "1.2 Завдання:" << endl;
    double L = 10;
    double pi = 3.14;
    double R = L / (2 * pi);
    double S = pi * R * R;

    cout << "Площа круга " << S << " km²" << endl;

    // 1.3 Завдання
    cout << "1.3 Завдання:" << endl;

    double v = 50;
    double t = 10;
    double a = 20;

    double area = v * t + (a * t * t) / 2;

    cout << "Пройдена відстань становить " << area << " м" << endl;

    // 2.1 Завдання
    cout << "2.1 Завдання:" << endl;

    int totalSeconds;
    cout << "Введіть кількість секунд: ";
    cin >> totalSeconds;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    cout << totalSeconds << " секунд це: " << hours << " годин, " << minutes << " хвилин, "<< seconds << " секунд" << endl;

    return 0;
}
