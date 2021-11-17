/* Title: hw3_3.cpp
 * Abstract: This program implements the Depth-First Search (DFS)
 *           algorithm using a stack(recursively) and a mark array
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/16/21
 */

#include <iostream>
#include <vector>

void readGraph(std::vector<std::vector<int>>& g);
void dfs(std::vector<std::vector<int>>& g, int src);
void dfsRecursive(std::vector<std::vector<int>>& g, int vertex, std::vector<int> &mark, int &count);

int main()
{
    // Declare variables
    std::vector<std::vector<int>> graph;
    const int srcVertex = 0;

    // Read graph data
    readGraph(graph);

    // Run DFS algorithm and print output
    dfs(graph, srcVertex);

    return 0;
}

// Reads graph information and builds adjacency list
void readGraph(std::vector<std::vector<int>>& g)
{
    // Variable declarations
    int numVertices;
    int numEdges;
    int from;
    int to;

    //Receive input
    std::cin >> numVertices >> numEdges;

    // Adjust the size of graph std::vector to hold all vertices.
    g.resize(numVertices);

    // Build adjacency list using supplied input
    for (int i = 0; i < numEdges; i++)
    {
	    std::cin >> from >> to;
        g[from].push_back(to);
    }
}

// Find a path to all vertices in an adjacency list using DFS algorithm
void dfs(std::vector<std::vector<int>>& g, int src)
{
    // Declare variables
    int count = 0;
    std::vector<int> mark(g.size(), 0);

    // Check for adjacent and move through the graph
    for (int i = 0; i < g.size(); i++)
    {
        if (mark[i] == 0)
        {
            dfsRecursive(g, i, mark, count);
        }
    }

    // print mark array
    for (int i = 0; i < g.size(); i++)
    {
	    std::cout << "Mark[" << i << "]: " << mark[i] << std::endl;
    }
}

// Recursively searches through adjacency list to find a path in the graph using DFS
void dfsRecursive(std::vector<std::vector<int>> &g, int vertex, std::vector<int> &mark, int &count)
{
    count += 1;
    mark[vertex] = count;

    // If a node has not been visited, run the dfs algorithm from that node
    for (int i = 0; i < g[vertex].size(); i++)
    {
        if (mark[g[vertex][i]] == 0)
        {
            dfsRecursive(g, g[vertex][i], mark, count);
        }
    }
};