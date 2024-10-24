#include <iostream>
#include "SortedSet.h"
using namespace std;

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
