#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
    Node* top; // pointer to top of stack
public:
    Stack() {
        top = NULL; // initially stack is empty
    }

    // PUSH function: add element at top
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; // link new node to current top
        top = newNode;       // update top
        cout << value << " pushed to stack." << endl;
    }

    // POP function: remove element from top
    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow! No element to pop." << endl;
            return -1;
        }

        Node* temp = top;       // store top node
        int poppedValue = top->data;
        top = top->next;        // move top to next node
        delete temp;            // free memory
        cout << poppedValue << " popped from stack." << endl;
        return poppedValue;
    }

    // DISPLAY stack from top to bottom
    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* curr = top;
        cout << "Stack : ";
        while (curr != NULL) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function with menu
int main() {
    Stack s;

    bool flag = true;
    while (flag) {
        int choice, value;
        cout << "\nEnter function number to perform:" << endl;
        cout << "1) PUSH\n2) POP\n3) DISPLAY STACK\n4) EXIT\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Program ended." << endl;
                flag = false;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
