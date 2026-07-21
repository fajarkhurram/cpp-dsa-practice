#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 0;
    }
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    int getHeight(Node* curr)
    {
        if (curr == NULL)
            return -1;
        return curr->height;
    }

    void updateHeight(Node* curr)
    {
        int leftHeight = getHeight(curr->left);
        int rightHeight = getHeight(curr->right);

        if (leftHeight > rightHeight)
            curr->height = leftHeight + 1;
        else
            curr->height = rightHeight + 1;
    }

    Node* rotateRight(Node* curr)
    {
        Node* temp = curr->left;
        Node* temp2 = temp->right;

        temp->right = curr;
        curr->left = temp2;

        updateHeight(curr);
        updateHeight(temp);

        return temp;
    }

    Node* rotateLeft(Node* curr)
    {
        Node* temp = curr->right;
        Node* temp2 = temp->left;

        temp->left = curr;
        curr->right = temp2;

        updateHeight(curr);
        updateHeight(temp);

        return temp;
    }

    Node* rotateLeftRight(Node* curr)
    {
        curr->left = rotateLeft(curr->left);
        return rotateRight(curr);
    }

    Node* rotateRightLeft(Node* curr)
    {
        curr->right = rotateRight(curr->right);
        return rotateLeft(curr);
    }

    // ================= INSERT =================
    Node* insertAVL(Node* curr, int value)
    {
        if (curr == NULL)
        {
            Node* newNode = new Node(value);
            return newNode;
        }

        if (value < curr->data)
        {
            curr->left = insertAVL(curr->left, value);
        }
        else if (value > curr->data)
        {
            curr->right = insertAVL(curr->right, value);
        }
        else
        {
            return curr;
        }

        int balance = getHeight(curr->left) - getHeight(curr->right);

        if (balance > 1)
        {
            if (value < curr->left->data)
                curr = rotateRight(curr);
            else
                curr = rotateLeftRight(curr);
        }
        else if (balance < -1)
        {
            if (value > curr->right->data)
                curr = rotateLeft(curr);
            else
                curr = rotateRightLeft(curr);
        }

        updateHeight(curr);
        return curr;
    }

    // ================= FIND MIN =================
    Node* find_min(Node* curr)
    {
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    // ================= DELETE =================
    Node* deleteAVL(Node* curr, int value)
    {
        if (curr == NULL)
            return NULL;

        if (value < curr->data)
        {
            curr->left = deleteAVL(curr->left, value);
        }
        else if (value > curr->data)
        {
            curr->right = deleteAVL(curr->right, value);
        }
        else
        {
            // NO CHILD
            if (curr->left == NULL && curr->right == NULL)
            {
                delete curr;
                return NULL;
            }

            // ONE CHILD
            else if (curr->left == NULL)
            {
                Node* temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == NULL)
            {
                Node* temp = curr->left;
                delete curr;
                return temp;
            }

            // TWO CHILDREN
            else
            {
                Node* temp = find_min(curr->right);
                curr->data = temp->data;
                curr->right = deleteAVL(curr->right, temp->data);
            }
        }

        
        if (curr == NULL)
            return NULL;

        int balance = getHeight(curr->left) - getHeight(curr->right);

        if (balance > 1)
        {
            if (getHeight(curr->left->left) >= getHeight(curr->left->right))
                curr = rotateRight(curr);
            else
                curr = rotateLeftRight(curr);
        }
        else if (balance < -1)
        {
            if (getHeight(curr->right->right) >= getHeight(curr->right->left))
                curr = rotateLeft(curr);
            else
                curr = rotateRightLeft(curr);
        }

        updateHeight(curr);
        return curr;
    }

   
    void preOrder(Node* curr)
    {
        if (curr)
        {
            cout << curr->data << " ";
            preOrder(curr->left);
            preOrder(curr->right);
        }
    }

    void inOrder(Node* curr)
    {
        if (curr)
        {
            inOrder(curr->left);
            cout << curr->data << " ";
            inOrder(curr->right);
        }
    }

    void postOrder(Node* curr)
    {
        if (curr)
        {
            postOrder(curr->left);
            postOrder(curr->right);
            cout << curr->data << " ";
        }
    }

    void insert(int value)
    {
        root = insertAVL(root, value);
    }

    void remove(int value)
    {
        root = deleteAVL(root, value);
    }
};

int main()
{
    AVL tree;

    cout << "Enter 12 values:\n";
    int value;

    for (int i = 0; i < 12; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    cout << "\nPreOrder: ";
    tree.preOrder(tree.root);

    cout << "\nInOrder: ";
    tree.inOrder(tree.root);

    cout << "\nPostOrder: ";
    tree.postOrder(tree.root);

    cout << "\n\nSearching 18: ";
    tree.insert(18); // just example
    tree.preOrder(tree.root);

    cout << "\n\nDeleting values...\n";
    tree.remove(256);
    tree.remove(89);
    tree.remove(123);

    cout << "\nFinal PreOrder: ";
    tree.preOrder(tree.root);

    return 0;
}