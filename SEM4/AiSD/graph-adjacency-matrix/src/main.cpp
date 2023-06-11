#include "graph.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 6);
    graph.addEdge(1, 0);

    BFS(&graph, 1);

    return 0;
}
