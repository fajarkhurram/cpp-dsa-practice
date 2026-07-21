# include <iostream>
using namespace std;

class CircularQueue{
    int arr* ;
    int capacity;
    int currSize ;
    int front;
    int rear;

public:

    CircularQueue(int size){
        capacity = size;
        arr = new int [capacity];
        currSize = 0;
        front = 0 ;
        rear= -1;
    }

    void push(int data){
        if(full()){
            cout << "Array is full" << endl;
            return;
        }

        rear = (rear + 1)% capacity ; // capacity = 3 ;  rear will always give me 0 , 1, 2,
        arr[rear] = data ;
        currSize ++;
    }

    void pop(){
        if(empty()){
            cout << "Array is empty " << endl;
            return;
        }

        front = (front + 1)% capacity;
        currSize--;
    }

    int getFront(){
         if(empty()){
            cout << "Array is empty " << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        return currSize == 0;
    }

    bool full(){
        return currSize == capacity;
    }

    void display(){
        if(empty()){
            cout << "Array is empty " << endl;
            return ;
        }

        int position = front;
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[position] << " ";
            position = (position + 1) % capacity;
        }
    }

};

int main()
{
    int size;
    cout << "Enter size of Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);

    int choice, value;

    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Push (Enqueue)" << endl;
        cout << "2. Pop (Dequeue)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                cq.push(value);
                break;

            case 2:
                cq.pop();
                break;

            case 3:
                value = cq.getFront();
                if(value != -1)
                    cout << "Front element is: " << value << endl;
                break;

            case 4:
                cq.display();
                cout << endl;
                break;

            case 5:
                if(cq.empty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;

            case 6:
                if(cq.full())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 7);

    return 0;
}

