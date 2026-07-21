# include <iostream>
using namespace std;

class BSTNode{
public:
    int data ;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value){
        this->data = value;
        left = right = NULL;
    }

};

class BST{
public:
    BSTNode* root;
    BST(){
        root = NULL;
    }

    BSTNode* insert(BSTNode*curr , int value){
        if(curr == NULL){
            BSTNode* newNode = new BSTNode(value);
            return newNode;
        }

        if(value < curr->data ){
            curr->left = insert(curr->left , value);
        }

        else{
            curr->right = insert(curr->right , value);
        }
        return curr;
    }

    bool search(BSTNode* curr , int toSearch){
        if(curr== NULL){
            return false;
        }
        if(toSearch == curr->data){
            return true;
        }

        if(toSearch < curr->data){
            return search(curr->left , toSearch);
        }

        else{
            return search(curr->right , toSearch);
        }
   
    }

    void PreOrderDisplay(BSTNode* curr){
        if(curr == NULL){
            return;
        }

        cout << curr->data << " , ";
        PreOrderDisplay(curr->left);
        PreOrderDisplay(curr->right);
    }

    void inOrderDisplay(BSTNode* curr){
        if(curr== NULL){
            return;
        }
        inOrderDisplay(curr->left);
        cout << curr->data << " , ";
        inOrderDisplay(curr->right);
    }

    void postOrderDisplay(BSTNode* curr){
        if(curr == NULL){
            return;
        }
        postOrderDisplay(curr->left);
        postOrderDisplay(curr->right);
        cout << curr->data << " , " ;
    }

    BSTNode* findmin(BSTNode* curr){
        if(curr == NULL){
            return NULL;
        }
        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr;
    }

    BSTNode* deleteNode(BSTNode* curr , int todelete){
        if(curr == NULL){
            return NULL;
        }
        if(todelete < curr->data){
            curr->left = deleteNode(curr->left , todelete);
            return curr;
        }
        else if(todelete > curr->data){
            curr->right = deleteNode(curr->right , todelete);
            return curr;
        }

        if(curr->left == NULL && curr->right == NULL){
            delete curr;
            return NULL;
        }

        else if(curr->left == NULL){
            BSTNode* temp = curr->right;
            delete curr;
            return temp;
        }
        else if(curr->right == NULL){
            BSTNode* temp = curr->left;
            delete curr;
            return temp;
        }

        else{
            BSTNode* min = findmin(curr->right);
            curr->data = min->data;
            curr->right = deleteNode(curr->right , min->data);
        }
        return curr;

    }
};
int main()
{

    BST tree;

    int arr[] = {89, 11, 76, 122, 256, 66 ,88, 59, 72, 120 ,18, 10};

    for (int i = 0; i < 12; i++)
    {
        tree.root = tree.insert(tree.root ,arr[i]);
    }

    
    tree.inOrderDisplay(tree.root);
    cout << endl;
    tree.postOrderDisplay(tree.root);
    cout << endl;
    tree.PreOrderDisplay(tree.root);
    cout << endl;

    cout << tree.search(tree.root, 120);
    cout << endl;
    cout << tree.search(tree.root , 2);

    tree.deleteNode(tree.root , 66);
    cout << "after delete " << endl;
    tree.inOrderDisplay(tree.root);
    cout << endl;
    tree.postOrderDisplay(tree.root);
    cout << endl;
    tree.PreOrderDisplay(tree.root);
    cout << endl;

    tree.deleteNode(tree.root , 59);
    cout << "after delete " << endl;
    tree.inOrderDisplay(tree.root);
    cout << endl;
    tree.postOrderDisplay(tree.root);
    cout << endl;
    tree.PreOrderDisplay(tree.root);
    cout << endl;



    return 0;
}