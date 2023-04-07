#include "graph.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    graph.addEdge(3, 5);

    std::unique_ptr<int[]> values = BFS(&graph, 0);

    std::cout << "Distances" << std::endl;

    for (int i = 0; i < graph.vertexCount; i++)
    {
        std::cout << i << ". " << values[i] << std::endl;
    }

    return 0;
}
