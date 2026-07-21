# include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = next = NULL;
    }
};

class Doubly_ll{
public :
    Node* head ;
    Node* tail;


    Doubly_ll(){
        head = tail = NULL;
    }

    void push_front(int value){
        Node* newNode = new Node( value);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert(int value , int position){
        Node* newNode = new Node(value);
        if(position < 0){
            cout << "invalid position" << endl;
            return;
        }
        if(position == 0){
            push_front(value);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < position-1 && curr!=NULL; i++)
        {
           curr = curr->next;
        }
        if(curr == NULL){
            return;
        }
        newNode->next = curr->next;
         
        if(curr->next != NULL){
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
        
    }
    void pop_front(){
        if(head == NULL){
            cout << "Double Linked List is empty"<< endl;
            return ;
        }
        Node* curr = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        curr->next = NULL;
        delete curr;
    }

    void pop_back(){
        if(head == NULL){
            cout << "Double Linked List is empty"<< endl;
            return ;
        }
        Node* curr = tail;
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL;
        }
        curr->prev = NULL;
        delete curr;
    }

    

    void delete_Node(int value){
        if(head == NULL){
            cout << "Double Linked List is empty"<< endl;
            return ;
        }
        if(value == head->data){
            pop_front();
            return;
        }
        Node* curr = head->next;
        
        
        while(curr != NULL){
            if(curr->data == value){
                curr->prev->next = curr->next;
                if(curr->next != NULL){
                    curr->next->prev = curr->prev;
                    
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void search_node(int value){
        if(head == NULL){
            cout << "Double Linked List is empty"<< endl;
            return ;
        }
        Node* curr = head;
        for (int i = 0; curr != NULL; i++)
        {
            if(value == curr->data){
                cout << "Value found at index " << i << endl;
                return;
            }
            curr = curr->next;
        }
        if(curr == NULL){
            cout << "Value not found" << endl;
        }
    }

    void display(Node * head){
        if(head == NULL){
            return;
        }
        cout << head->data << " <=> ";
        display(head->next);
    }

    void reverse()
    {
        Node *temp = NULL;
        Node *curr = head;

        // Swap next and prev of every node
        while(curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to next node
            curr = curr->prev;
        }

        // Change head to last node
        if(temp != NULL)
            head = temp->prev;
    }

    //================ FIND MINIMUM =================
    int findMin()
    {
        // If list is empty
        if(head == NULL)
        {
            cout << "List is Empty";
            return -1;
        }

        Node *temp = head;

        // Assume first node is minimum
        int min = temp->data;

        // Traverse the list
        while(temp != NULL)
        {
            if(temp->data < min)
                min = temp->data;

            temp = temp->next;
        }

        return min;
    }


        //================ FIND MAXIMUM =================
    int findMax()
    {
        // If list is empty
        if(head == NULL)
        {
            cout << "List is Empty";
            return -1;
        }

        Node *temp = head;

        // Assume first node is maximum
        int max = temp->data;

        // Traverse the list
        while(temp != NULL)
        {
            if(temp->data > max)
                max = temp->data;

            temp = temp->next;
        }

        return max;
    }
};
int main()
{
    
    Doubly_ll ll;

    cout << "---- Push Front ----" << endl;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    ll.display(ll.head);
    cout << endl << endl;

    cout << "---- Push Back ----" << endl;
    ll.push_back(40);
    ll.push_back(50);

    ll.display(ll.head);
    cout << endl << endl;

    cout << "---- Insert at Position 2 ----" << endl;
    ll.insert(25, 2);

    ll.display(ll.head);
    cout << endl << endl;

    cout << "---- Search 40 ----" << endl;
    ll.search_node(40);
    cout << endl;

    cout << "---- Delete 25 ----" << endl;
    ll.delete_Node(25);

    ll.display(ll.head);
    cout << endl << endl;

    cout << "---- Pop Front ----" << endl;
    ll.pop_front();
    ll.display(ll.head);
    cout << endl << endl;

    cout << "---- Pop Back ----" << endl;
    ll.pop_back();
    ll.display(ll.head);
    cout << endl;

    return 0;
}

   