# include <iostream>
using namespace std;

void BubbleSort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false){ //array is sorted no swaping has take place
            return;
        }
        
    }

}

void SelectionSort(int arr[], int n){

    for(int i = 0 ; i < n-1 ; i++){
        int smallestIdx = i; //unsorted partstarting(assuming it is the smallest number)

        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestIdx];
        arr[smallestIdx] = temp;
    }
}

void InsertionSort(int arr[] , int n){

    for (int i = 1; i < n ; i++) //starting from the second element assuming first element is sorted
    {
        int current = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > current){
            arr[prev+1] = arr[prev];
            prev--; //reducing to check and comnpare all the previous elements
        }

        arr[prev+1] = current;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
}


int main()
{

    int arr[10] = {17, 95, 83, 74, 77, 77, 12, 75, 63, 85};
    InsertionSort(arr,10);

    cout<< "Sorted Array" << endl;
    printArray(arr,10);

    return 0;
}