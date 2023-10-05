#include <iostream>
#include <vector>
#include "graph.hpp"

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
