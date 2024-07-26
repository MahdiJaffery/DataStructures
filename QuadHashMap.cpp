#include "Header.h"

class QuadHashMap
{
    Item *hashArr;
    int capacity, curSize;
    float loadFactor;

    void setLoadFactor()
    {
        loadFactor = static_cast<float>(curSize) / capacity;
    }

    int Hash(int val)
    {
        return val % capacity;
    }

    int resolveCollision(int index, int i)
    {
        return (index + i * i) % capacity;
    }

    void doubleCapacity()
    {
        int oldCapacity = capacity;
        Item *tempHash = new Item[oldCapacity];

        capacity *= 2;

        for (int i = 0; i < oldCapacity; i++)
            tempHash[i] = hashArr[i];

        hashArr = new Item[capacity];
        loadFactor = 0, curSize = 0;

        for (int i = 0; i < oldCapacity; i++)
            if (tempHash[i].status == 2)
                insert(tempHash[i].key);

        setLoadFactor();
    }

    void reHash()
    {
        Item *newHash = new Item[capacity];
        int index, helper = 1;
        for (int i = 0; i < capacity; i++)
        {
            if (hashArr[i].status == 2)
            {
                index = Hash(hashArr[i].key);

                helper = 1;
                while (newHash[index].status == 2)
                {
                    index = resolveCollision(index, helper);
                    helper++;
                }

                newHash[index] = hashArr[i];
            }
        }

        hashArr = nullptr;
        delete hashArr;

        hashArr = newHash;

        newHash = nullptr;
        delete[] newHash;
    }

public:
    QuadHashMap(int size = 8) : capacity(size), curSize(0)
    {
        loadFactor = static_cast<float>(curSize) / capacity;
        hashArr = new Item[capacity];
    }

    void insert(int val)
    {
        int index = Hash(val), helper = 1;

        while (hashArr[index].status == 2)
        {
            index = resolveCollision(index, helper);
            helper++;
        }

        hashArr[index] = Item(val);
        curSize++;

        setLoadFactor();
        if (loadFactor > 0.5)
            doubleCapacity();
    }

    bool searchElement(int val)
    {
        int index = Hash(val), helper = 1;

        while (hashArr[index].status == 2)
        {
            if (hashArr[index].key == val)
                return true;
            else
            {
                index = resolveCollision(index, helper);
                helper++;
            }
        }
        return false;
    }

    void removeElement(int val)
    {
        if (!searchElement(val))
            return;

        int index = Hash(val), helper = 1;

        while (hashArr[index].status == 2)
        {
            if (hashArr[index].key == val)
            {
                hashArr[index] = Item();
                curSize--;
                reHash();
                setLoadFactor();

                return;
            }
            else
            {
                index = resolveCollision(index, helper);
                helper++;
            }
        }
    }

    void printMap()
    {
        for (int i = 0; i < capacity; i++)
            if (hashArr[i].status == 2)
                cout << "Index " << i << ": " << hashArr[i].key << endl;
            else
                cout << "Index " << i << ": " << "\n";
        cout << line;
    }
};

int main()
{
    QuadHashMap myMap;

    myMap.insert(5);
    myMap.insert(55);
    myMap.insert(555);
    myMap.insert(2);
    myMap.insert(3);

    cout << "Map Holds:\n";
    myMap.printMap();

    myMap.searchElement(7) ? cout << "Element Found" : cout << "Element not Found";
    cout << line;

    myMap.removeElement(555);

    cout << "Map Holds:\n";
    myMap.printMap();

    return 0;
}