#include <iostream>
using namespace std;

const int TABLE_SIZE = 11; // prime number to avoid skipping
int hashTable[TABLE_SIZE];

//  Initialize table
void initialize() {
    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1; 
}


int hashFunc(int key) {
    return key % TABLE_SIZE;
}

//  Insert with quadratic probing
void insert(int key) {
    int index = hashFunc(key);

    if(hashTable[index] == -1) { // first slot free
        hashTable[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
        return;
    }

    // collision -> quadratic probing
    for(int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i*i) % TABLE_SIZE;
        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            cout << "Inserted " << key << " at index " << newIndex << endl;
            return;
        }
    }

    cout << "Table full! Cannot insert " << key << endl;
}

// Search with quadratic probing
bool search(int key) {
    int index = hashFunc(key);

    if(hashTable[index] == key)
        return true;

    for(int i = 1; i < TABLE_SIZE; i++) {
        int newIndex = (index + i*i) % TABLE_SIZE;

        if(hashTable[newIndex] == key)
            return true;

        if(hashTable[newIndex] == -1)
            return false; 
    }

    return false;
}


void display() {
    cout << "Hash Table: ";
    for(int i = 0; i < TABLE_SIZE; i++)
        cout << hashTable[i] << " ";
    cout << endl;
}

int main() {
    initialize();

    int choice, key;

    do {
        cout << "\n----- HASH TABLE MENU -----\n";
        cout << "1. Insert a number\n";
        cout << "2. Search a number\n";
        cout << "3. Display table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Enter number to search: ";
                cin >> key;
                if(search(key))
                    cout << key << " found in table!\n";
                else
                    cout << key << " not found in table!\n";
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);

    return 0;
}
