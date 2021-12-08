/* Title: hw5_1.cpp
 * Abstract: This program conducts heap operations using a max heap data structure.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 12/06/21
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string checkIfHeap(std::vector<int> v1);

int main()
{
	// initialize variables
	std::vector<int> v1;
	std::vector<std::string> output;
	int numInput, numCommands, input;
	std::string command;

	// get input
	std::cin >> numInput;
	v1.resize(numInput);

	// fill vector and convert to heap
	for(int i = 0; i < numInput; i++)
	{
		std::cin >> input;
		v1[i] = input;
	}
	output.push_back(checkIfHeap(v1));
	make_heap(v1.begin(), v1.end());

	// run commands - heap operations
	std::cin >> numCommands;
	while(numCommands > 0)
	{
		std::cin >> command;

		if(command == "displayMax")
		{
			output.push_back(std::to_string(v1.front()));
		}
		else if(command == "insert")
		{
			std::cin >> input;
			v1.push_back(input);
			push_heap(v1.begin(), v1.end());
		}
		else if (command == "deleteMax")
		{
			pop_heap(v1.begin(), v1.end());
			v1.pop_back();
		}
		else if (command == "display")
		{
			std::string heapNums = "";
			for (int& x : v1)
			{
				heapNums += std::to_string(x) + " ";
			}
			output.push_back(heapNums);
		}

		numCommands--;
	}

	// Print output
	for (std::string& x : output)
	{
		std::cout << x << std::endl;
	}

	return 0;
}

std::string checkIfHeap(std::vector<int> v1)
{
	return is_heap(v1.begin(), v1.end()) ? "This is a heap." : "This is NOT a heap.";
}