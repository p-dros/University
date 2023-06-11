#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include "graph.hpp"

int getExpectedResult(std::string filename)
{
    size_t underscorePos = filename.find("_");
    size_t dotPos = filename.find(".");

    std::string numberString = filename.substr(underscorePos + 1, dotPos - underscorePos - 1);

    return std::stoi(numberString);
}

Graph createGraphFromFile(std::string filename)
{
    std::string textNumber;

    std::ifstream inputFile("tests/" + filename);

    getline(inputFile, textNumber);
    int numberOfSafes = std::stoi(textNumber);

    Graph graph(numberOfSafes + 1);

    int i = 1;
    while (getline(inputFile, textNumber))
    {
        int key = std::stoi(textNumber);
        graph.addEdge(key, i);
        i++;
    }

    return graph;
}

void test_files()
{
    std::vector<std::string> filenames = {
        "1_23.txt",
        "2_3.txt",
        "3_8.txt",
        "4_1000.txt",
        "5_500.txt",
        "6_2.txt",
        "7_31.txt",
        "8_5041.txt"};

    for (std::string filename : filenames)
    {
        int expectedResult = getExpectedResult(filename);
        Graph graph = createGraphFromFile(filename);

        assert(solvePuzzle(graph) == expectedResult);
        std::cout << filename << " file passed test" << std::endl;
    }
}

int main()
{
    test_files();
    return 0;
}