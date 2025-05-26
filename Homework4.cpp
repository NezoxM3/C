#include <iostream>
using namespace std;

const int MAX_STUDENTS = 30;

int main() {
    int grades[MAX_STUDENTS];
    int count = 0;

    cout << "Введіть оцінки студентів (від 0 до 100). Щоб завершити введіть від’ємне число:\n";
    while (count < MAX_STUDENTS) {
        int grade;
        cout << "Оцінка #" << (count + 1) << ": ";
        cin >> grade;

        if (grade < 0) break;
        if (grade > 100) {
            cout << "Оцінка повинна бути в діапозоні 0 до 100. Спробуйте ще раз.\n";
            continue;
        }

        grades[count] = grade;
        count++;
    }

    cout << "\nВведені оцінки:\n";
    for (int i = 0; i < count; i++) {
        cout << grades[i] << " ";
    }
    cout << "\n";

    if (count == 0) {
        cout << "Оцінки не введені.\n";
        return 0;
    }

    int sum = 0, minGrade = grades[0], maxGrade = grades[0];
    int failed = 0, good = 0, excellent = 0;

    for (int i = 0; i < count; i++) {
        sum += grades[i];
        if (grades[i] < minGrade) minGrade = grades[i];
        if (grades[i] > maxGrade) maxGrade = grades[i];

        if (grades[i] < 60) failed++;
        else if (grades[i] < 80) good++;
        else excellent++;
    }

    double average = static_cast<double>(sum) / count;

    cout << "\nСтатистика:\n";
    cout << "Кількість студентів: " << count << "\n";
    cout << "Середній бал: " << average << "\n";
    cout << "Мінімальний бал: " << minGrade << "\n";
    cout << "Максимальний бал: " << maxGrade << "\n";
    cout << "Не склали іспит (<60): " << failed << "\n";
    cout << "Оцінка 'добре' (60-79): " << good << "\n";
    cout << "Оцінка 'відмінно' (80-100): " << excellent << "\n";

    int searchGrade;
    cout << "\nВведіть оцінку для пошуку: ";
    cin >> searchGrade;

    bool found = false;
    cout << "Оцінка " << searchGrade << " знайдена на позиціях: ";
    for (int i = 0; i < count; i++) {
        if (grades[i] == searchGrade) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "немає такої оцінки у списку.";
    }


    return 0;
}