#include "graph.hpp"
#include "set.hpp"
#include <queue>
#include <stack>
#include <stdexcept>
#include <memory>

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

Set<int> Graph::inConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    Set<int> connections;

    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[i][vertexIdx])
        {
            connections.insert(i);
        }
    }

    return connections;
}

Set<int> Graph::outConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    Set<int> connections;

    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[vertexIdx][i])
        {
            connections.insert(i);
        }
    }

    return connections;
}

Set<int> Graph::allConnections(const int vertexIdx)
{
    if (!isValidIndex(vertexIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    Set<int> connections;
    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix[vertexIdx][i] || matrix[i][vertexIdx])
        {
            connections.insert(i);
        }
    }

    return connections;
}
