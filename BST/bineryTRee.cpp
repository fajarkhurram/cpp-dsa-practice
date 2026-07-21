#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
    float data;
    Node *left;
    Node *right;

    Node(float value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

    Node* createTree()
{
    float value;

    cout << "Enter value (-1 for NULL): ";
    cin >> value;

    // Base Case
    if(value == -1)
        return NULL;

    // Create new node
    Node* root = new Node(value);

    // Create left subtree
    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    // Create right subtree
    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

Node* insert(Node* root, int value)
{
    // If tree is empty
    if(root == NULL)
        return new Node(value);

    queue<Node*> q;

    // Start from root
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        // Insert at first empty left child
        if(temp->left == NULL)
        {
            temp->left = new Node(value);
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        // Insert at first empty right child
        if(temp->right == NULL)
        {
            temp->right = new Node(value);
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }

    return root;
}

bool DFS(Node *root, float x)
{
    if(root == NULL)
        return false;

    stack<Node*> st;

    // Push root into stack
    st.push(root);

    while(!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        // Check if value is found
        if(temp->data == x)
            return true;

        // Push right child first
        if(temp->right != NULL)
            st.push(temp->right);

        // Push left child so it is visited first
        if(temp->left != NULL)
            st.push(temp->left);
    }

    return false;
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    stack<Node*> st;

    st.push(root);

    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();

        cout<<temp->data<<" ";

        if(temp->right)  //push right child first so that left child is processed first
            st.push(temp->right);

        if(temp->left)  
            st.push(temp->left);
    }
}

    bool isMirror(Node *root1, Node *root2)
{
    // Both trees are empty
    if(root1 == NULL && root2 == NULL)
        return true;

    // One tree is empty
    if(root1 == NULL || root2 == NULL)
        return false;

    // Check data and opposite children
    return (root1->data == root2->data &&
            isMirror(root1->left, root2->right) &&
            isMirror(root1->right, root2->left));
}
     
    bool isEqual(Node *root1, Node *root2)
    {
        // Both trees empty
        if(root1 == NULL && root2 == NULL)
            return true;

        // One tree empty
        if(root1 == NULL || root2 == NULL)
            return false;

        // Data and both subtrees must be equal
        return (root1->data == root2->data &&
                isEqual(root1->left, root2->left) &&
                isEqual(root1->right, root2->right));
    }


    bool sameStructure(Node *root1, Node *root2)
    {
    // Both trees empty
    if(root1 == NULL && root2 == NULL)
        return true;

    // One tree empty
    if(root1 == NULL || root2 == NULL)
        return false;

    // Compare only structure
    return (sameStructure(root1->left, root2->left) &&
            sameStructure(root1->right, root2->right));
    }

int main()
{
    Node* root=new Node(10.5);

    root->left=new Node(5.5);
    root->right=new Node(20.8);

    root->left->left=new Node(2.1);
    root->left->right=new Node(8.4);

    preorder(root);
}