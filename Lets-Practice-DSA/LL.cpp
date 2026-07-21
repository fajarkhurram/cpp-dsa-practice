#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class List
{
public:
    Node *head;

    List()
    {
        head = NULL;
    }

    void insert_at_start(int value)
    {
        Node *newNode = new Node(value);
        // if my list is empty
        if (head == NULL)
        {
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;
            return;
        }
        // I want to insert at start
        else
        {
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void insert(int position, int value)
    {

        if (position < 0)
        {
            cout << "Invalid position !";
            return;
        }

        if (position == 0)
        {
            insert_at_start(value);
            return;
        }

        else
        {
            Node *newNode = new Node(value);
            Node *curr = head;
            for (int i = 0; i < position - 1; i++)
            {
                if (curr == NULL)
                {
                    return;
                }
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    int search(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return -1;
        }

        Node *curr = head;
        int i = 0;
        while (curr != NULL)
        {

            if (curr->data == value)
            {
                cout << value << " found at index " << i << endl;
                return i;
            }

            curr = curr->next;
            i++;
        }

        cout << value << " not found!" << endl;
        return -1;
    }

    void delete_node(int value)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY " << endl;
            return;
        }

        Node *curr = head;
        if (value == head->data)
        {
            head = head->next;
            delete curr;
            return;
        }

        curr = curr->next;
        Node *prev = head;

        while (curr != NULL)
        {
            if (value == curr->data)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }

            curr = curr->next;
            prev = prev->next;
        }
    }

    int search_multiple_occ(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return -1;
        }

        Node *curr = head;
        int i = 0;
        int count = 0;
        while (curr != NULL)
        {

            if (curr->data == value)
            {
                cout << value << " found at index " << i << endl;
                count++;
            }

            curr = curr->next;
            i++;
        }
        if (count == 0)
        {
            cout << value << " not found!" << endl;
            return -1;
        }

        return count;
    }

    void unique_insert(int position, int value)
    {
        int appearence = search(value);

        if (appearence == -1)
        {
            insert(position, value);
            cout << value << " inserted at position " << position << endl;
        }

        else
        {
            cout << "Already exsist!" << endl;
        }
    }

    void sorted_insert(int value)
    {
        Node *newNode = new Node(value);

        // Empty list or value smaller than head
        if (head == NULL || value <= head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Find the proper position
        Node *curr = head;
        while (curr->next != NULL && curr->next->data < value)
        {
            curr = curr->next;
        }

        // Insert after curr
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void sorted_unique_insertion(int value)
    {

        if (search(value) != -1)
        {
            cout << "Value already exist" << endl;
            return;
        }

        else
        {
            sorted_insert(value);
            cout << "Value inserted" << endl;
        }
    }

    void delete_multiple_occ(int value)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY " << endl;
            return;
        }

        Node *curr = head;
        if (value == head->data)
        {
            head = head->next;
            delete curr;
        }

        curr = curr->next;
        Node *prev = head;

        while (curr != NULL)
        {
            if (value == curr->data)
            {
                prev->next = curr->next;
                delete curr;
            }

            curr = curr->next;
            prev = prev->next;
        }
    }

    // void display(){
    //     Node* curr = head;

    //     while(curr != NULL){
    //         cout << curr->data << "->";
    //         curr = curr->next;
    //     }
    //     cout << "NULL" ;
    // }

    void display(Node *head)
    {
        Node *curr = head;
        if (curr == NULL)
        {
            return;
        }
        cout << head->data << "->";
        display(head->next);
    }

    void recursive_display(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        recursive_display(head->next);
        cout << head->data << "->";
    }

    List Union(Node *head1, Node *head2)
    {
        List result = new List();

        Node *temp1 = head1;
        while (temp1 != NULL)
        {
            result.insert_at_start(temp1->data);
            temp1 = temp1->next;
        }

        Node *temp2 = head2;

        while (temp2 != NULL)
        {
            Node *curr = result.head;
            bool found = false;
            while (curr != NULL)
            {
                if (temp2->data == curr->data)
                {
                    found = true;
                    break;
                }
                curr = curr->next;
            }
            if (!found)
            {
                result.insert_at_start(temp2->data);
            }
            temp2 = temp2->next;
        }
        return result;
    }

    List intersection(Node* head1 , Node* head2){
        List result = new List();

        Node* temp1 = head1;
        

        while(temp1 != NULL){
            Node* temp2 = head2;
            bool found = false;
            while(temp2 != NULL){
                if(temp1->data == temp2->data){
                    found = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if(found){
                result.insert_at_start(temp1->data);
            }
            temp1 = temp1->next;
        }
        return result;
    }

    void Customize_insert(int item1 , int item2 , Node *head){
        Node* temp = head;

        while(temp != NULL){
            if(temp->data == item1 ){
                Node* newNode = new Node(item2);
                newNode->next = temp->next;
                temp->next = newNode;

                temp = newNode;
            }
            temp = temp->next;
        }
    }


};

int main()
{
    List myList;
    int choice, value, position;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at position\n";
        cout << "3. Search for a value\n";
        cout << "4. Delete a value\n";
        cout << "5. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            myList.insert_at_start(value);
            break;

        case 2:
            cout << "Enter position to insert at: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            myList.insert(position, value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            myList.search(value);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            myList.delete_node(value);
            break;

        case 5:
            cout << "Current list: ";
            myList.display(myList.head);
            cout << endl;
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
