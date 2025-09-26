#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
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

void saveContactsToFile(const vector<Contact>& contacts, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    file << contacts.size() << endl;
    for (const auto& c : contacts) {
        file << c.firstName << endl;
        file << c.lastName << endl;
        file << c.birthDate << endl;
        file << c.phone << endl;
        file << c.address << endl;
        file << c.age << endl;
        file << c.isWorkContact << endl;
    }
    file.close();
}

vector<Contact> readContactsFromFile(const string& filename) {
    vector<Contact> contacts;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found. Starting with empty contact list." << endl;
        return contacts;
    }

    size_t n;
    file >> n;
    file.ignore();
    for (size_t i = 0; i < n; i++) {
        Contact c;
        getline(file, c.firstName);
        getline(file, c.lastName);
        getline(file, c.birthDate);
        getline(file, c.phone);
        getline(file, c.address);
        file >> c.age;
        file >> c.isWorkContact;
        file.ignore();
        contacts.push_back(c);
    }
    file.close();
    return contacts;
}

void printContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i].firstName << " " << contacts[i].lastName
             << " (" << (contacts[i].isWorkContact ? "Work" : "Personal") << ")\n";
    }
}

void addContact(vector<Contact>& contacts) {
    Contact c;
    cin.ignore();
    cout << "Enter first name: "; getline(cin, c.firstName);
    cout << "Enter last name: "; getline(cin, c.lastName);
    cout << "Enter birth date: "; getline(cin, c.birthDate);
    cout << "Enter phone: "; getline(cin, c.phone);
    cout << "Enter address: "; getline(cin, c.address);
    cout << "Enter age: "; cin >> c.age;
    cout << "Work contact? (1-yes, 0-no): "; cin >> c.isWorkContact;
    contacts.push_back(c);
    cout << "Contact added!\n";
}

void editContact(vector<Contact>& contacts) {
    printContacts(contacts);
    if (contacts.empty()) return;
    cout << "Choose contact number to edit: ";
    size_t idx;
    cin >> idx;
    if (idx == 0 || idx > contacts.size()) {
        cout << "Invalid index.\n";
        return;
    }
    Contact& c = contacts[idx - 1];
    cin.ignore();
    cout << "Enter first name (" << c.firstName << "): "; getline(cin, c.firstName);
    cout << "Enter last name (" << c.lastName << "): "; getline(cin, c.lastName);
    cout << "Enter birth date (" << c.birthDate << "): "; getline(cin, c.birthDate);
    cout << "Enter phone (" << c.phone << "): "; getline(cin, c.phone);
    cout << "Enter address (" << c.address << "): "; getline(cin, c.address);
    cout << "Enter age (" << c.age << "): "; cin >> c.age;
    cout << "Work contact? (1-yes, 0-no): "; cin >> c.isWorkContact;
    cout << "Contact updated!\n";
}

void deleteContact(vector<Contact>& contacts) {
    printContacts(contacts);
    if (contacts.empty()) return;
    cout << "Choose contact number to delete: ";
    size_t idx;
    cin >> idx;
    if (idx == 0 || idx > contacts.size()) {
        cout << "Invalid index.\n";
        return;
    }
    contacts.erase(contacts.begin() + (idx - 1));
    cout << "Contact deleted!\n";
}

long long loadTotalTime(const string& filename) {
    ifstream file(filename);
    long long seconds = 0;
    if (file.is_open()) {
        file >> seconds;
    }
    return seconds;
}

void saveTotalTime(const string& filename, long long seconds) {
    ofstream file(filename);
    if (file.is_open()) {
        file << seconds;
    }
}

void printTime(long long seconds) {
    long long hours = seconds / 3600;
    long long minutes = (seconds % 3600) / 60;
    long long sec = seconds % 60;
    cout << "Total program runtime: "
         << hours << "h " << minutes << "m " << sec << "s\n";
}

int main() {
    string filename;
    cout << "Enter contacts filename: ";
    getline(cin, filename);

    vector<Contact> contacts = readContactsFromFile(filename);

    auto start = chrono::steady_clock::now();

    string timeFile = "time.txt";
    long long totalSeconds = loadTotalTime(timeFile);
    printTime(totalSeconds);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Show all contacts\n";
        cout << "2. Add new contact\n";
        cout << "3. Edit contact\n";
        cout << "4. Delete contact\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: printContacts(contacts); break;
            case 2: addContact(contacts); break;
            case 3: editContact(contacts); break;
            case 4: deleteContact(contacts); break;
            case 0:
                saveContactsToFile(contacts, filename);
                auto end = chrono::steady_clock::now();
                long long sessionSeconds =
                    chrono::duration_cast<chrono::seconds>(end - start).count();
                totalSeconds += sessionSeconds;
                saveTotalTime(timeFile, totalSeconds);
                cout << "Contacts saved. Exiting...\n";
                printTime(totalSeconds);
                break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}