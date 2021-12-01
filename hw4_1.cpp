/* Title: hw4_1.cpp
 * Abstract: This program reads a number of input values and the values themselves.
 *           Then, the program puts all negative numbers in front of all positive 
 *			 numbers. 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/30/21
 */

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);
void swap(int& a, int& b);
void approach1Sort(std::vector<int>& v);
void approach2Sort(std::vector<int>& v);

int main()
{
    // Get input
    std::vector<int> numbers1;
    int numInput, input;

    std::cin >> numInput;

    for(int i = 0; i < numInput; i++)
    {
        std::cin >> input;
        numbers1.push_back(input);
    }
    std::vector<int> numbers2(numbers1);

    // Sort vector - first approach
    approach1Sort(numbers1);
    printVector(numbers1);
    std::cout << std::endl;

    // Sort vector - second approach
    approach2Sort(numbers2);
    printVector(numbers2);

    return 0;
}


// Prints the contents of a vector
void printVector(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}

// Swaps two integer values by reference
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Sorts a vector of integers by putting all negative values to the left of positive values
// Uses two indices(i,j) starting at opposing ends of the vector (Approach 1) 
void approach1Sort(std::vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] >= 0)
        {
            if (v[j] < 0)
            {
                swap(v[i], v[j]);
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
}

// Sorts a vector of integers by putting all negative values to the left of positive values
// Uses two indices(i,j) starting at the beginning of the vector (Approach 2).
void approach2Sort(std::vector<int> &v)
{
    int i = 0;
	int j = 0;
    while (j < v.size())
    {
        if (v[i] >= 0 && v[j] >= 0)
        {
            j++;
        }
        else if ((v[i] < 0 && v[j] >= 0) || (v[i] < 0 && v[j] < 0))
        {
            i++;
            j++;
        }
        else if (v[i] >= 0 && v[j] < 0)
        {
            swap(v[i], v[j]);
        }
    }
}