#ifndef SAFES_HPP
#define SAFES_HPP

#include "graph.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

int solvePuzzle(Graph &safesGraph)
{
    int vertexCount = safesGraph.vertexCount;
    int order[vertexCount];

    safesGraph.topologicalSort(order);

    bool visited[vertexCount];
    std::fill_n(visited, vertexCount, false);

    int counter = 0;
    int curr = 0;
    for (int i = 0; i < vertexCount; i++)
    {
        curr = order[i];
        if (!visited[curr])
        {
            std::cout << "Skladowa" << std::endl;
            safesGraph.dfs(curr, visited);
            counter++;
        }
    }
    return counter;
}

Graph createGraphFromFile(std::string fileName)
{
    std::ifstream inputFile("tests/" + fileName);

    std::vector<int> numbers;

    std::string stringNumber;
    while (getline(inputFile, stringNumber))
    {
        int number = std::stoi(stringNumber);

        numbers.push_back(number);
    }

    Graph graph(numbers.size());
    for (size_t i = 0; i < numbers.size(); i++)
    {
        graph.addEdge(i, numbers.at(i) - 1);
    }

    return graph;
}

void run_tests()
{
    Graph graph = createGraphFromFile("1_23.txt");
    std::cout << solvePuzzle(graph) << std::endl;
}

#endif