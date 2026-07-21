# include <iostream>
using namespace std;



void merge(int arr[], int left , int mid , int right){
    int temp [right - left +1];
    int i = left ;
    int j = mid + 1;
    int k = 0 ;

    //comparing

    while(i <= mid && j <= right){

        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    //adding the remaining from left
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    //adding the remaining from right
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    //copying elements from temp to origiunal array

    for (int i = 0 ; i < (right - left+1) ; i++){
        arr[i+left] = temp[i];
    }

}

void merge_sort(int arr[], int left , int right){

    if(left < right){
    int mid = left +(right-left)/2;
    merge_sort(arr, left , mid);
    merge_sort(arr, mid+1 , right);
    merge(arr, left ,mid , right);

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

    int arr [] = {11,51,18,17,22,52,78,45,92,85,11,12};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Array before sorting" << endl;
    printArray(arr, size );
    merge_sort(arr, 0 , size-1 );
    cout << "\nArray after sorting" << endl;
    printArray(arr, size );


    return 0;
}