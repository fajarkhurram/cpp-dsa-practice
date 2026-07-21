#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node* next;

    Node()
    {
        data = -1;
        next = NULL;
    }

    Node(float value)
    {
        data = value;
        next = NULL;
    }
};

Node HT[10];

// Hash function for float
int hashFunc(float value)
{
    int temp = value * 100;  // convert float to int
    return temp % 10;
}

// Insert function
void insert(float value)
{
    int index = hashFunc(value);

    if (HT[index].data == -1)
    {
        HT[index].data = value;
    }
    else
    {
        Node* newNode = new Node(value);
        Node* curr = &HT[index];

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
}

// Search function
void search(float value)
{
    int index = hashFunc(value);
    Node* curr = &HT[index];

    while (curr != NULL)
    {
        if (curr->data == value)
        {
            cout << "Value Found at index " << index << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "Value Not Found\n";
}

// Display function
void display()
{
    cout << "\n--- HASH TABLE ---\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << " -> ";

        Node* curr = &HT[i];

        if (curr->data == -1)
        {
            cout << "NULL";
        }
        else
        {
            while (curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL";
        }

        cout << endl;
    }
}

// Main
int main()
{
    int choice;
    float value;

    do
    {
        cout << "\n--- FLOAT HASH TABLE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter float value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter float to search: ";
                cin >> value;
                search(value);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
