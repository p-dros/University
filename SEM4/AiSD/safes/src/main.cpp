#include <iostream>
#include <vector>
#include "graph.hpp"

int solvePuzzle(Graph &graph)
{
    std::vector<int> order = graph.topologicalSort();

    std::vector<bool> visited(graph.vertexCount, false);

    int counter = 0;
    int curr = 0;
    for (int i = 0; i < graph.vertexCount; i++)
    {
        curr = order.at(i);
        if (!visited[curr])
        {
            graph.dfs(curr, visited);
            counter++;
        }
    }

    return (counter - 1);
}

int main(int argc, char const *argv[])
{
    int safeCount;
    std::cout << "Podaj Liczbe sejfow: " << std::endl;

    std::cin >> safeCount;

    Graph graph(safeCount + 1);

    int key;
    for (int i = 1; i <= safeCount; i++)
    {
        std::cin >> key;
        graph.addEdge(key, i);
    }

    std::cout << "Anwser: " << solvePuzzle(graph) << std::endl;

    return 0;
}
