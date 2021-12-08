/* Title: hw5_3.cpp
 * Abstract: This program simulate the operations of linear probing covered in the lecture. 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 12/07/21
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	// Arr of prime numbers < 200
	int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

	// Get initial parameters
	int tableSize, numCommands;
	std::cin >> tableSize >> numCommands;

	//Initialize all variables
	std::vector<int> numbers(tableSize, -1);
	std::vector<std::string> savedOutput;
	float currentLoadFactor = 0.0;
	const float MAX_LOAD_FACTOR = 0.5;
	int storedNums = 0;

	//Run commands
	while (numCommands > 0)
	{
		
		if (currentLoadFactor > MAX_LOAD_FACTOR) // Rehashing
		{
			// Resize vector and update table size
			for (int prime : primeNumbers)
			{
				int minNewTableSize = 2 * tableSize;
				if(prime >= minNewTableSize)
				{
					numbers.resize(prime, -1);
					tableSize = prime;
					break;
				}
			}

			// Get all values currently in table
			std::vector<int> tempNums;
			for(int i = 0; i < tableSize; i++)
			{
				if(numbers[i] >= 0)
				{
					tempNums.push_back(numbers[i]);
					numbers[i] = -1;
				}
			}

			// Reassign values
			for(int i = 0; i < tempNums.size(); i++)
			{
				int newIndex = tempNums[i] % tableSize;
				// Linear probing
				while(numbers[newIndex] != -1)
				{
					newIndex++;
				}
				// Assign index if not out of range
				if(newIndex < tableSize)
				{
					numbers[newIndex] = tempNums[i];
				}
			}

			// Recalculate load factor
			currentLoadFactor = 1.0 * tempNums.size() / tableSize;
		}
		else // Get and execute commands
		{
			std::string command;
			std::cin >> command;

			if (command == "insert")
			{
				int newNum;
				std::cin >> newNum;

				int newIndex = newNum % tableSize;

				// Linear probing
				while (numbers[newIndex] != -1)
				{
					newIndex++;
				}
				// Assign index if not out of range
				if (newIndex < tableSize)
				{
					numbers[newIndex] = newNum;
					storedNums++;
					currentLoadFactor = 1.0 * storedNums / tableSize;
				}

				numCommands--;
			}
			else if (command == "displayStatus")
			{
				int queryIndex;
				std::cin >> queryIndex;

				// Checks status of value at the given index location
				if(numbers[queryIndex] == -1)
				{
					savedOutput.push_back("Empty");
				}
				else
				{
					savedOutput.push_back(std::to_string(numbers[queryIndex]));
				}

				numCommands--;
			}
			else if (command == "tableSize")
			{
				savedOutput.push_back(std::to_string(tableSize));

				numCommands--;
			}
			else if (command == "search")
			{
				int queryKey;
				std::cin >> queryKey;

				// Looks for value using modular position in hash table, including linear probing
				bool queryKeyFound = false;
				for (int i = queryKey % tableSize; i < tableSize && numbers[i] != -1; i++)
				{
					if (numbers[i] == queryKey)
					{
						queryKeyFound = true;
					}
				}

				savedOutput.push_back(std::to_string(queryKey) + " " + (queryKeyFound ? "Found" : "Not found"));
				numCommands--;
			}
		}
	}

	// print output
	for(int i = 0; i < savedOutput.size(); i++)
	{
		std::cout << savedOutput[i] << std::endl;
	}

	return 0;
}