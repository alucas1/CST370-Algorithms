/* Title: hw6_1.cpp
 * Abstract: This program simulates the collection of a maximum number of coins on an n x m board.
 *           The seeking starts at the top-left of the board and movement is restricted to the right
 *           and bottom of the board.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 12/14/21
 */

#include <iostream>
#include <vector>

void coinPath(int row, int column, std::vector<std::vector<int>> &board, int coins, std::vector<std::pair<int, int>>currentPath, std::vector<std::pair<int, int>>& optimalPath, int &maxCoins);

int main()
{
    // Get initial parameters
    int rows, columns;
    std::cin >> rows >> columns;
    std::vector<std::vector<int>> board(rows, std::vector<int>(columns));

    // Initialize position of coins on board
	for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
	        std::cin >> board[i][j];
        }
    }

    // Initialize variables
    std::vector<std::pair<int, int>> currentPath;
    std::vector<std::pair<int, int>> optimalPath;
    int currentPathCoins = 0;
    int maxCoins = -1;

    // Find optimal path
    coinPath(0, 0, board, currentPathCoins, currentPath, optimalPath, maxCoins);

    // Print output
    std::cout << "Max coins:" << maxCoins << std::endl;
    std::cout << "Path: ";
    for (std::pair<int, int> p : optimalPath) 
    {
	    std::cout << "(" << p.first << "," << p.second << ")";
        if (p.first == rows && p.second == columns)
        {
	        std::cout << std::endl;
        }
        else
        {
	        std::cout << "->";
        }
    }

    return 0;
}

// Looks through the board and keeps a running sum of all coins at each cell. Seeking
// starts at the top left of the board and movement is restricted to right and downward
// seeks.
void coinPath(int row, int column, std::vector<std::vector<int>>& board, int coins, std::vector<std::pair<int, int>> currentPath, std::vector<std::pair<int, int>> &optimalPath, int &maxCoins)
{
    // Return if board borders are exceeded
    if (row >= board.size() || column >= board[0].size()) 
    {
        return;
    }

    // Add current cell to the current path as a vertice-vertice pair
    currentPath.push_back({ row + 1, column + 1 });

    // On the last cell, if the current coins exceeds the max coins, update
    // the optimal path and max coins.
    if ((row == board.size() - 1) && (column == board[0].size() - 1)) 
    {
        if (coins + board[row][column] > maxCoins) 
        {
            maxCoins = coins + board[row][column];
            optimalPath = currentPath;
        }

        return;
    }

    // Seek through the board recursively, adding coins at each cell
    int currentCoins = coins + board[row][column];
    coinPath(row + 1, column, board, currentCoins, currentPath, optimalPath, maxCoins);
    coinPath(row, column + 1, board, currentCoins, currentPath, optimalPath, maxCoins);
}
