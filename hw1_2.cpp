/* Title: hw1_1.cpp
 * Abstract: This program reads input numbers from a user and displays 
 *			 the number(s) that occurs most frequently among all the input numbers.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/02/21
 */

#include <iostream>
#include <map>
#include <vector>

int main()
{
	// Initialize variables
	int numInput = 0;
	int maxFrequency = 1;
	std::vector<int> inputNums;
	std::map<int, int, std::greater <int>> frequencyMap;

	// Get number of integers that will be input
	std::cin >> numInput;

	// Read Input
	for (int i = 0; i < numInput; i++)
	{
		int input;
		std::cin >> input;
		inputNums.push_back(input);
	}

	// Update map with vector values
	for (int i = 0; i < numInput; i++)
	{
		// Set freq to 1 if new value is added
		if (frequencyMap.find(inputNums[i]) == frequencyMap.end())
		{
			frequencyMap[inputNums[i]] = 1;
		}
		else // otherwise increment the key's value
		{
			frequencyMap[inputNums[i]]++;
			if(frequencyMap[inputNums[i]] > maxFrequency)
			{
				// check if frequency exceeds current max - if so, save it
				maxFrequency = frequencyMap[inputNums[i]];
			}
		}
	}

	// Print output - Go through map and only print max values
	std::cout << "Frequency:" << maxFrequency << std::endl;
	std::cout << "Number:";
	for (auto& x : frequencyMap) 
	{
		if (maxFrequency == x.second)
		{
			std::cout << x.first << ' ';
		}
	}

	return 0;
}
