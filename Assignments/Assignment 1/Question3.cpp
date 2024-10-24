#include <iostream>
#include "SortedSet.h"
using namespace std;

int main()
{
    SortedSet<int> mySet;

    for (int i = 1; i <= 6; i++)
        mySet.insertData(i * 10);

    mySet.reverseList();

    mySet.print();
    return 0;
}