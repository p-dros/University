#include "graph.hpp"
#include <set>
#include <queue>
#include <stack>
#include <stdexcept>
#include <memory>
#include <iostream>

Graph::Graph(const int vertexCount) : vertexCount(vertexCount)
{
    matrix = new bool *[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        matrix[i] = new bool[vertexCount];

        for (int j = 0; j < vertexCount; j++)
        {
            matrix[i][j] = false;
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < vertexCount; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

const bool Graph::isValidIndex(const int vertexIdx)
{
    return vertexIdx >= 0 && vertexIdx < vertexCount;
}

void Graph::addEdge(const int srcIdx, const int distIdx)
{
    if (!isValidIndex(srcIdx) || !isValidIndex(distIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }
    matrix[srcIdx][distIdx] = true;
}

void Graph::removeEdge(const int srcIdx, const int distIdx)
{
    if (!isValidIndex(srcIdx) || !isValidIndex(distIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }
    matrix[srcIdx][distIdx] = false;
}

const bool Graph::hasEdge(const int srcIdx, const int distIdx)
{
    if (!isValidIndex(srcIdx) || !isValidIndex(distIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }
    return matrix[srcIdx][distIdx];
}

std::set<int> Graph::inConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    std::set<int> connections;

    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[i][vertexIdx])
        {
            connections.insert(i);
        }
    }

    return connections;
}

std::set<int> Graph::outConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    std::set<int> connections;

    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[vertexIdx][i])
        {
            connections.insert(i);
        }
    }

    return connections;
}

std::set<int> Graph::allConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    std::set<int> connections;
    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[vertexIdx][i] || matrix[i][vertexIdx])
        {
            connections.insert(i);
        }
    }

    return connections;
}

void Graph::dfs(int v, bool *visited)
{
    std::cout << v << std::endl;
    visited[v] = true;

    std::set<int> connections = outConnections(v);
    for (int u : connections)
    {
        if (!visited[u])
        {
            dfs(u, visited);
        }
    }
}

void Graph::topologicalSort(int *result)
{
    int curr = vertexCount - 1;
    bool visited[vertexCount];

    std::fill_n(visited, vertexCount, false);

    for (int i = 0; i < vertexCount; i++)
    {
        if (!visited[i])
        {
            topologicalSortVisit(i, visited, result, curr);
        }
    }
}

void Graph::topologicalSortVisit(int v, bool *visited, int *result, int &curr)
{
    visited[v] = true;
    std::set<int> connections = outConnections(v);

    for (int u : connections)
    {
        if (!visited[u])
        {
            topologicalSortVisit(u, visited, result, curr);
        }
    }

    result[curr] = v;
    curr--;
}
