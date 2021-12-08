/* Title: hw5_2.cpp
 * Abstract: This program  displays the performance of two different sorting
 * algorithms (= merge sort and quick sort) on the screen. 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 12/06/21
 * ===========================================================================
 * Credits:
 *         Merge Sort:
 *              Name: C++ program for Merge Sort
 *              Date Obtained: 12/06/21
 *              Author: Mayank Tyagi
 *              Source: https://www.geeksforgeeks.org/merge-sort/
 *          Quick Sort:
 *              Name: C++ implementation of QuickSort
 *              Date Obtained: 12/06/21
 *              Author: rathbhupendra
 *              Source: https://www.geeksforgeeks.org/quick-sort/
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int* a, int* b);
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);

int main()
{
    // Initialize Variables
    const int MAX_NUMS = 1000000;
    int* nums1 = new int[MAX_NUMS];
	int* nums2 = new int[MAX_NUMS];
    int numInput;

    // Generate X amount of random numbers - store two copies
    std::cout << "Enter input size: ";
    std::cin >> numInput;

    // Fill arrays with random numbers
    srand(time(NULL));
    for(int i = 0; i < numInput; i++)
    {
        nums1[i] = rand();
        nums2[i] = nums1[i];
    }

    // Perform quicksort and get times
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(nums1, 0, numInput - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> quickSortDuration = stop - start;

    // Perform mergesort and get times
    start = std::chrono::high_resolution_clock::now();
    mergeSort(nums2, 0, numInput - 1);
    stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeSortDuration = stop - start;

    // Print time table
    std::cout << std::endl;
    std::cout << "===================== Execution Time ====================" << std::endl;
    std::cout << std::setw(14) << std::left << "Merge sort:" << mergeSortDuration.count() << " milliseconds" << std::endl;
    std::cout << std::setw(14) << std::left << "Quick sort:" << quickSortDuration.count() << " milliseconds" << std::endl;
    std::cout << "=========================================================" << std::endl;

    return 0;
}


/* START - C++ implementation of QuickSort */
// This code is contributed by rathbhupendra
// Source: https://www.geeksforgeeks.org/quick-sort/
// ---------------------------------------------------------------

// A utility function to swap two elements 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot 
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------------------------------------------------------
/* END - C++ implementation of QuickSort */




/* START - C++ program for Merge Sort */
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
// Source: https://www.geeksforgeeks.org/merge-sort/
// ---------------------------------------------------------------

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// ---------------------------------------------------------------
/* END - C++ implementation of QuickSort */