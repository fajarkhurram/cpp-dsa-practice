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
        }
    }

    void push_back(int value){
        //create a new node
        Node* newNode = new Node(value);
        if( head == NULL){      //if list is empty
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode; //establishing a connection (IMP TO FOCUS)
            tail = newNode; //updating head pointer
        }
    }
    //deleting first node
    void pop_front(){
        if(head == NULL){
            cout << "The Linked List is empty" << endl;
            return;
        }else{
            Node* temp = head;  //assign head into temp
            head = head->next;  // update head before deleting
            temp->next = NULL;  
            delete temp;
        }

    }
    //deleting last node
    void pop_back(){
        if(head == NULL){
            cout << "The Linked List is empty" << endl;
            return;}
        else{
            Node* temp = head;
            while(temp->next != tail){ // previous mae tail ka adress huga
                temp = temp-> next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
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
       
    }

    void deleteNode(int value){
        Node* temp = head;
        if(head == NULL){
            cout << "The list is empty" << endl;
            return;
        }
        if(value == head->data){
            pop_front();
        }
        if(value == tail->data){
            pop_back();
        }
        temp = head->next;
        Node* prev = head;
        while(temp != NULL){
            if(value == temp->data){
                prev->next = temp->next; //connection establish
                free(temp);
                return;
            }
            temp = temp->next;
            prev= prev->next;
        }
    
    }
    void print_LL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<"->"; //printing temperoroy node's data
            temp = temp->next;        // updatre temperory to next node's pointer
        }
        cout << "NULL"<< endl;
    }

    void recursive_display(Node* head)
        {
    if(head == NULL)
        return;

    cout << head->data << "->";
    recursive_display(head->next);
    cout << "NULL";
    }

    void recursive_reverseDisplay(Node* head)
        {
    if(head == NULL)
        return;
        
    recursive_reverseDisplay(head->next);
    cout << head->data << "->";
    }


    // Insert node using last digit of number as position
void insertNth(int value, int number)   //VALUE IS THE DATA TO BE INSERTED, NUMBER IS USED TO FIND THE POSITION
{
   
    int n = number % 10;

    // Create new node
    Node* newNode = new Node(value);

    int count = 0;
    Node* temp = head;

    // Count total nodes in the list
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // If list has fewer than n nodes
    if(count < n)
    {
        // Odd value -> insert at beginning
        if(value % 2 != 0)
        {
            newNode->next = head;
            head = newNode;
        }
        // Even value -> insert at end
        else
        {
            insertEnd(value);
        }

        return;
    }

    // Move back to head
    temp = head;

    // Reach the nth node
    for(int i = 1; i < n; i++)
    {
        temp = temp->next;
    }

    // Insert new node after nth node
    newNode->next = temp->next;
    temp->next = newNode;
}


    void reverseDisplay()
    {
        Node* temp = head;
        while(temp)
    {
        arr[i]=temp->data;
        i++;
        temp=temp->next;
    }
    }

    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j]<<" ";
    }
};


int main()
{
    List ll;
    bool flag = true;
    while(flag){
        int choices ;
        cout << "Enter the function number you want to perform:" << endl;
        cout << "1) insert numbers to the right\n2) insert numbers to the left \n3)insert numbers at specific positon \n4)delete a node \n5)search \n6)display \n7)exit ";
        cin >> choices;
        int num;

        switch (choices)
        {
        case 1:
            cout << "Enter the number" <<  endl;
            cin>> num;
            ll.push_back(num);
            break;
        case 2:
            cout << "Enter the number" <<  endl;
            cin>> num;
            ll.push_front(num);
            break;
        case 3:
            cout << "Enter the number" <<  endl;
            cin>> num;
            cout << "Enter position" << endl;
            int position; 
            cin >> position;
            ll.insert(num, position);
            break;
        case 4:
            cout << "Enter the number you want to delete" <<  endl;
            cin>> num;
            ll.deleteNode(num);
            break;
        case 5:
            cout << "Enter the number" <<  endl;
            cin>> num;
            cout << ll.search(num) << endl;
            break;
        case 6:
            cout << "Resulting array" <<  endl;
            ll.print_LL();
            break;
        case 7:
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