#include "Header.h"

class BST
{
    Node *root;

    void insert(Node *&root, int val)
    {
        if (!root)
        {
            root = new Node(val);
            return;
        }

        if (root->val > val)
            insert(root->left, val);
        else
            insert(root->right, val);
    }

    bool searchElement(Node *root, int val)
    {
        if (!root)
            return false;

        if (val > root->val)
            searchElement(root->right, val);
        else if (val < root->val)
            searchElement(root->left, val);
        return true;
    }

    void getPredecessor(Node *root, int &data)
    {
        while (root->right)
            root = root->right;
        data = root->val;
    }

    void deleteNode(Node *&root)
    {
        Node *temp = root;
        int data;

        if (!temp->left)
        {
            root = root->right;
            delete temp;
        }
        else if (!temp->right)
        {
            root = root->left;
            delete temp;
        }
        else
        {
            getPredecessor(root->left, data);
            root->val = data;
            remove(root->left, data);
        }
    }

    void remove(Node *&root, int val)
    {
        if (val > root->val)
            remove(root->right, val);
        else if (val < root->val)
            remove(root->left, val);
        else
            deleteNode(root);
    }

    void inOrder(Node *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        cout << root->val << space;
        inOrder(root->right);
    }

public:
    BST() : root(nullptr) {}

    void insertVal(int val)
    {
        insert(root, val);
    }

    bool search(int val)
    {
        return searchElement(root, val);
    }

    void remove(int val)
    {
        if (!search(val))
            return;
        remove(root, val);
    }

    void inOrder()
    {
        inOrder(root);
        cout << line;
    }
};

int main()
{
    BST myTree;

    myTree.insertVal(5);
    myTree.insertVal(2);
    myTree.insertVal(1);
    myTree.insertVal(4);
    myTree.insertVal(3);

    cout << "Tree Holds:\t";
    myTree.inOrder();

    myTree.remove(3);

    myTree.search(3) ? cout << "Found Element" : cout << "Element not Found";
    cout << line;

    cout << "Tree Holds:\t";
    myTree.inOrder();

    return 0;
}