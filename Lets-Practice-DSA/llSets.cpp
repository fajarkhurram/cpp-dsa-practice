#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    // Insert at end
    void insert(Node *head, int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Merge two sorted lists
    Node *merge(Node *head1, Node *head2)
    {
        Node *head3 = NULL;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                insert(head3, head1->data);
                head1 = head1->next;
            }
            else
            {
                insert(head3, head2->data);
                head2 = head2->next;
            }
        }

        // Copy remaining nodes of List1
        while (head1 != NULL)
        {
            insert(head3, head1->data);
            head1 = head1->next;
        }

        // Copy remaining nodes of List2
        while (head2 != NULL)
        {
            insert(head3, head2->data);
            head2 = head2->next;
        }

        return head3;
    }

    void customInsert(Node *head, int item1, int item2)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == item1)
            {
                Node *newNode = new Node(item2);

                newNode->next = temp->next;
                temp->next = newNode;

                temp = newNode; // Skip the inserted node
            }

            temp = temp->next;
        }
    }

    Node *Union(Node *head1, Node *head2)
    {
        Node *head3 = NULL;

        Node *temp = head1;

        // Copy all elements of List1
        while (temp != NULL)
        {
            if (!search(head3, temp->data))
                insert(head3, temp->data);

            temp = temp->next;
        }

        // Copy only unique elements from List2
        temp = head2;

        while (temp != NULL)
        {
            if (!search(head3, temp->data))
                insert(head3, temp->data);

            temp = temp->next;
        }

        return head3;
    }

    Node *Intersection(Node *head1, Node *head2)
    {
        Node *head3 = NULL;

        Node *temp1 = head1;

        while (temp1 != NULL)
        {
            Node *temp2 = head2;

            while (temp2 != NULL)
            {
                if (temp1->data == temp2->data)
                {
                    if (!search(head3, temp1->data))
                        insert(head3, temp1->data);

                    break;
                }

                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }

        return head3;
    }

    Node *Difference(Node *head1, Node *head2)
    {
        Node *head3 = NULL;

        Node *temp1 = head1;

        while (temp1 != NULL)
        {
            Node *temp2 = head2;
            bool found = false;

            while (temp2 != NULL)
            {
                if (temp1->data == temp2->data)
                {
                    found = true;
                    break;
                }

                temp2 = temp2->next;
            }

            if (found == false)
            {
                insert(head3, temp1->data);
            }

            temp1 = temp1->next;
        }

        return head3;
    }

    // Display
    void display(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }

        cout << endl;
    }
};
int main()
{
    Node *head1 = NULL, *head2 = NULL;

    // Sorted List1
    insert(head1, 1);
    insert(head1, 3);
    insert(head1, 5);
    insert(head1, 8);

    // Sorted List2
    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 6);
    insert(head2, 7);

    cout << "List 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    Node *head3 = merge(head1, head2);

    cout << "Merged List: ";
    display(head3);

    return 0;
}