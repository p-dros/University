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

void DFS(Graph *G, int sourceIdx)
{
    if (!G->isValidIndex(sourceIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    bool visited[G->vertexCount];
    std::fill_n(visited, G->vertexCount, false);

    std::cout << "DFS traversal starting from vertex " << sourceIdx << ": ";
    DFS(G, sourceIdx, visited);
    std::cout << std::endl;
}

void DFS(Graph *G, int index, bool *visited)
{
    visited[index] = true;
    std::cout << index << " ";

    for (int i = 0; i < G->vertexCount; i++)
    {
        if (G->matrix[index][i] && !visited[i])
        {
            DFS(G, i, visited);
        }
    }
}

void DFS_stack(Graph *G, int sourceIdx)
{
    if (!G->isValidIndex(sourceIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    bool visited[G->vertexCount];
    std::fill_n(visited, G->vertexCount, false);

    std::cout << "DFS traversal starting from vertex " << sourceIdx << ": ";

    std::stack<int> stack;
    stack.push(sourceIdx);

    while (!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex])
        {
            visited[vertex] = true;
            std::cout << vertex << " ";

            for (int i = G->vertexCount - 1; i >= 0; i--)
            {
                if (G->matrix[vertex][i] && !visited[i])
                {
                    stack.push(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

std::unique_ptr<int[]> BFS(Graph *G, int sourceIdx)
{
    if (!G->isValidIndex(sourceIdx))
    {
        throw std::out_of_range("Index out of bounds");
    }

    int n = G->vertexCount;

    std::unique_ptr<int[]> dist(new int[n]);
    bool visited[n];

    std::fill_n(dist.get(), n, -1);
    std::fill_n(visited, n, false);

    std::queue<int> queue;
    queue.push(sourceIdx);

    visited[sourceIdx] = true;
    dist[sourceIdx] = 0;

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        queue.pop();

        for (int i = 0; i < n; i++)
        {
            if (G->matrix[currentVertex][i] && !visited[i])
            {
                visited[i] = true;
                std::cout << "vertex: " << i << std::endl;
                dist[i] = dist[currentVertex] + 1;
                queue.push(i);
            }
        }
    }

    return dist;
}