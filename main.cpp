//this project created by furkan askin
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

class Phonebook {
private:
    vector<Contact> contacts;

    // Helper function to find a contact by name
    vector<Contact>::iterator findContact(const string& name) {
        return find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.name == name;
        });
    }

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully." << endl;
    }

    void searchContact(const string& name) {
        auto it = findContact(name);
        if (it != contacts.end()) {
            cout << "Name: " << it->name << endl;
            cout << "Phone Number: " << it->phoneNumber << endl;
            cout << "Email: " << it->email << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void editContact(const string& name) {
        auto it = findContact(name);
        if (it != contacts.end()) {
            cout << "Enter new phone number: ";
            cin >> it->phoneNumber;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter new email: ";
            cin >> it->email;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Contact updated successfully." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void deleteContact(const string& name) {
        auto it = findContact(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            cout << "Contact deleted successfully." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void printAllContacts() const {
        if (contacts.empty()) {
            cout << "Phonebook is empty." << endl;
        } else {
            cout << "All Contacts:" << endl;
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.name << endl;
                cout << "Phone Number: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "------------------------" << endl;
            }
        }
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Phonebook phonebook;

    while (true) {
        cout << "\nPhonebook Application" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Print All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: {
                Contact contact;
                cout << "Enter name: ";
                getline(cin, contact.name);
                cout << "Enter phone number: ";
                getline(cin, contact.phoneNumber);
                cout << "Enter email: ";
                getline(cin, contact.email);
                phonebook.addContact(contact);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                phonebook.searchContact(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name to edit: ";
                getline(cin, name);
                phonebook.editContact(name);
                break;
            }
            case 4: {
                string name;
                cout << "Enter name to delete: ";
                getline(cin, name);
                phonebook.deleteContact(name);
                break;
            }
            case 5:
                phonebook.printAllContacts();
                break;
            case 6:
                cout << "Exiting Phonebook Application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
