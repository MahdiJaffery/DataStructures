#include "Header.h"

class Doubly
{
    Node *head, *tail;

public:
    Doubly() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int val)
    {
        if (!head)
        {
            tail = head = new Node(val);
            return;
        }

        Node *temp = new Node(val);

        temp->right = head;
        head->left = temp;
        head = temp;

        temp = nullptr;
        delete temp;
    }

    void insertAtTail(int val)
    {
        if (!head)
        {
            tail = head = new Node(val);
            return;
        }

        Node *temp = new Node(val);

        temp->left = tail;
        tail->right = temp;
        tail = temp;

        temp = nullptr;
        delete temp;
    }

    bool searchElement(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->val == val)
                return true;
            temp = temp->right;
        }
        return false;
    }

    void removeFromHead()
    {
        if (!head)
            return;
        else if (head == tail)
        {
            head = tail = nullptr;
            delete head, tail;
            return;
        }

        Node *temp = head->right;
        temp->left = nullptr;
        head->right = nullptr;

        head = nullptr;
        delete head;

        head = temp;

        temp = nullptr;
        delete temp;
    }

    void removeFromTail()
    {
        if (!head)
            return;
        else if (head == tail)
        {
            head = tail = nullptr;
            delete head, tail;
            return;
        }

        Node *temp = tail->left;

        temp->right = nullptr;
        tail->left = nullptr;

        tail = nullptr;
        delete tail;

        tail = temp;

        temp = nullptr;
        delete temp;
    }

    void printDoubly()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << space;
            temp = temp->right;
        }
        cout << line;
    }
};

int main()
{
    Doubly List;

    List.insertAtHead(2);
    List.insertAtTail(3);
    List.insertAtHead(1);

    List.searchElement(2) ? cout << "Element Found" : cout << "Element Not Found";
    cout << line;

    return 0;
}