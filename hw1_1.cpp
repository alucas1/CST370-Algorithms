/* Title: hw1_1.cpp
 * Abstract: This program reads input numbers from a user and displays the
 *			 closest distance between two numbers among all input numbers.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/02/21
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	// Initialize variables
	int numInput = 0;
	std::vector<int> inputNums;
	std::vector<std::pair<int, int>> pairs;

	// Get number of integers that will be input
	std::cin >> numInput;

	// Read Input
	for (int i = 0; i < numInput; i++)
	{
		int input;
		std::cin >> input;
		inputNums.push_back(input);
	}

	// Sort input - ascending order
	std::sort(inputNums.begin(), inputNums.end());

	// Set initial min distance
	int minDistance = abs(inputNums[0] - inputNums[1]);
	pairs.push_back(std::make_pair(inputNums[0], inputNums[1]));

	// Perform Calculations - Check for min distance
	for (int i = 2; i < numInput; i++)
	{
		int difference = abs(inputNums[i - 1] - inputNums[i]);

		if (difference < minDistance)
		{
			// If a new min is found, clear the previously stored pairs
			pairs.clear();
			minDistance = difference;
			pairs.push_back(std::make_pair(inputNums[i - 1], inputNums[i]));
		}
		else if (difference == minDistance)
		{
			pairs.push_back(std::make_pair(inputNums[i - 1], inputNums[i]));
		}
	}

	// Output min distance and matched pairs
	std::cout << "Min Distance:" << minDistance << std::endl;
	for (auto& pair : pairs)
	{
		std::cout << "Pair:" << pair.first << " " << pair.second << std::endl;
	}

	return 0;
}
