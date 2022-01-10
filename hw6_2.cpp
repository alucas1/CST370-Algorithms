/* Title: hw6_2.cpp
 * Abstract: This program implements the Floyd algorithm to display all-pairs shortest paths.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 12/14/21
 */

#include <iostream>
#include <vector>
#include <climits>

void printMatrix(std::vector<std::vector<int>> matrix);
void floydAlgorithm(std::vector<std::vector<int>> &distances, int vertices);

int main()
{
    int vertices, distance;
    std::vector<std::vector<int>> distances;

    // Get vertices
    std::cin >> vertices;
    distances.resize(vertices);

    // Get distances as 2d matrix of input
    for(int i = 0; i < vertices; i++)
    {
	    for(int j = 0; j < vertices; j++)
	    {
		    std::cin >> distance;
            if(distance == -1)
            {
	            distance = INT_MAX;
            }
            distances[i].push_back(distance);
	    }
    }
    std::cout << std::endl;

    // Run Floyd algorithm
    floydAlgorithm(distances, vertices);

    // Print results
    printMatrix(distances);

    return 0;
}

// Implements Floyd's algorithm for the all-pairs shortest-paths problem
// @param distances - The weight matrix of a graph with no negative-length cycle
// @param vertices  - The total number of vertices
void floydAlgorithm(std::vector<std::vector<int>> &distances, int vertices)
{
    for (int k = 0; k < vertices; k++) 
    {
        for (int i = 0; i < vertices; i++) 
        {
            for (int j = 0; j < vertices; j++) 
            {
                if (distances[i][j] > (distances[i][k] + distances[k][j]))
                {
                    if (distances[k][j] != INT_MAX && distances[i][k] != INT_MAX)
                	{
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
	            }
            }
        }
    }
}

// Prints a 2d matrix represented by vectors (must be size nxn)
// @param printMatrix - The matrix to print to the console
void printMatrix(std::vector<std::vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if(matrix[i][j] == INT_MAX)
            {
	            std::cout << "-1" << " ";
            }
            else
            {
	            std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}