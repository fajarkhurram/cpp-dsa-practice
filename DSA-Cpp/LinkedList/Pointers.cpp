#include <iostream>
using namespace std;

void changeA(int* ptr){  //pass by rerfrence using pointer
    *ptr = 20;
}

void changeA(int &b ){  //pass by rerfrence using alias
    b = 30;
}


int main() {
   /* 
    float a = 10.45; 
    float* pointer = &a;

    cout << pointer << endl;
    cout << &a << endl;

    //making pointer to pointer
    float** pointer2 = &pointer;
    cout << pointer2 << endl;

    //derefrencing (we are taking value stored at the address)
    cout << *(&a) << endl;
    cout << *(pointer) << endl;

    cout << *(*(pointer2))<< endl;*/

   /*// Pass by refrence 
    
    int a =  10;

    changeA(&a); 
    cout << a << endl;

    changeA(a);
    cout << a << endl;*/

    //Array Pointers

    // int arr[] = { 1, 2 , 3, 4, 5};

    // cout << arr << endl; // iska address
    // cout << *arr << endl; // pointer => 1


    //Pointer Arithmatic 

    int a = 10;
    int* ptr = &a;
    cout << ptr << endl;
    ptr++;
    cout << ptr << endl;

    int b = 13;
    int* ptr2 = &b;
    cout << ptr2 << endl;
    ptr2--;
    cout << ptr2 << endl;



    
    return 0;
}
