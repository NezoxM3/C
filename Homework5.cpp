#include <iostream>

using namespace std;

void randomNums(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100 + 1;
    }
}

bool checkIfInArr(int a[], int n, int val) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == val) {
            return true;
        }
    }
    return false;
}

int getCloseNum(int a[], int n, int val) {
    int near = a[0];
    int minDiff = abs(a[0] - val);

    for (int i = 1; i < n; ++i) {
        int diff = abs(a[i] - val);
        if (diff < minDiff) {
            minDiff = diff;
            near = a[i];
        }
    }
    return near;
}

int main() {
    const int arrSize = 5;
    int myNums[arrSize];
    randomNums(myNums, arrSize);

    const int maxTries = 7;
    int guess;
    bool win = false;

    for (int i = 1; i <= maxTries; ++i) {
        cout << "Attempt " << i << ". Your Guess: ";
        cin >> guess;

        if (checkIfInArr(myNums, arrSize, guess)) {
            cout << "You guested correctly!" << endl;
            win = true;
            break;
        } else {
            int close = getCloseNum(myNums, arrSize, guess);
            if (close < guess) {
                cout << "Incorrect, closest number is lower than yours" << endl;
            } else {
                cout << "Incorrect, closest number is bigger than yours" << endl;
            }
        }
    }

    if (!win) {
        cout << "\nYou didn't guessed any correct numbers" << endl;
        cout << "Correct numbers: ";
        for (int i = 0; i < arrSize; ++i) {
            cout << myNums[i];
            if (i < arrSize - 1) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}