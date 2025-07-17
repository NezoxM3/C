#include <iostream>
using namespace std;

// First Task

int First() {
    int num1_first, num2_first;
    cout << "Введіть два числа: ";
    cin >> num1_first >> num2_first;

    int *ptr1_first = &num1_first, *ptr2_first = &num2_first;

    if (*ptr1_first > *ptr2_first)
        cout << "Більше число: " << *ptr1_first << endl;
    else
        cout << "Більше число: " << *ptr2_first << endl;

    return 0;
}

// Second Task

int Second() {
    int input_second;
    cout << "Введіть число: ";
    cin >> input_second;

    int *ptr_second = &input_second;

    if (*ptr_second > 0)
        cout << "Число додатне" << endl;
    else if (*ptr_second < 0)
        cout << "Число від’ємне" << endl;
    else
        cout << "Число дорівнює нулю" << endl;

    return 0;
}

// Third Task

void swapThird(int *val1_third, int *val2_third) {
    int temp_third = *val1_third;
    *val1_third = *val2_third;
    *val2_third = temp_third;
}

int Third() {
    int num1_third, num2_third;
    cout << "Введіть два числа: ";
    cin >> num1_third >> num2_third;

    swapThird(&num1_third, &num2_third);

    cout << "Після обміну: num1 = " << num1_third << ", num2 = " << num2_third << endl;

    return 0;
}

// Fourth Task

int Fourth() {
    double operand1_fourth, operand2_fourth;
    char operator_fourth;
    cout << "Введіть математичний вираз: ";
    cin >> operand1_fourth >> operator_fourth >> operand2_fourth;

    double *ptr1_fourth = &operand1_fourth, *ptr2_fourth = &operand2_fourth;
    double result_fourth;

    switch (operator_fourth) {
        case '+': result_fourth = *ptr1_fourth + *ptr2_fourth; break;
        case '-': result_fourth = *ptr1_fourth - *ptr2_fourth; break;
        case '*': result_fourth = *ptr1_fourth * *ptr2_fourth; break;
        case '/':
            if (*ptr2_fourth != 0)
                result_fourth = *ptr1_fourth / *ptr2_fourth;
            else {
                cout << "Помилка. Ділення на нуль" << endl;
                return 1;
            }
        break;
        default:
            cout << "Невірна операція" << endl;
        return 1;
    }

    cout << "Результат: " << result_fourth << endl;
    return 0;
}

// Fifth Task

int Fifth() {
    const int SIZE_FIFTH = 5;
    int array_fifth[SIZE_FIFTH];

    cout << "Введіть 5 цілих чисел: ";
    for (int i = 0; i < SIZE_FIFTH; ++i)
        cin >> array_fifth[i];

    int *ptr_fifth = array_fifth;
    int sum_fifth = 0;

    for (int i = 0; i < SIZE_FIFTH; ++i)
        sum_fifth += *(ptr_fifth + i);

    cout << "Сума елементів: " << sum_fifth << endl;
    return 0;
}