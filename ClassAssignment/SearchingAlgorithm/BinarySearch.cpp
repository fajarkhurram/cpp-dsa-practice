#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int size, int toSearch)
{
    int left = 0, right = size - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (toSearch == arr[mid])
        {
            cout << toSearch << " Value found at index " << mid << endl;
            return true;
        }

        if (toSearch < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << toSearch << " Value is not found at any index " << endl;
    return false;
}

void BSForMulOcc(int arr[], int size, int toSearch)
{
    int left = 0, right = size - 1, mid;
    bool flag = false;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (toSearch == arr[mid]){
            cout << toSearch << " Value found at index " << mid << endl;
            flag = true;

            //searching on left
            for (int i = mid + 1; i < size; i++){
                if (toSearch == arr[i])
                    cout << toSearch << " Value found at index " << i << endl;
                else                
                    break;   
            }
            //searching on right
            for (int i = mid - 1; i >= 0; i--){
                if (toSearch == arr[i])
                    cout << toSearch << " Value found at index " << i << endl;
                else
                    break; 
            }
        break;
        }
        else if (toSearch < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
}
    if(flag == false){
        cout << toSearch << " Value is not found at any index " << endl;
    }
    
}

int main()
{
    int arr[10] = {11, 20, 27, 33, 36, 67, 67, 67, 72, 82};

    int value;
    cout<< " Enter the value you want to search"<< endl;
    cin >> value;

    BinarySearch(arr, 10, value);

    cout<< " Enter the value you want to search for multiple occurances "<< endl;
    cin >> value;

    BSForMulOcc(arr, 10, value);

    return 0;
}