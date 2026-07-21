#include "HashTable.h"

int main() {
    HashTable ht;

    ht.loadFromFile();

    int choice;
    string name, phone;

    while (true) {
        cout << "\n===== CONTACT SYSTEM =====\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Name: ";
            cin >> name;
            cout << "Phone: ";
            cin >> phone;
            ht.insert(name, phone);
        }

        else if (choice == 2) {
            cout << "Name: ";
            cin >> name;
            ht.search(name);
        }

        else if (choice == 3) {
            cout << "Name: ";
            cin >> name;
            ht.deleteContact(name);
        }

        else if (choice == 4) {
            ht.display();
        }

        else if (choice == 5) {
            break;
        }
    }

    return 0;
}