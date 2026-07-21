#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Contact.h"

class HashTable {
private:
    Node** table;
    int size;
    int count;

public:
    HashTable(int s = 10);

    int hashFunction(string name);

    void insert(string name, string phone);
    void search(string name);
    void deleteContact(string name);
    void display();

    void loadFromFile();

    float loadFactor();
    void rehash();   // 🔥 NEW
};

#endif