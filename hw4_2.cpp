/* Title: hw4_2.cpp
 * Abstract: This program displays the biggest number in an array with n integer
 *			 numbers using a divide-and-conquer technique.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/30/21
 */

#include <iostream>
#include <vector>

int findMaxValue(std::vector<int> numbers, int lower, int upper);

int main()
{
	// Get input
	int numInput, input;
	std::vector<int> numbers;

	std::cin >> numInput;
	numbers.resize(numInput, 0);
	for(int i = 0; i < numInput; i++)
	{
		std::cin >> input;
		numbers[i] = input;
	}

	// Get the value of the greatest integer in the vector of numbers
	int greatestVal = findMaxValue(numbers, 0, numInput - 1);
	std::cout << greatestVal;

	return 0;
}

// Uses a divide and conquer strategy to find the greatest value in a vector
int findMaxValue(std::vector<int> numbers, int lower, int upper) {
	// Base case - returns value when subvector is size 1
	if (lower == upper)
	{
		return numbers[lower];
	}

	// Divide the vector into two subvectors and calculate max value recursively
	int middle = (lower + upper) / 2;
	int leftHalf = findMaxValue(numbers, lower, middle);
	int rightHalf = findMaxValue(numbers, middle + 1, upper);

	// Return the highest value at each comparison
	int maxVal = leftHalf > rightHalf ? leftHalf : rightHalf;
	return maxVal;
}