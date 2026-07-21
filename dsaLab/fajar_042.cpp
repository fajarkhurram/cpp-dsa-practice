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


public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }


    void insert(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
          //if list is empty
            head = tail = newNode;
            return;
        }

        tail->next = newNode; //establishing a connection (IMP TO FOCUS)
        tail = newNode; //updating head pointer
    }

    void recursive_insert(int value){
        
        if (value == -1)
        return;

        insert(value);
        cout << "Enter value you want to insert again enter -1 to stop"<< endl;
        cin >> value;
        recursive_insert(value);
    }

    void deleteNode(int value){
        Node* temp = head;
        bool flag = false;
        if(head == NULL){
            cout << "The list is empty" << endl;
            flag = false;
            return;
        }
        if(value == head->data){
            Node* temp = head;  //assign head into temp
            head = head->next;  // update head before deleting
            temp->next = NULL;  
            delete temp;
            flag = true;
            return;
        }
        if(value == tail->data){
            Node* temp = head;
            while(temp->next != tail){ // previous mae tail ka adress huga
                temp = temp-> next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
            flag = true;
            return;
        }
        temp = head->next;
        Node* prev = head;
        while(temp != NULL){
            if(value == temp->data){
                prev->next = temp->next; //connection establish
                free(temp);
                flag = true;
                return;
            }
            temp = temp->next;
            prev= prev->next;
        }

        if(flag == false){
            cout <<"data is not present in any node" << endl;
            return;
        }



    
    }


    void Delete_recursive(int key){
        if (key == -1){
        return;
    }

        deleteNode(key);
        cout << "Enter value you want to delete again enter -1 to stop"<< endl;
        cin >> key;

        Delete_recursive(key);
        
    }

    

    bool revsearch(int key , Node* head){
        if (head == NULL){
            return false ;
        }
        revsearch(key , head->next);
        if(head->data == key){
        cout << "found" << endl;
        return true;
        }
        else{
            cout << "not found" << endl;
        }
        return false;

    }


    void print_LL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<"->"; //printing temperoroy node's data
            temp = temp->next;        // updatre temperory to next node's pointer
        }
        cout << "NULL"<< endl;
    }

};

int main()
{
    List l;
    int key;
    cout << "enter key you want to insert " << endl;
    cin >> key;
    cout << endl;
    l.recursive_insert(key);
    cout << "AFTER INSERTION" << endl;
    l.print_LL();
    cout << "enter key you want to delete " << endl;
    cin >> key;
    cout << endl;

    l.Delete_recursive(key);
    cout << "After deletion" << endl;
    l.print_LL();
    cout << "enter key you want to search " << endl;
    cin >> key;
    cout << endl;
    
    l.revsearch(key, l.head);

    return 0;
}