/* Title: hw3_1.cpp
 * Abstract: This program first reads the number of input that will be
 *			 entered, and the subsequent input. The program then sorts
 *			 the input in ascending order and prints it out in shortened
 *			 notation (e.g. 1 2 5-19 80 100-129).
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/16/21
 */

#include <iostream>
#include <vector>

void swap(int &x, int &y);
void selectionSort(std::vector<int> &nums);
void printVector(std::vector<int> &nums);

int main()
{
	// Get input
	int inputSize = 0;
	int inputNum = 0;
	std::vector<int> inputNums;

	std::cin >> inputSize;
	for(int i = 0; i < inputSize; i++)
	{
		std::cin >> inputNum;
		inputNums.push_back(inputNum);
	}

	// Sort input - ascending order
	selectionSort(inputNums);

	// Print input in shortened notation
	printVector(inputNums);

	return 0;
}

// Swaps the value of two integers
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Uses selection sort to sort a vector of integers
void selectionSort(std::vector<int> &nums)
{
    int minIndex;
	int maxSize = nums.size();

    for (int i = 0; i < maxSize - 1; i++)
    {
		minIndex = i;
		for (int j = i + 1; j < maxSize; j++)
		{
			if (nums[j] < nums[minIndex])
			{
				minIndex = j;
			}
		}
    	swap(nums[minIndex], nums[i]);
    }
}

// Prints the sorted integer vector in short notation
void printVector(std::vector<int> &nums)
{
	// Checks if vector is empty
	if(!nums.empty())
	{
		// Uses a moving window to detect number ranges
		int windowStart, windowEnd;

		for (int i = 0; i < nums.size(); i++)
		{
			windowStart = windowEnd = nums[i];
			int j = 0;
			//Moves window if a range of numbers are detected
			for (j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] == nums[j - 1] + 1)
				{
					windowEnd = nums[j];
				}
				else
				{
					break;
				}
			}
			if (windowStart == windowEnd) // Prints single values
			{
				std::cout << windowStart << " ";
			}
			else // Prints range of values using window
			{
				std::cout << windowStart << "-" << windowEnd << " ";
			}

			// resolves index position
			i = j - 1;
		}
	}
}