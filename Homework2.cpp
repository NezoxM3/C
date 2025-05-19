#include <iostream>

using namespace std;

int main() {
    // 1 Завдання
    cout << "1 task:" << endl;

    int number;
    cout << "Type a six digit number: ";
    cin >> number;

    if (number < 100000 || number > 999999) {
        cout << "Error, this is not a six digit number!" << endl;
        return 0;
    }

    int firstDigit = number / 100000;
    int secondDigit = (number / 10000) % 10;
    int thirdDigit = (number / 1000) % 10;
    int fourthDigit = (number / 100) % 10;
    int fifthDigit = (number / 10) % 10;
    int sixthDigit = number % 10;

    int sum1 = firstDigit + secondDigit + thirdDigit;
    int sum2 = fourthDigit + fifthDigit + sixthDigit;

    if (sum1 == sum2) {
        cout << "It is a lucky number!" << endl;
    } else {
        cout << "That is not a lucky number" << endl;
    }

    // 2 Завдання
    cout << "2 task:" << endl;

    int numberH2;
    cout << "Type a four digit number: ";
    cin >> numberH2;

    if (numberH2 < 1000 || numberH2 > 9999) {
        cout << "Error: this is not a four digit number!" << endl;
        return 0;
    }

    int digit1 = numberH2 / 1000;
    int digit2 = (numberH2 / 100) % 10;
    int digit3 = (numberH2 / 10) % 10;
    int digit4 = numberH2 % 10;

    int newNumber = digit2 * 1000 + digit1 * 100 + digit4 * 10 + digit3;

    cout << "Updated number: " << newNumber << endl;


    // 3 Завдання
    cout << "3 task:" << endl;

    int first, second, third, fourth, fifth, sixth, seventh;
    int max;

    cout << "Type seven different numbers: " << endl;
    cin >> first >> second >> third >> fourth >> fifth >> sixth >> seventh;

    max = first;

    if (second > max) max = second;
    if (third > max) max = third;
    if (fourth > max) max = fourth;
    if (fifth > max) max = fifth;
    if (sixth > max) max = sixth;
    if (seventh > max) max = seventh;

    cout << "Biggest number is: " << max << endl;

    // 4 Завдання
    cout << "4 task:" << endl;

    int distanceAB, distanceBC, weight;
    int fuelPerKm;
    const int tankCapacity = 300;

    // Ввід
    cout << "Type a distance between A and B in km: ";
    cin >> distanceAB;
    cout << "Type a distance between B and C in km: ";
    cin >> distanceBC;
    cout << "Type a weight of the cargo: ";
    cin >> weight;

    if (weight > 2000) {
        cout << "It's over 2000 weight, it is too heavy to make the flight" << endl;
        return 0;
    }

    if (weight <= 500)
        fuelPerKm = 1;
    else if (weight <= 1000)
        fuelPerKm = 4;
    else if (weight <= 1500)
        fuelPerKm = 7;
    else
        fuelPerKm = 9;

    int fuelNeededAB = distanceAB * fuelPerKm;
    int fuelNeededBC = distanceBC * fuelPerKm;

    if (fuelNeededAB > tankCapacity) {
        cout << "It's imposible to make a flight from A to B, too low on fuel" << endl;
        return 0;
    }

    if (fuelNeededBC > tankCapacity) {
        cout << "It's imposible to make a flight from B to C, too low on fuel" << endl;
        return 0;
    }

    int fuelLeft = tankCapacity - fuelNeededAB;
    int refuelNeeded = fuelNeededBC - fuelLeft;

    cout << "You need " << refuelNeeded << " fuel to finish the transportation" << endl;

    return 0;
}