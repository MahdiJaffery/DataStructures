#include <iostream>
#include "Summary.h"
using namespace std;

int main()
{
    Graph<int> myGraph(5);

    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addVertex(4);
    myGraph.addVertex(5);

    myGraph.addEdge(1, 2, 1);
    myGraph.addEdge(1, 3, 1);
    myGraph.addEdge(2, 4, 1);
    myGraph.addEdge(3, 5, 1);
    myGraph.addEdge(4, 5, 1);

    myGraph.print();
    cout << line;

    cout << "DFS, Start from Vertex 1:\n";
    myGraph.DFS(1);
    cout << line;

    cout << "BFS, Start from Vertex 1:\n";
    myGraph.BFS(1);
    cout << line;

    myGraph.removeEdge(1, 2);
    cout << "After removing edge 1-2" << endl;
    myGraph.print();
    cout << line;

    cout << "DFS, Start from Vertex 1:\n";
    myGraph.DFS(1);
    cout << line;

    cout << "BFS, Start from Vertex 1:\n";
    myGraph.BFS(1);
    cout << line;
    return 0;
}