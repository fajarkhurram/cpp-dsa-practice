#include <iostream>
using namespace std;

// Node class
class Node {
public:
    char data;
    Node* next;
};

// Stack for CHAR (infix to postfix)
class CharStack {
    Node* top;
public:
    CharStack() {
        top = NULL;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) return '\0';

        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    char peek() {
        if (top == NULL) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

// Stack for DOUBLE (evaluation)
class DNode {
public:
    double data;
    DNode* next;
};

class DoubleStack {
    DNode* top;
public:
    DoubleStack() {
        top = NULL;
    }

    void push(double value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    double pop() {
        if (top == NULL) return 0;

        DNode* temp = top;
        double value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

// helper functions
bool isOperand(char op){
    if((op >= '0' && op <= '9') ||
       (op >= 'A' && op <= 'Z') ||
       (op >= 'a' && op <= 'z')){
        return true;
    }
    return false;
}

int precedence(char chr){
    if(chr == '+' || chr == '-') return 1;
    if(chr == '*' || chr == '/') return 2;
    return 0;
}

// postfix evaluation
double postfix_evaluation(string postfix){
    DoubleStack s;

    for(int i = 0; i < postfix.length(); i++){

        if(postfix[i] >= '0' && postfix[i] <= '9'){
            s.push(postfix[i] - '0');
        }

        else if(postfix[i] >= 'a' && postfix[i] <= 'z'){
            double value;
            cout << "Enter value for " << postfix[i] << " : ";
            cin >> value;
            s.push(value);
        }
    }
        for(int i = 0 ; i < postfix.length(); i++){

            if(isOperand(postfix[i])){
            double val1 = s.pop();
            double val2 = s.pop();

            if(postfix[i] == '+')
                s.push(val2 + val1);

            else if(postfix[i] == '-')
                s.push(val2 - val1);

            else if(postfix[i] == '*')
                s.push(val2 * val1);

            else if(postfix[i] == '/')
                s.push(val2 / val1);
        }
    }

    return s.pop();
}

int main()
{
    string infix ="a+b*c/d-(x*y+(5*d-a)*y)";
    string postfix = "";

    CharStack s;

    for (int i = 0; i < infix.length(); i++)
    {
        if(isOperand(infix[i])){
            postfix += infix[i];
        }

        else if(infix[i] == '('){
            s.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix += s.pop();
            }
            s.pop(); // remove '('
        }

        else{
            while(!s.isEmpty() && precedence(infix[i]) <= precedence(s.peek())){
                postfix += s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.isEmpty()){
        postfix += s.pop();
    }

    cout << "Postfix: ";
    for (int i = 0; i < postfix.length(); i++)
    {
        cout << postfix[i];
    }

    cout << endl;

    double result = postfix_evaluation(postfix);
    cout << "Result: " << result << endl;

    return 0;
}