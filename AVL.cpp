#include "Header.h"
#include <queue>

class AVL
{
    Node *root;

    int Height(Node *root)
    {
        if (!root)
            return 0;
        return root->height;
    }

    int Balance(Node *root)
    {
        if (!root)
            return 0;
        return Height(root->left) - Height(root->right);
    }

    Node *rotateRight(Node *root)
    {
        if (!root)
            return root;

        Node *middle = root->right;
        Node *middleRight = middle->right;

        middle->right = root;
        root->left = middleRight;

        root->height = max(Height(root->left), Height(root->left)) + 1;
        middle->height = max(Height(middle->left), Height(middle->right)) + 1;

        return middle;
    }

    Node *rotateLeft(Node *root)
    {
        if (!root)
            return root;

        Node *middle = root->right;
        Node *middleLeft = middle->left;

        middle->left = root;
        root->right = middleLeft;

        root->height = max(Height(root->left), Height(root->right)) + 1;
        middle->height = max(Height(middle->left), Height(middle->right)) + 1;

        return middle;
    }

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

        root->height = max(Height(root->left), Height(root->right)) + 1;
        int balanceFactor = Balance(root);

        if (balanceFactor == 2 && val < root->left->val)
            root = rotateRight(root);
        if (balanceFactor == -2 && val > root->right->val)
            root = rotateLeft(root);
        if (balanceFactor == 2 && val > root->left->val)
        {
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
        if (balanceFactor == -2 && val < root->right->val)
        {
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    void removeNode(Node *&root)
    {
        Node *temp = root;
        int data;

        if (!root->left)
        {
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            root = root->left;
            delete temp;
        }
        else
        {
            getPredecessor(root->left, data);
            root->val = data;
            deleteNode(root->left, data);
        }

        if (!root)
            return;

        root->height = max(Height(root->left), Height(root->right)) + 1;
        int balanceFactor = Balance(root);

        if (balanceFactor == 2)
            root = rotateRight(root);
        else if (balanceFactor == -2)
            root = rotateLeft(root);
    }

    void deleteNode(Node *&root, int val)
    {
        if (!root)
            return;

        if (val > root->val)
            deleteNode(root->right, val);
        else if (val < root->val)
            deleteNode(root->left, val);
        else
            removeNode(root);
    }

    void getPredecessor(Node *root, int &val)
    {
        while (root->right)
            root = root->right;
        val = root->val;
    }

    bool searchNode(Node *root, int val)
    {
        if (!root)
            return false;

        if (val > root->val)
            searchNode(root->right, val);
        else if (val < root->val)
            searchNode(root->left, val);
        return true;
    }

    void inOrder(Node *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        cout << root->val << space;
        inOrder(root->right);
    }

    void levelOrder(Node *root)
    {
        queue<Node *> Que;

        Que.push(root);
        Node *newNode;

        while (!Que.empty())
        {
            newNode = Que.front();
            Que.pop();

            cout << newNode->val << space;

            if (newNode->left)
                Que.push(newNode->left);
            if (newNode->right)
                Que.push(newNode->right);
        }
    }

public:
    AVL() : root(nullptr) {}

    void insert(int val)
    {
        insert(root, val);
    }

    bool searchNode(int val)
    {
        return searchNode(root, val);
    }

    void deleteNode(int val)
    {
        if (!searchNode(val))
            return;
        deleteNode(root, val);
    }

    void inOrder()
    {
        inOrder(root);
        cout << line;
    }

    void levelOrder()
    {
        levelOrder(root);
    }
};

int main()
{
    AVL myTree;

    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);

    cout << "Tree Holds:" << space;
    myTree.inOrder();

    myTree.deleteNode(3);

    myTree.searchNode(3) ? cout << "Element Found" : cout << "Element not Found";
    cout << line;

    cout << "Tree Holds:" << space;
    myTree.inOrder();

    return 0;
}