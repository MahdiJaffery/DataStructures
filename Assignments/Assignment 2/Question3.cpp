#include <iostream>
using namespace std;

template <class T>
class UndoStack
{
private:
    T arr[100];
    int topIndex;
    int size;
    int capacity;

public:
    UndoStack() : topIndex(0), size(0), capacity(100) {}

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void push(const T &value)
    {
        arr[topIndex] = value;
        topIndex = (topIndex + 1) % capacity;

        if (isFull())
            cout << "Overwriting oldest value" << endl;
        else
            size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            topIndex = (topIndex - 1 + capacity) % capacity;
            size--;
        }
        else
            cout << "UndoStack is empty!" << endl;
    }

    T top() const
    {
        if (!isEmpty())
        {
            int actualTopIndex = (topIndex - 1 + capacity) % capacity;
            return arr[actualTopIndex];
        }
        throw runtime_error("UndoStack is empty!");
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "UndoStack is empty!" << endl;
            return;
        }

        cout << "Stack contents: ";
        for (int i = 0; i < size; i++)
        {
            int actualIndex = (topIndex - 1 - i + capacity) % capacity;
            cout << arr[actualIndex] << " ";
        }
        cout << endl;
    }
};

int main()
{
    UndoStack<int> myUndoStack;

    for (int i = 1; i <= 101; i++)
    {
        myUndoStack.push(i);
    }

    myUndoStack.print();

    myUndoStack.pop();
    myUndoStack.pop();
    myUndoStack.pop();
    myUndoStack.print();

    return 0;
}
