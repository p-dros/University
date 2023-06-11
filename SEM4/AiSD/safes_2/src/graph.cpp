#include "graph.hpp"
#include <set>
#include <queue>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <vector>
#include <stack>

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

std::vector<int> Graph::topologicalSort()
{
    std::vector<int> result;
    std::vector<bool> visited(vertexCount, false);
    std::stack<int> stk;

    for (int i = 0; i < vertexCount; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(i, visited, stk);
        }
    }

    while (!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

void Graph::topologicalSortDFS(int v, std::vector<bool> &visited, std::stack<int> &stk)
{
    visited[v] = true;
    std::set<int> connections = outConnections(v);
    for (int u : connections)
    {
        if (!visited[u])
        {
            topologicalSortDFS(u, visited, stk);
        }
    }
    stk.push(v); // Dodaj wierzchołek na stos po zakończeniu przeszukiwania DFS
}

void Graph::dfs(int v, std::vector<bool> &visited)
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
