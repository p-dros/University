#include "graph.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);

    int *values = BFS(&graph, 0);

    delete[] values;
    return 0;
}
