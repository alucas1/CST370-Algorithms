/* Title: hw2_2.cpp
 * Abstract: This program reads a number of elements in a set.
 *			 Then, the program reads the elements of the set.
 *			 The program then displays all possible decimal numbers,
 *			 corresponding binary numbers, and subsets one by one.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/09/21
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

void increment(std::vector<int> &v);

int main()
{
	// Initialize variables
	int setSize = 0;
	std::vector<int> binaryArr(10, 0);
	std::vector<std::string> input;

	// Get input
	std::cin >> setSize;

	// Check if set size is empty. Otherwise continue with program
	if(setSize == 0)
	{
		// If set is empty
		std::cout << "0:0:EMPTY";
	}
	else
	{
		// Get user input
		for (int i = 0; i < setSize; i++)
		{
			std::string in;
			std::cin >> in;
			input.push_back(in);
		}

		// Print output
		for (int i = 0; i < pow(2, setSize); i++)
		{
			// Prints the index
			std::cout << i << ":";

			//Prints the binary representation
			for (int j = 0; j < setSize; j++)
			{
				std::cout << binaryArr[binaryArr.size() - setSize + j];
			}
			std::cout << ":";

			//Prints the corresponding set element
			if (i == 0)
			{
				std::cout << "EMPTY";
			}
			else
			{
				// Checks each corresponding bit and input elements.
				// If bit it true(1), the corresponding element is printed
				for (int j = 0; j < setSize; j++)
				{
					if (binaryArr[binaryArr.size() - setSize + j] == true)
					{
						std::cout << input[j] << " ";
					}
				}
			}
			std::cout << std::endl;

			// Calculate new Binary and setup vars for next iteration
			increment(binaryArr);
		}
	}

	return 0;
}

/*
 * Increments a binary number stored in a vector from left to right
 * @param  &v	A reference to a vector storing bits (0, 1)
 */
void increment(std::vector<int> &v)
{
	// Goes through the binary number starting from the end
	for (int i = v.size() - 1; i >= 0; --i)
	{
		// If it is not 0, flip it to 1
		if (!v[i])
		{
			v[i] = true;
			return;
		}
		v[i] = false;
	}
}