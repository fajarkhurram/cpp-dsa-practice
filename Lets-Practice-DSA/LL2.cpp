# include <iostream>
using namespace std;
class Node{
    public:
     int data;
     int next;
    Node(int data){
        data = data;
        next = NULL;
    }
};


class LL{

public:
    Node* head;

    LL(){
        head = NULL;
    }



    Node* create_ll(string data){
        Node* head = NULL;

        for(int i = 0 ; i < data.length ; i++){
            int digit = data[i] -'0';

            Node newNode = new Node(digit);

            newNode->next = head;
            head = newNode;
        }
        return head;
    }

}



int main()
{


    

    return 0;
}