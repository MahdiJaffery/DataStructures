#include <iostream>
#include "SortedSet.h"

int main()
{
    SortedSet<int> mySet;

    for (int i = 1; i <= 6; i++)
        mySet.insertData(i * 10);

    if (mySet.rotateList(8))
        cout << "List rotated\n";
    else
        cout << "Failed to rotate list\n";

    mySet.print();

    if (mySet.rotateList(-3))
        cout << "List rotated\n";
    else
        cout << "Failed to rotate list\n";

    mySet.print();

    return 0;
}