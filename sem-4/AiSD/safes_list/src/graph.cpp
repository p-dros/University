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
    adjacencyList.resize(vertexCount);
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

    adjacencyList[srcIdx].push_back(distIdx);
}

void Graph::removeEdge(const int srcIdx, const int distIdx)
{
    if (!isValidIndex(srcIdx) || !isValidIndex(distIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }
    for (std::vector<int>::size_type i = 0; i < adjacencyList[srcIdx].size(); ++i)
    {
        if (adjacencyList[srcIdx][i] == distIdx)
        {
            adjacencyList[srcIdx].erase(adjacencyList[srcIdx].begin() + i);
            break;
        }
    }
}

const bool Graph::hasEdge(const int srcIdx, const int distIdx)
{
    if (!isValidIndex(srcIdx) || !isValidIndex(distIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    for (std::vector<int>::size_type i = 0; i < adjacencyList[srcIdx].size(); ++i)
    {
        if (adjacencyList[srcIdx][i] == distIdx)
        {
            return true;
        }
    }
    return false;
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
        for (int neighbor : adjacencyList[i])
        {
            if (neighbor == vertexIdx)
            {
                connections.insert(i);
                break;
            }
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
    for (int neighbor : adjacencyList[vertexIdx])
    {
        connections.insert(neighbor);
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

    for (int neighbor : adjacencyList[vertexIdx])
    {
        connections.insert(neighbor);
    }

    for (int i = 0; i < vertexCount; i++)
    {
        for (int neighbor : adjacencyList[i])
        {
            if (neighbor == vertexIdx)
            {
                connections.insert(i);
                break;
            }
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