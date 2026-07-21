#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert at End
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete Node
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->data != value)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        // Only Node
        if (head == tail)
        {
            delete temp;
            head = tail = NULL;
        }

        // First Node
        else if (temp == head)
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
        }

        // Last Node
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }

        // Middle Node
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Print List
    void print()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Count Nodes
    int countNodes()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Middle Node
    void middleNode()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle Node = " << slow->data << endl;
    }

    // Move Minimum to Front
    void moveMinToFront()
    {
       
    if (head == NULL || head->next == NULL)
        return;

    // Find minimum node
    Node* minNode = head;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data < minNode->data)
            minNode = temp;

        temp = temp->next;
    }

    // Move minimum to first
    swap(head->data, minNode->data);

    }

    // Move Maximum to End
    void moveMaxToLast()
    {
        // Find maximum node
    Node* maxNode = head;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data > maxNode->data)
            maxNode = temp;

        temp = temp->next;
    }

    // Find last node
    Node* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    // Move maximum to last
    swap(last->data, maxNode->data);
}
};

int main()
{
    DoublyLinkedList list;

    list.insert(40);
    list.insert(20);
    list.insert(80);
    list.insert(10);
    list.insert(60);

    cout << "Original List:\n";
    list.print();

    cout << "Total Nodes = " << list.countNodes() << endl;

    list.middleNode();

    list.moveMinToFront();

    cout << "\nAfter Moving Minimum to Front:\n";
    list.print();

    list.moveMaxToLast();

    cout << "\nAfter Moving Maximum to Last:\n";
    list.print();

    list.deleteNode(40);

    cout << "\nAfter Deleting 40:\n";
    list.print();

    return 0;
}