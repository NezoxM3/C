#include <iostream>

template <typename T>T minValue(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

template <typename T>int findInArray(T arr[], int size, T value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a = 5, b = 10;
    std::cout << "Min: " << minValue(a, b) << "\n";
    std::cout << "Max: " << maxValue(a, b) << "\n";

    swapValues(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << "\n";

    double arr[] = {2.5, 3.1, 4.7, 1.0};
    int size = 4;

    std::cout << "Array: ";
    printArray(arr, size);

    int index = findInArray(arr, size, 4.7);
    std::cout << "\nIndex of 4.7: " << index << "\n";

    return 0;
}