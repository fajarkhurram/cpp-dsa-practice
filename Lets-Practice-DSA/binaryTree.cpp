#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;

    Node(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    // Create Tree
    Node* createTree()
    {
        string value;

        cout << "Enter node value (or NULL for no node): ";
        cin >> value;

        if (value == "NULL")
            return NULL;

        Node *newNode = new Node(value);

        cout << "Enter left child of " << value << endl;
        newNode->left = createTree();

        cout << "Enter right child of " << value << endl;
        newNode->right = createTree();

        return newNode;
    }

    // Check Equal Trees
    bool equal(Node *t1, Node *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return true;

        if (t1 == NULL || t2 == NULL)
            return false;

        if (t1->data != t2->data)
            return false;

        return equal(t1->left, t2->left) &&
               equal(t1->right, t2->right);
    }

    // Check Same Structure
    bool sameStructure(Node *t1, Node *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return true;

        if (t1 == NULL || t2 == NULL)
            return false;

        return sameStructure(t1->left, t2->left) &&
               sameStructure(t1->right, t2->right);
    }

    // Check Mirror Image
    bool mirror(Node *t1, Node *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return true;

        if (t1 == NULL || t2 == NULL)
            return false;

        if (t1->data != t2->data)
            return false;

        return mirror(t1->left, t2->right) &&
               mirror(t1->right, t2->left);
    }

    // Preorder Traversal
    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";

        preorder(root->left);

        preorder(root->right);
    }
};

int main()
{
    BinaryTree T1, T2;

    cout << "========== CREATE TREE 1 ==========\n";
    T1.root = T1.createTree();

    cout << "\n========== CREATE TREE 2 ==========\n";
    T2.root = T2.createTree();

    cout << "\nPreorder Traversal of Tree 1: ";
    T1.preorder(T1.root);

    cout << "\nPreorder Traversal of Tree 2: ";
    T2.preorder(T2.root);

    cout << "\n\n========== RESULTS ==========\n";

    if (T1.equal(T1.root, T2.root))
        cout << "Trees are Equal.\n";
    else
        cout << "Trees are NOT Equal.\n";

    if (T1.sameStructure(T1.root, T2.root))
        cout << "Trees have Same Structure.\n";
    else
        cout << "Trees do NOT have Same Structure.\n";

    if (T1.mirror(T1.root, T2.root))
        cout << "Trees are Mirror Images.\n";
    else
        cout << "Trees are NOT Mirror Images.\n";

    return 0;
}