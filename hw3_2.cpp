/* Title: hw3_2.cpp
 * Abstract: This program reads an input graph data from a user.
 *           Then, it presents an optimal path for the traveling salesman problem (TSP). 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/16/21
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

void solveTSP(std::vector<std::vector<int>> &adjMatrix, int startingVertex);

int main()
{
    // Declared variables
    int numVertices, numEdges;
    int srcVertex, destVertex, cost;
    int startingVertex;

    // Receive and store input in adjacency matrix
    std::cin >> numVertices >> numEdges;
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, INT_MAX));
    for (int i = 0; i < numEdges; i++)
    {
        std::cin >> srcVertex >> destVertex >> cost;
        adjMatrix[srcVertex][destVertex] = cost;
    }

    // Get starting vertex
    std::cin >> startingVertex;

    // Print TSP solution
    solveTSP(adjMatrix, startingVertex);

    return 0;
}

/*
 * Accepts information from a directed graph to produce a solution to the
 * traveling salesman problem. Solution path and cost are printed as output.
 * @param       adjMatrix  A vector containing information about the graph
 * @param startingVertex  The starting vertex in the traveling salesman problem
 */
void solveTSP(std::vector<std::vector<int>> &adjMatrix, int startingVertex)
{
    // Declare variables
    std::vector<int> optimalPath;
    std::vector<int> vertices;
    int minPath = INT_MAX;

    // Creates a list of all the vertices excluding the starting vertex
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (i != startingVertex)
        {
            vertices.push_back(i);
	    }
    }

    // Vector to store the optimal path of the TSP solution
    optimalPath.assign(vertices.begin(), vertices.end());

	// Calculate path cost for each permutation of the path circuit
    do {
        int pathCost = 0;

        // Compute path cost
        int currentVertex = startingVertex;
        for (int vertex: vertices) {
            // If the cost is int_max, there is no path from the current vertex
            if (adjMatrix[currentVertex][vertex] == INT_MAX)
            {
                pathCost = INT_MAX;
                break;
            }
            // Otherwise add the cost to the running sum if a path is found
        	pathCost += adjMatrix[currentVertex][vertex];
        	currentVertex = vertex;
        }

        // Adds cost to last vertex into running sum
        if (pathCost < INT_MAX)
        {
	        pathCost += adjMatrix[currentVertex][startingVertex];
        }

        // Check and update the minimum cost path (optimal path)
        if (pathCost < minPath)
        {   // Update the optimal path with the current permutation
            optimalPath.assign(vertices.begin(), vertices.end());
            minPath = pathCost;
        }
    } while(next_permutation(vertices.begin(), vertices.end()));

    // Prints optimal path if it exists.
    if (minPath < INT_MAX && minPath >= 0)
    {
	    std::cout << "Path : " << startingVertex << "->";
        for (auto i : optimalPath)
        {
	        std::cout << i << "->";
	    }
	    std::cout << startingVertex << std::endl << "Cost : " << minPath;
    }
    else 
    {
	    std::cout << "Path : " << std::endl << "Cost : -1";
    }
}

