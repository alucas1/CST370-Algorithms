/* Title: hw0_2.cpp
 * Abstract: This program calculates the Min, Max, and Median of five numbers.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 10/26/21
 */

#include <algorithm>
#include <iostream>

int main()
{
	// Initialize variables
	const int MAX_INPUT = 5;
	int arr[MAX_INPUT] = {0};
	int x, min, max, median;

	// Read input
	for (int i = 0; i < MAX_INPUT; i++)
	{
		std::cin >> x;
		arr[i] = x;

		if (i == 0)
		{
			min = max = x;
		}

		if (x > max)
		{
			max = x;
		}

		if (x < min)
		{
			min = x;
		}
	}

    // Sort array
	std::sort(arr, arr + MAX_INPUT);

	// Output
	std::cout << "MIN:" << min << std::endl;
	std::cout << "MAX:" << max << std::endl;
	std::cout << "MEDIAN:" << arr[2] << std::endl;

	return 0;
}

