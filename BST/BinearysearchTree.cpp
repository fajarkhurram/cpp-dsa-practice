#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insertBST(Node *curr, int value)
    {
        if (curr == NULL)
        {
            Node *newNode = new Node(value);
            return newNode;
        }
        if (value < curr->data)
        { // add node on left
            curr->left = insertBST(curr->left, value);
        }
        else
        { // insert on right
            curr->right = insertBST(curr->right, value);
        }
        return curr;
    }

    Node *searchBST(Node *curr, int value)
    {
        if (curr != NULL)
        {
            if (value == curr->data)
            {
                cout << "value found" << endl;
                return curr;
            }

            if (value < curr->data)
            {
                return searchBST(curr->left, value);
            }
            else
            {
                return searchBST(curr->right, value);
            }
        }
        else
        {
            cout << "Value not found" << endl;
            return NULL;
        }
    }

    void postOrder_display(Node *curr)
    {
        if (curr != NULL)
        {
            postOrder_display(curr->left);
            postOrder_display(curr->right);
            cout << curr->data << " , ";
        }
    }

    void preOrder_display(Node *curr)
    {
        if (curr != NULL)
        {
            cout << curr->data << " , ";
            preOrder_display(curr->left);
            preOrder_display(curr->right);
        }
    }

    void inOrder_display(Node *curr)
    {
        if (curr != NULL)
        {
            inOrder_display(curr->left);
            cout << curr->data << " , ";
            inOrder_display(curr->right);
        }
    }

    //Step 1 → Go right
    //Step 2 → Then go left as much as possible
    Node* find_min(Node* curr){
        if(curr == NULL) 
        return NULL;

        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr;
    }

    Node* deleteBst(Node* curr , int todelete){
        if(curr == NULL){

            cout <<"value not found"<< endl;
            return NULL;
        }

        if(todelete < curr->data){ //search for value in left
            curr->left = deleteBst(curr->left, todelete );
        }
        else if(todelete > curr->data){ //search for value in right
            curr->right = deleteBst(curr->right , todelete);
        }
        //left , right nh hai tow obv curr hi hai so VALUE FOUND
        else{
        
            //case 1: No child
            if(curr->left == NULL && curr->right == NULL){
                delete curr;
                return NULL;
            }
            //case 2 (Having one child either left or either right)
            if(curr->left == NULL){
                Node* temp = curr->right;
                delete curr;
                return temp;
            }
            if(curr->right == NULL){
                Node* temp = curr->left;
                delete curr;
                return temp;
            }
            else{
                Node* min = find_min(curr->right);
                curr->data = min->data;
                curr->right = deleteBst(curr->right, min->data);
                 
            }     
    }
    return curr;

    }

    int findLevel(Node* root, int x)
{
    if(root == NULL)
        return -1;

    queue<Node*> q;
    q.push(root);

    int level = 0;

    while(!q.empty())
    {
        int size = q.size();

        while(size--)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->data == x)
                return level;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        level++;
    }

    return -1;
}

    int height(Node* root)
    {
        if(root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    void descending(Node* root)
{
    stack<Node*> st;
    Node* curr=root;

    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->right;
        }

        curr=st.top();
        st.pop();

        cout<<curr->data<<" ";

        curr=curr->left;
    }
}


    void postOrder(Node* root)
{
    if(root==NULL)
        return;

    stack<Node*> s1,s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* temp=s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

    // Order: Root -> Left -> Right
void preorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> st;

    // Push root node into stack
    st.push(root);

    while(!st.empty())
    {
        // Get top node
        Node* temp = st.top();
        st.pop();

        // Print current node
        cout << temp->data << " ";

        // Push right child first
        if(temp->right != NULL)
            st.push(temp->right);

        // Push left child second
        if(temp->left != NULL)
            st.push(temp->left);
    }
}

void inorder(Node* root)
{
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty())
    {
        // Reach leftmost node
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        // Visit node
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Move to right subtree
        curr = curr->right;
    }
}

void levelOrder(Node* root)   //bfs traversal
{
    if(root == NULL)
        return;

    queue<Node*> q;

    // Insert root into queue
    q.push(root);

    while(!q.empty())
    {
        // Remove front node
        Node* temp = q.front();
        q.pop();

        // Print node
        cout << temp->data << " ";

        // Insert left child
        if(temp->left != NULL)
            q.push(temp->left);

        // Insert right child
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

// Find Successor
Node* successor(Node* node)
{
    // If right subtree exists
    if(node->right != NULL)
        return find_min(node->right);

    return NULL;
}

Node* predecessor(Node* node)
{
    // If left subtree exists
    if(node->left != NULL)
    {
        // Move to left child
        node = node->left;

        // Find rightmost node
        while(node->right != NULL)
        {
            node = node->right;
        }

        return node;
    }

    return NULL;
}



};

int main()
{

    BST bst;

    cout << "ENTER 12 VALUES YOU WANT TO INSERT \n";
    int value;
    for (int i = 0; i < 12; i++)
    {
        cin >> value;
        bst.root = bst.insertBST(bst.root, value);
    }

    bst.preOrder_display(bst.root);
    cout << endl;
    bst.inOrder_display(bst.root);
    cout << endl;
    bst.postOrder_display(bst.root);
    cout << endl;

    bst.searchBST(bst.root, 18);
    bst.searchBST(bst.root, 100);

    bst.deleteBst(bst.root, 256);
    bst.preOrder_display(bst.root);
    cout << endl;
    bst.deleteBst(bst.root, 89);
    bst.preOrder_display(bst.root);
    cout << endl;
    bst.deleteBst(bst.root, 123);
    cout << endl;



    return 0;
}