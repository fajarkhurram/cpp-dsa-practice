#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = -1;
        next = NULL;
    }

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node HT[10];

void insert(int value)
{
    int index = value % 10;

    if (HT[index].data == -1)
    {
        HT[index].data = value;
    }

    else
    {
        Node *newNode = new Node(value);
        Node *curr = HT[index].next;
        if (curr == NULL)
        {

            HT[index].next = newNode;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
}

void search(int value)
{
    int index = value % 10;

    if(HT[index].data == -1){
        cout << "value not found" << endl;
        return;
    }

    if (value == HT[index].data)
    {
        cout << "Value found at index" << index << endl;
        return;
    }
    if (HT[index].next != NULL)
        {
            Node *curr = HT[index].next;
            while (curr != NULL)
            {
                if (value == curr->data)
                {
                    cout << "Value found at index " << index << endl;
                    return;
                    
                }
                curr = curr->next;
            }
        }
         cout << "Value not found" << endl;
}
    


void display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << HT[i].data << "->";
        if (HT[i].next != NULL)
        {
            Node *curr = HT[i].next;
            while (curr != NULL)
            {
                cout << curr->data << "->";
                curr = curr->next;
            }
        }
        cout << "NULL" << endl;
    }
}
int main()
{
    insert(15);
    insert(25);
    insert(35);
    insert(135);
    insert(7);
    insert(17);

    display();

    search(45);
    search(135);
}
