#include<iostream>
using namespace std;

//================ NODE =================
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//================ INSERT INTO BST =================
Node* insert(Node* root, int value)
{
    // If tree is empty, create first node
    if(root == NULL)
        return new Node(value);

    // Insert in left subtree
    if(value < root->data)
        root->left = insert(root->left, value);

    // Insert in right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

//================ CONVERT BST TO ARRAY (INORDER) =================
void BSTtoArray(Node* root, int arr[], int &index)
{
    if(root == NULL)
        return;

    // Visit left subtree
    BSTtoArray(root->left, arr, index);

    // Store node in array
    arr[index] = root->data;
    index++;

    // Visit right subtree
    BSTtoArray(root->right, arr, index);
}

//================ PREORDER OF ARRAY =================
void preorderArray(int arr[], int size, int i)
{
    // Stop if index goes outside array
    if(i >= size)
        return;

    // Print current element
    cout << arr[i] << " ";

    // Visit left child
    preorderArray(arr, size, 2*i + 1);

    // Visit right child
    preorderArray(arr, size, 2*i + 2);
}

//================ BINARY SEARCH =================
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

//================ MAIN =================
int main()
{
    Node* root = NULL;

    // Insert values (0 and negative are also valid)
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 0);
    root = insert(root, -8);
    root = insert(root, 7);
    root = insert(root, 15);

    int arr[100];
    int index = 0;

    // Convert BST into sorted array
    BSTtoArray(root, arr, index);

    cout << "Array : ";
    for(int i = 0; i < index; i++)
        cout << arr[i] << " ";

    cout << "\n\nPreorder Traversal of Array : ";
    preorderArray(arr, index, 0);

    int key;
    cout << "\n\nEnter value to search : ";
    cin >> key;

    int pos = binarySearch(arr, index, key);

    if(pos != -1)
        cout << "Value Found at Index " << pos;
    else
        cout << "Value Not Found";

    return 0;
}