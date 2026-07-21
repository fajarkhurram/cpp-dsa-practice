#include "HashTable.h"
#include <fstream>

// Constructor
HashTable::HashTable(int s) {
    size = s;
    count = 0;

    table = new Node*[size];

    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

// Hash Function
int HashTable::hashFunction(string name) {
    int sum = 0;
    for (char c : name) {
        sum += c;
    }
    return sum % size;
}

// LOAD FACTOR
float HashTable::loadFactor() {
    return (float)count / size;
}

// 🔥 REHASHING FUNCTION
void HashTable::rehash() {
    cout << "\nRehashing started... Increasing table size\n";

    int oldSize = size;
    Node** oldTable = table;

    size = size * 2;
    table = new Node*[size];
    count = 0;

    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }

    // reinsert old data
    for (int i = 0; i < oldSize; i++) {
        Node* temp = oldTable[i];

        while (temp != NULL) {
            insert(temp->name, temp->phone);
            temp = temp->next;
        }
    }

    cout << "Rehashing completed! New size = " << size << endl;
}

// INSERT
void HashTable::insert(string name, string phone) {
    int index = hashFunction(name);

    Node* temp = table[index];

    // duplicate check
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Contact already exists!\n";
            return;
        }
        temp = temp->next;
    }

    Node* newNode = new Node(name, phone);
    newNode->next = table[index];
    table[index] = newNode;

    count++;

    cout << "Contact added successfully!\n";

    // 🔥 check load factor
    if (loadFactor() > 0.75) {
        rehash();
    }
}

// SEARCH
void HashTable::search(string name) {
    int index = hashFunction(name);

    Node* temp = table[index];

    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Found: " << temp->name << " -> " << temp->phone << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Contact not found!\n";
}

// DELETE
void HashTable::deleteContact(string name) {
    int index = hashFunction(name);

    Node* temp = table[index];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->name == name) {

            if (prev == NULL) {
                table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            count--;

            cout << "Contact deleted!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Contact not found!\n";
}

// DISPLAY
void HashTable::display() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ":\n";

        Node* temp = table[i];

        while (temp != NULL) {
            cout << "  " << temp->name << " -> " << temp->phone << endl;
            temp = temp->next;
        }
    }
}

// FILE LOAD
void HashTable::loadFromFile() {
    ifstream file("contacts.txt");

    string name, phone;

    while (file >> name >> phone) {
        insert(name, phone);
    }

    file.close();
}