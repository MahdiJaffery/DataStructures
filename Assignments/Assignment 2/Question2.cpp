#include <iostream>
#define line "\n\n"
#define space "\t"
using namespace std;
template <class T>
class Stack
{

    int size;
    T *arr;
    int maxsize;
    int head;
    int tail;
    bool isFlipped = false;

public:
    Stack()
    {
        arr = new T[10];
        size = 0;
        maxsize = 10;
        head = 0;
        tail = 0;
    }

    void push(T element)
    {
        if (isfull())
        {

            resizeUp();
        }
        if (!isFlipped)
        {
            arr[tail] = element;
            size++;
            tail = (tail + 1) % maxsize;
        }
        else
        {
            head = (head - 1 + maxsize) % maxsize;
            arr[head] = element;
            size++;
        }
    }

    T pop()
    {
        if (!isempty())
        {
            T Ans;
            if (!isFlipped)
            {
                tail = (tail - 1 + maxsize) % maxsize;
                Ans = arr[tail];
                size--;
            }
            else
            {
                Ans = arr[head];
                head = (head + 1) % maxsize;
                size--;
            }
            return Ans;
        }
        else
        {
            cout << "array empty\n";
        }
    }

    bool isempty()
    {
        return !size;
    }
    bool isfull()
    {
        return size == maxsize;
    }

    void flip()
    {
        isFlipped = !isFlipped;
    }

    void print()
    {
        int ptr = head;
        for (int i = 0; i < size; i++)
        {

            if (ptr == maxsize)
            {
                ptr = 0;
            }
            cout << arr[ptr] << space;
            ptr++;
        }
        cout << endl;
    }

    void resizeUp()
    {
        T *newArray = new T[maxsize * 2];

        int ptr = head;
        for (int i = 0; i < size; i++)
        {

            if (ptr == maxsize)
            {
                ptr = 0;
            }
            newArray[i] = arr[ptr];
            ptr++;
        }

        arr = newArray;
        head = 0;
        tail = maxsize - 1;
    }
};

int main()
{
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Original Stack:\n";
    myStack.print();

    myStack.pop();
    cout << "Original Stack after pop():\n";
    myStack.print();

    myStack.flip();
    myStack.pop();
    cout << "Stack after flipStack() and pop():\n";
    myStack.print();

    myStack.push(10);
    cout << "Stack after Push:\n";
    myStack.print();

    myStack.flip();
    myStack.push(10);
    cout << "Stack after Flip and Push:\n";
    myStack.print();
}