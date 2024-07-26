#include "Header.h"

class MaxHeap
{
    int *heapArr, size, curSize;

    bool isFull()
    {
        return curSize == size;
    }

    bool isEmpty()
    {
        return curSize == 0;
    }

    void Heapify(int index)
    {
        if (index < 0)
            return;

        int parent = (index - 1) / 2;
        if (heapArr[parent] < heapArr[index])
        {
            swap(heapArr[parent], heapArr[index]);
            Heapify(parent);
        }
    }

    void reheapDown(int index)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (heapArr[left] > heapArr[right] && heapArr[left] > heapArr[index] && left < curSize)
        {
            swap(heapArr[left], heapArr[index]);
            reheapDown(left);
        }
        else if (heapArr[right] > heapArr[left] && heapArr[right] > heapArr[index] && right < curSize)
        {
            swap(heapArr[right], heapArr[index]);
            reheapDown(right);
        }
        else
            return;
    }

public:
    MaxHeap(int size = 10) : size(size), curSize(0)
    {
        heapArr = new int[size];
    }

    void insert(int val)
    {
        heapArr[curSize] = val;
        Heapify(curSize);
        curSize++;
    }

    void remove()
    {
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
    MaxHeap myHeap(8);

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