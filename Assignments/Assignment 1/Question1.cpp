#include <iostream>
using namespace std;

template <typename T>
class SortedSet
{
    struct Node
    {
        T val;
        Node *next;
        Node(T val) : val(val), next(nullptr) {}
    };

    int length;
    Node *head;

    bool insertData(T val, Node *&head)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            length++;
            return true;
        }

        if (head->val == val)
        {
            delete newNode; // Deallocate memory
            return false;
        }

        if (head->val > val)
        {
            newNode->next = head;
            head = newNode;
            length++;
            return true;
        }

        Node *temp = head;
        while (temp->next)
        {
            if (temp->next->val == val)
            {
                delete newNode;
                return false;
            }
            if (temp->next->val > val)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return true;
            }
            temp = temp->next;
        }

        temp->next = newNode;
        length++;
        return true;
    }

    bool deleteIndex(int index, Node *&head)
    {
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            length--;
            return true;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        length--;
        return true;
    }

public:
    SortedSet() : head(nullptr), length(0) {}

    bool insertData(T val)
    {
        return insertData(val, head);
    }

    bool deleteIndex(int index)
    {
        if (index > length)
        {
            cout << "Invalid Index\n";
            return false;
        }

        return deleteIndex(index, head);
    }

    void unionSet(SortedSet<T> &set)
    {
        Node *temp = set.head;
        while (temp)
        {
            insertData(temp->val);
            temp = temp->next;
        }
    }

    void print()
    {
        if (!head) // Check if the list is empty
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SortedSet<int> evenSet;

    for (int i = 0; i <= 10; i += 2)
    {
        if (evenSet.insertData(i))
            cout << "Inserted " << i << endl;
        else
            cout << "Failed to insert " << i << endl;
    }

    evenSet.print();

    SortedSet<int> oddSet;

    for (int i = 1; i <= 10; i += 2)
    {
        if (oddSet.insertData(i))
            cout << "Inserted " << i << endl;
        else
            cout << "Failed to insert " << i << endl;
    }

    oddSet.print();

    evenSet.deleteIndex(4);

    evenSet.print();

    evenSet.unionSet(oddSet);

    evenSet.print();

    return 0;
}
