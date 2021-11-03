/* Title: hw1_1.cpp
 * Abstract: This program converts a directed graph data from a user 
 *			 into a corresponding adjacency list format. 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/02/21
 */

#include <iostream>

int main() {
    // Initialize variables
    const int MAX_VERTICES = 50;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = { 0 };
    int vertices, edges;

    // Get user input and update adjacency matrix
    std::cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) 
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        adjacencyMatrix[v1][v2] = 1;
    }

    // Output - prints adjacency matrix as adjacency list
    for (int v1 = 0; v1 < vertices; v1++) 
    {
	    std::cout << v1;
        for (int v2 = 0; v2 < vertices; v2++) 
        {
            if (adjacencyMatrix[v1][v2] == 1)
            {
            	std::cout << "->" << v2;
            }
        }

	    std::cout << std::endl;
    }

    return 0;
}