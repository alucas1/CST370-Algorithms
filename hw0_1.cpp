/* Title: hw0_1.cpp
 * Abstract: This program calculates the sum and difference of two numbers.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 10/26/21
 */

#include <iostream>

int main()
{
	int a, b;

	std::cin >> a >> b;

	std::cout << "SUM:" << a + b << std::endl;
	std::cout << "DIFF:" << abs(a - b) << std::endl;

	return 0;
}