/* Title: hw4_3.cpp
 * Abstract: This program conducts the topological sorting based on the Kahn algorithm 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/30/21
 */

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

// Data structure to hold graph data
class Graph
{
    int numVertices;
    std::list<int>* adjacencyList;

public:
    Graph(int numVertices);
    void addEdge(int from, int to);
    void kahnSort();
};

int main()
{
    // initialize variables
    int numVertices, numEdges;
    std::map<int, int> inDegreeCount;

    // Get initial parameters from user
    std::cin >> numVertices >> numEdges;
    Graph graph(numVertices);

    // Initialize in-degree count for all vertices to 0
    for (int i = 0; i < numVertices; i++)
    {
        inDegreeCount.insert({ i,0 });
    }

    // Read graph data
    for (int i = 0; i < numEdges; i++)
    {
        // add edge information to graph
        int vertex1, vertex2;
        while (std::cin >> vertex1 >> vertex2)
        {
            graph.addEdge(vertex1, vertex2);

            // Update in-degree count
            if (inDegreeCount.find(vertex2) == inDegreeCount.end())
            {
                inDegreeCount.insert({ vertex2,1 });
            }
            else
            {
                auto updatedInDegreeCount = inDegreeCount.find(vertex2);
                updatedInDegreeCount->second = updatedInDegreeCount->second + 1;
            }
            break;
        }
    }

    // Print in-degree count
    std::cout << std::endl;
    for (auto const& pair : inDegreeCount)
    {
        std::cout << "In-degree[" << pair.first << "]:  " << pair.second << "\n";
    }

    graph.kahnSort();

    return 0;
}


// Constructor
Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new std::list<int>[numVertices];
}

// Adds an edge pair to the adjacency list
void Graph::addEdge(int from, int to)
{
    adjacencyList[from].push_back(to);
}

// Khan algorithm - conducts topological sort
void Graph::kahnSort()
{
    // Initialize variables
    std::vector<int> inDegreeCount(numVertices, 0);
    std::vector<int> sortedTopological;
    int cycleCount = 0;

    // Go through adjacency list and count in-degrees for each vertex
    for (int i = 0; i < numVertices; i++)
    {
        std::list<int>::iterator it;
        for (it = adjacencyList[i].begin(); it != adjacencyList[i].end(); it++)
        {
            inDegreeCount[*it]++;
        }
    }

    // Khan algorithm - add all vertices with an in-degree count of 0 to a queue
    std::queue<int> vertexQueue;
    for (int i = 0; i < numVertices; i++)
    {
        if (inDegreeCount[i] == 0)
        {
            vertexQueue.push(i);
        }
    }

    // Khan algorithm - deque vertices and update in-degree for adjacent vertices
    while (!vertexQueue.empty())
    {
        // The front of the vertex queue is added to the sorted list
        int vertexQueueFront = vertexQueue.front();
        vertexQueue.pop();
        sortedTopological.push_back(vertexQueueFront);

        // Update adjacency list for all vertices adjacent to the popped value (-1 to in-degree)
        std::list<int>::iterator i;
        for (i = adjacencyList[vertexQueueFront].begin(); i != adjacencyList[vertexQueueFront].end(); i++)
        {
            // Add values with in-degree == 0 to the vertex queue
            inDegreeCount[*i]--;
            if (inDegreeCount[*i] == 0)
            {
                vertexQueue.push(*i);
            }
        }

        cycleCount++;
    }

    // Cycle check - If there was a cycle, exit function and print 'no order'
    if (cycleCount != numVertices)
    {
        std::cout << "No Order:";
        return;
    }

    // Print topologically sorted list
    std::cout << "Order: ";
    int i = 0;
    for (i = 0; i < sortedTopological.size() - 1; i++)
    {
        std::cout << sortedTopological[i] << "->";
    }
    std::cout << sortedTopological[i];
}
