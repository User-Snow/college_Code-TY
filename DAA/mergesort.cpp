// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto a = 0, b = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	//a --> indexOfSubarrayOne
	//b --> indexOfSubarrayTwo
	while (a < subArrayOne
		&& b < subArrayTwo) {
		if (leftArray[a]
			<= rightArray[b]) {
			array[indexOfMergedArray]
				= leftArray[a];
			a++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[b];
			b++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (a < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[a];
		a++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (b < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[b];
		b++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = {55, 45, 41, 12, 01, 2, 59 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "\nGiven array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	cout<<"\n";
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
