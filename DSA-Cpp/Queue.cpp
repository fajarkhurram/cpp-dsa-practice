# include <iostream>
using namespace std;

class Node{
public :
    Node* next ;
    int data;

    Node(int value){
        next = NULL;
        data = value;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if(!empty()){
            tail->next = newNode;
            tail = newNode;
            cout<< "Inserted" << endl;
            return;
        }else{
            head = tail = newNode;
            cout<< "Inserted" << endl;
        }
        
    }

    void dequeue(){
        if(empty()){
           cout << "Linked List is empty" << endl;
           return;
        }
        else{
            Node* curr = head;
            head = head->next;
            delete curr;
        }

    }

    int front(){
        if(empty()){
           cout << "Linked List is empty" << endl;
           return -1;
        }
        else{
            return head->data;
        }
    }

    bool empty(){
        return head == NULL;
    }

    void display(){
        if(empty()){
           cout << "Linked List is empty" << endl;
           return ;
        }

        Node* curr = head;
        while(curr != NULL){
            cout << curr->data << "->" ;
            curr = curr->next;
        }
        cout << "NULL";
    }
};
int main()
{
    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                value = q.front();
                if(value != -1)
                    cout << "Front element is: " << value << endl;
                break;

            case 4:
                q.display();
                cout << endl;
                break;

            case 5:
                if(q.empty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while(choice != 6);

    return 0;
}
