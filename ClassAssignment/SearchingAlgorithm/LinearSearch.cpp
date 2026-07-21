# include <iostream> 
using namespace std;

bool LinearSearch(int arr[],int size,  int toSearch ){ 
    
    for(int i = 0 ; i < size ; i++){
        if(toSearch == arr[i]){
            cout << toSearch<<" found at index "<< i<<endl;
            return true;
        }
    }
        cout << toSearch<<" not found at any index "<<endl;
        return false;
    
}

void LSForMulOcc(int arr[],int size,  int toSearch ){ 
    bool flag = false;
    for(int i = 0 ; i < size ; i++){
        if(toSearch == arr[i]){
            cout << toSearch<<" found at index "<< i << endl;
            flag = true;
        }
    }
    if(flag == false){
        cout << toSearch<<" not found at any index "<< endl;
    }
}



int main(){
    // Linear search 
    int arr[10] = {99, 72, 27, 11, 36 , 88, 73 , 83 , 19 , 57};
    int toSearch;
    int size = 10;  
    cout<< "Enter the value you want to search"<< endl;
    cin >> toSearch;

    LinearSearch(arr, size, toSearch);
    int n;
    cout<< "Enter size of a second array"<< endl;
    cin >> n;

    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    int value;
    cout<< " Enter the value you want to search"<< endl;
    cin >> value;

    LSForMulOcc(arr2, n, value);
    return 0;
 
 
}
