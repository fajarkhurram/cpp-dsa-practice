# include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int value){
        //create a new node
        Node* newNode = new Node(value);
        if( head == NULL){      //if list is empty
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head; //establishing a connection
            head = newNode; //updating head pointer
            tail -> next = head; 
        }
    }
    //deleting first node
    void pop_front(){
        if(head == NULL){
            cout << "The Linked List is empty" << endl;
            return;
        }
        // only one node
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        else{
            Node* temp = head;  //assign head into temp
            head = head->next;  // update head before deleting
            temp->next = NULL;  
            delete temp;
            tail->next = head;
        }

    }
    

    void insert(int value, int position){
        if (position < 0){
            cout << "Invalid position" << endl;
            return;
        }
        if(position == 0){
            push_front(value);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position-1; i++)
        {
            if(temp == NULL){
                cout<< "Invalid Index" << endl;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key){
        Node* temp = head;
        int i = 0;
        do{
            if(key == temp->data){
                cout << key << " found at index ";
                return i;
            }
            temp = temp->next;
            i++; 
        } while (temp != head);
        
        return -1;   
    }

    void deleteNode(int value){
        Node* temp = head;
        if(head == NULL){
            cout << "The list is empty" << endl;
            return;
        }
        if(value == head->data){
            pop_front();
            return;
        }
        temp = head->next;
        Node* prev = head;
        do{
            if(value == temp->data){
                prev->next = temp->next; //connection establish
                delete(temp);
                return;
            }
            temp = temp->next;
            prev= prev->next;
        }while(temp != head);
    
    }
    void print_LL(){
        Node* temp = head;
        if(head == NULL){
        cout << "List is empty" << endl;
        return;
        }
        do{
            cout << temp->data <<"->"; //printing temperoroy node's data
            temp = temp->next;        // updatre temperory to next node's pointer
        }while(temp != head);
        cout << endl;
    }
     void print_recursive_LL(Node * head , Node * curr){
         if( curr->next == head){
            cout << curr->data << "->";
         }
         cout << curr->data << "->";
         print_recursive_LL(head, curr->next);
        }
};


int main()
{
    List ll;
    bool flag = true;
    while(flag){
        int choices ;
        cout << "Enter the function number you want to perform:" << endl;
        cout << "1) insert numbers \n2)insert numbers at specific positon \n3)delete a node \n4)search \n5)display \n6)exit ";
        cin >> choices;
        int num;

        switch (choices)
        {
        case 1:
            cout << "Enter the number" <<  endl;
            cin>> num;
            ll.push_front(num);
            break;
        case 2:
            cout << "Enter the number" <<  endl;
            cin>> num;
            cout << "Enter position" << endl;
            int position; 
            cin >> position;
            ll.insert(num, position);
            break;
        case 3:
            cout << "Enter the number you want to delete" <<  endl;
            cin>> num;
            ll.deleteNode(num);
            break;
        case 4:
            cout << "Enter the number" <<  endl;
            cin>> num;
            cout << ll.search(num) << endl;
            break;
        case 5:
            cout << "Resulting array" <<  endl;
            ll.print_LL();
            break;
        case 6:
            cout << "Program ended" <<  endl;
            cout << "==============" <<  endl;
            flag = false;
        
            break;
        
        default:
            break;
        }




    }
    return 0;
}