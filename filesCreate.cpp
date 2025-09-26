#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string birthDate;
    string phone;
    string address;
    int age;
    bool isWorkContact;
};

void saveContactToFile(const Contact& c, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << c.firstName << endl;
    file << c.lastName << endl;
    file << c.birthDate << endl;
    file << c.phone << endl;
    file << c.address << endl;
    file << c.age << endl;
    file << c.isWorkContact << endl; // 1 або 0
    file.close();
    cout << "Contact saved to " << filename << endl;
}

Contact readContactFromFile(const string& filename) {
    Contact c;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return c;
    }
    getline(file, c.firstName);
    getline(file, c.lastName);
    getline(file, c.birthDate);
    getline(file, c.phone);
    getline(file, c.address);
    file >> c.age;
    file >> c.isWorkContact;
    file.close();
    return c;
}

int main() {
    Contact c;

    cout << "Enter first name: ";
    getline(cin, c.firstName);
    cout << "Enter last name: ";
    getline(cin, c.lastName);
    cout << "Enter birth date (YYYY-MM-DD): ";
    getline(cin, c.birthDate);
    cout << "Enter phone: ";
    getline(cin, c.phone);
    cout << "Enter address: ";
    getline(cin, c.address);
    cout << "Enter age: ";
    cin >> c.age;
    cout << "Work contact? (1 - yes, 0 - no): ";
    cin >> c.isWorkContact;
    cin.ignore(); // очищаємо буфер після cin

    string filename;
    cout << "Enter filename to save: ";
    getline(cin, filename);

    saveContactToFile(c, filename);

    cout << "\nReading contact back...\n";
    Contact loaded = readContactFromFile(filename);

    cout << "First name: " << loaded.firstName << endl;
    cout << "Last name: " << loaded.lastName << endl;
    cout << "Birth date: " << loaded.birthDate << endl;
    cout << "Phone: " << loaded.phone << endl;
    cout << "Address: " << loaded.address << endl;
    cout << "Age: " << loaded.age << endl;
    cout << "Contact type: " << (loaded.isWorkContact ? "Work" : "Personal") << endl;

    return 0;
}