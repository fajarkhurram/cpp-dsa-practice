# include <iostream>
using namespace std;

int arr [] = {11,51,18,17,22,52,78,45,92,85,11,12};

int set_pivot(int left , int right){
    int p_idx = (left+right)/2;

    while (left < right){
        
            while(p_idx != right ){
                //right side loop
                if(arr[p_idx] > arr[right]){
                    swap(arr[p_idx], arr[right]);
                    p_idx = right;
                    break;
                }else{
                    right--;
                }
            }
            while(p_idx != left){
                //left side loop
                if(arr[p_idx] < arr[left]){
                    swap(arr[p_idx], arr[left]);
                    p_idx = left;
                    break;
                }else{
                    left++;
                }
            }
        }
       
     return p_idx;
    
}

void quick_Sort(int left, int right){
    if(left < right){
        int p_idx = set_pivot(left, right);
        quick_Sort(left,p_idx-1);
        quick_Sort(p_idx+1,right);
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

    int arr_size=sizeof(arr)/sizeof(arr[0]);
    cout<<arr_size;
    quick_Sort(0,arr_size-1);
    printArray(arr,arr_size);


    return 0;
}