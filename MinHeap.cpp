#include "Header.h"

class MinHeap
{
    int *heapArr;
    int size, curSize;

    bool isFull() const
    {
        return curSize == size;
    }

    bool isEmpty() const
    {
        return curSize == 0;
    }

    void reheapUp(int child)
    {
        if (child < 0)
            return;

        int parent = (child - 1) / 2;
        if (heapArr[parent] > heapArr[child])
        {
            swap(heapArr[parent], heapArr[child]);
            reheapUp(parent);
        }
    }

    void reheapDown(int index)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (heapArr[left] < heapArr[right] && heapArr[left] < heapArr[index] && left < curSize)
        {
            swap(heapArr[left], heapArr[index]);
            reheapDown(left);
        }
        else if (heapArr[right] < heapArr[left] && heapArr[right] < heapArr[index] && right < curSize)
        {
            swap(heapArr[right], heapArr[index]);
            reheapDown(right);
        }
        else
            return;
    }

public:
    MinHeap(int size = 10) : size(size), curSize(0)
    {
        heapArr = new int[size];
    }

    void insert(int val)
    {
        if (isFull())
            return;

        heapArr[curSize] = val;
        reheapUp(curSize);
        curSize++;
    }

    void remove()
    {
        if (isEmpty())
            return;

        heapArr[0] = heapArr[curSize - 1];
        curSize--;
        reheapDown(0);
    }

    void printHeap()
    {
        for (int i = 0; i < curSize; i++)
            cout << heapArr[i] << space;
        cout << line;
    }
};

int main()
{
    MinHeap myHeap;

    myHeap.insert(1);
    myHeap.insert(5);
    myHeap.insert(2);
    myHeap.insert(3);
    myHeap.insert(4);
    myHeap.insert(8);
    myHeap.insert(7);
    myHeap.insert(6);

    cout << "Heap Holds:" << space;
    myHeap.printHeap();

    myHeap.remove();

    cout << "Heap Holds:" << space;
    myHeap.printHeap();

    return 0;
}