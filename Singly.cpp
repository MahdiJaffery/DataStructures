#include "Header.h"

class Singly
{
    Node *head, *tail;

public:
    Singly() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int val)
    {
        if (!head)
        {
            tail = head = new Node(val);
            return;
        }

        Node *temp = new Node(val);
        temp->right = head;
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
            tail = head = nullptr;
            delete head, tail;
            return;
        }
        Node *temp = head->right;

        head->right = nullptr;
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
            tail = head = nullptr;
            delete head, tail;
            return;
        }

        Node *temp = head;

        while (temp->right != tail)
            temp = temp->right;

        temp->right = nullptr;
        delete tail;

        tail = temp;

        temp = nullptr;
        delete temp;
    }

    void printSingly()
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

int main(){
    Singly List;

    List.insertAtHead(2);
    List.insertAtTail(1);
    List.insertAtHead(3);

    List.printSingly();

    return 0;
}