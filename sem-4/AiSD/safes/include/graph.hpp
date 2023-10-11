#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <set>
#include <stack>
#include <memory>
#include <vector>

class Graph
{
private:
    /**
     * @brief Adjacency matrix
     */
    bool **matrix;
    /**
     * @brief Helper function, checks if index passed is valid
     * @return true, if valid, false, in not
     */
    const bool isValidIndex(const int vertexIdx);
    void topologicalSortDFS(int v, std::vector<bool> &visited, std::stack<int> &stk);

public:
    /**
     * @brief Number of vertices
     */
    const int vertexCount;
    /**
     * @brief create new Graph with vertexCount vertices
     * @param vertexCount number of vertices
     */
    Graph(const int vertexCount);
    /**
     * @brief destroys graph instance avoiding memory leaks
     */
    ~Graph();
    /**
     * @brief Add an edge between srcIdx and distIdx vertices
     * @param srcIdx source vertex
     * @param distIdx destination vertex
     */
    void addEdge(const int srcIdx, const int distIdx);

    /**
     * @brief Remove and edge between srcIdx and distIdx
     * @param srcIdx source vertex
     * @param distIdx destination vertex
     */
    void removeEdge(const int srcIdx, const int distIdx);

    /**
     * @brief Checks,if the edge between two vertices exists
     * @return true, if the edge exists, false if not
     * @param srcIdx source vertex
     * @param distIdx destination vertex
     */
    const bool hasEdge(const int srcIdx, const int distIdx);
    /**
     * @brief
     * @return Set of vertices that has connection with
     * vertex with passed index
     * @param vertexIdx source vertex
     */
    std::set<int> inConnections(const int vertexIdx);
    /**
     * @brief
     * @return Set of vertices that are connected with
     * vertex with passed index
     * @param vertexIdx source vertex
     */
    std::set<int> outConnections(const int vertexIdx);
    /**
     * @brief
     * @return Set of vertices that has direct connection with
     * vertex with passed index
     * @param vertexIdx source vertex
     */
    std::set<int> allConnections(const int vertexIdx);

    std::vector<int> topologicalSort();

    void dfs(int v, std::vector<bool> &visited);
};

int solvePuzzle(Graph &graph);

#endif