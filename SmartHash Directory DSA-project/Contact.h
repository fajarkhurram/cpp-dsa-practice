#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string phone;
    Node* next;

    Node(string n, string p) {
        name = n;
        phone = p;
        next = NULL;
    }
};

#endif