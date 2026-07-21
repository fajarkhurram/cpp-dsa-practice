# include <iostream>
using namespace std;
#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    char data;
    Node* next;
};

// Stack class using linked list
class Stack {
    Node* top; // pointer to top of stack
public:
    Stack() {
        top = NULL; // initially stack is empty
    }

    // PUSH function: add element at top
    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; // link new node to current top
        top = newNode;       // update top
        
    }

    // POP function: remove element from top
    char pop() {
        if (top == NULL) {
            cout << "Stack Underflow! No element to pop." << endl;
            return 0;
        }

        Node* temp = top;       // store top node
        char poppedValue = top->data;
        top = top->next;        // move top to next node
        delete temp;            // free memory
        
        return poppedValue;
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        return false;
    }

    char peek(){
        if(isEmpty()){
            return 0;
        }
        return top->data;
    }


    // DISPLAY stack from top to bottom
    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* curr = top;
        cout << "Stack : ";
        while (curr != NULL) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

    bool isOperand(char op){
        if((op >= '0' && op <= '9' )   || (op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z')){
            return true;
        }
            return false;           
    }

    int precedence(char chr){
        if(chr == '|') return 1;
        if(chr == '&') return 2;
        if(chr == '>' || chr == '<') return 3;
        if(chr == '=' || chr == '!') return 4;
        if(chr == '+' || chr == '-') return 5;
        if(chr == '*'|| chr == '/' || chr == '%') return 6;

        return -1;
    }

int main()
{
    string infix ="a+b/d<5+a*b";
    string postfix = ""; int k = 0; 
    Stack s;

    for (int i = 0; i < infix.length(); i++)
    {
        if(isOperand(infix[i])){
            postfix += infix[i];
        }

        else if(s.isEmpty()){
            s.push(infix[i])  ;
        }

        else if(infix[i] == '('){
            s.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(!s.isEmpty() && s.peek() !='('){
                char chr = s.pop();
                postfix += chr;   
            }
            s.pop();
        }

        else if(precedence(infix[i]) >= precedence(s.peek())){
            s.push(infix[i]);
        }

        else if(!s.isEmpty() && precedence(infix[i]) <= precedence(s.peek())){
            while(precedence(infix[i]) <= precedence(s.peek())){
                postfix += s.pop();
                
            }
            s.push(infix[i]);
        }

    }
    while(!s.isEmpty()){
    postfix += s.pop();
}

    for (int i = 0; i < postfix.length(); i++)
    {
        cout << postfix[i] ;
    }

    

    return 0;
}