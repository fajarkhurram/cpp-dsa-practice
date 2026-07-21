# include <iostream>
using namespace std;

class Heap {
    int size;
    int capacity;
    int *arr;

public:

    Heap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        arr = new int [capacity];
        
    }

    void insert(int value){
        if(size == capacity){
            cout << "Heap full" << endl;
            return;
        }

        arr[size] = value;
        upHeapify(size);
        size++;

    }

    void upHeapify(int index){

        while(index > 0){
            int parent = (index -1)/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    int search(int value){
        if(size == 0){
            cout << "value not found" << endl;
            return -1;
        }

        for(int i = 0 ; i < size ; i++){
            if( value == arr[i]){
                cout << "value found at index " << i << endl;
                return i;
            }
        }
        cout << "value not found" << endl;
        return -1 ;

    }

    void display(){
        if(size == 0){
            cout << "heap empty" << endl;
            return ;
        }
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] <<" " ;
        }

        cout << endl;
    }

    void Delete(){
        if(size==0)
    {
    cout<<"Heap Empty";
    return;
    }
        int root = 0;

        swap(arr[root] , arr[size-1]);
        size--;
        downHeapify(0);
    }

    void downHeapify(int index){
        while(index < size){
        int left = index*2 +1;
        int right = index*2 +2;

        int largest = index ;

        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]){ // if child exist and woh bara hai largest sy
            largest = right;
        }

        if (largest == index){
            break;
        }

        swap(arr[index], arr[largest]);
        index = largest;

    }

    }

    void heapSort(){
        int originalSize = size;
        while (size > 1){
            swap(arr[0] , arr[size-1]);
            size--;
            downHeapify(0);
        }
        size = originalSize;
    }
};



int main()
{
    Heap 
    h(10);
    h.insert(90);
    h.insert(80);
    h.insert(70);
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.display();

    h.search(10);
    h.search(20);

    h.Delete();
    h.display();

    h.heapSort();
    h.display();

    

    return 0;
}