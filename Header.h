#include <iostream>

#define space "\t"
#define line "\n\n"

using namespace std;

struct Node
{
    int val, height;
    Node *right, *left;
    Node(int val) : val(val), right(nullptr), left(nullptr), height(1) {}
};

struct Item
{
    int key, status; //	0-Empty     1-Deleted     2-Occupied
    Item() : key(0), status(0) {}
    Item(int key) : key(key), status(2) {}
};