#include "SortHandler.h"
#include <iostream>
using namespace std;

//insertion sort implementation
//Preconditions: Unsorted list that hit the threshold for either mergesort or quicksort, now to be sorted by insertion sort
//Inputs: List of type array, first int, last int, and address of comparison
//Postconditions: The list will be sorted by insertion comparisons. Each time there is a comparison, the comparison value will be incremented
void SortHandler::insertionSort(int* arr, int first, int last, int& comparison) {
	for (int i = first; i <= last; i++) {
		int next = arr[i];
		int loc = i - 1;

		//move elements that are greater than next
		while (loc >= 0 && arr[loc] > next) {
			comparison++;
			arr[loc + 1] = arr[loc];
			loc--;
		}

		arr[loc + 1] = next;
	}
	// cout << "insert done " << comparison<<endl; //debugging 
}

//helper function for merge 
void SortHandler::merge(int* arr, int threshold, int first, int mid, int last, int& merge_comparison) {
	//create temp array
	int temp[25000];

	int first1 = first;
	int last1 = mid;

	int first2 = mid + 1;
	int last2 = last;

	int i = first1;
	//merge the temp array back into array
	while ((first1 <= last1) && (first2 <= last2)) {
		merge_comparison +=2; //comparison for while loop and if statements
		if (arr[first1] <= arr[first2]) {
			temp[i] = arr[first1];
			first1++;
		}
		else {
			temp[i] = arr[first2];
			first2++;
		}
		i++;
	}

	//copy the remaining elements
	while (first1 <= last1) {
		merge_comparison++;
		temp[i] = arr[first1];
		first1++;
		i++;
	}

	while (first2 <= last2) {
		merge_comparison++;
		temp[i] = arr[first2];
		first2++;
		i++;
	}

	for (i = first; i <= last; i++) {
		arr[i] = temp[i];
	}
}

//mergesort implementation 
//Preconditions: An unsorted list of type array
//Inputs: Unsorted list in type array, threshold value (user input), first int, last in, threshold comparison addresses
//Postconditions: List will be sorted using mergesort algorithm, until the list hits the threshold, it which the sorted will be finished by insertion sort
void SortHandler::mergeSort(int* arr, int threshold, int first, int last, int& merge_comparison, int& thresholdComparisons) {
	if (last - first + 1 <= threshold) {
		merge_comparison++;
		insertionSort(arr, first, last, thresholdComparisons);
		//cout << last - first << endl; //check size of list
	}
	else if (first < last) {
		merge_comparison++;

		int mid = first + (last - first) / 2;
		//sort both halves 
		mergeSort(arr, threshold, first, mid, merge_comparison, thresholdComparisons);
		mergeSort(arr, threshold, mid + 1, last, merge_comparison, thresholdComparisons);
		//put them together 
		merge(arr, threshold, first, mid, last, merge_comparison);
	}
}

//helper function for quick sort 
int SortHandler::quick(int* arr, int first, int last, int& quick_comparison) {
	//pivot 
	int pi = arr[last];
	int i = (first - 1);
	int t;

	for (int j = first; j <= last - 1; j++)  {
		quick_comparison++;
		//if element is smaller than pivot 
		if (arr[j] <= pi) 
		{
			i++;

			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	t = arr[i + 1];
	arr[i + 1] = arr[last];
	arr[last] = t;
	return (i + 1);
}

//quicksort implementation
//Preconditions: An unsorted list of type array
//Inputs: Unsorted list in type array, threshold value (user input), first int, last in, threshold comparison addresses
//Postconditions: List will be sorted using quicksort alogrithm, until the list hits the threshold, it which the sorted will be finished by insertion sort
void SortHandler::quickSort(int* arr, int threshold, int first, int last, int& quick_comparison, int& thresholdComparisons) {
	if (last - first + 1 <= threshold) {
		quick_comparison++;
		insertionSort(arr, first, last, thresholdComparisons);
	} 
	else if (first < last) {
		quick_comparison++;
		//call quick sort helper to partition the index
		int pivot = quick(arr, first, last, quick_comparison);

		quickSort(arr, threshold, first, pivot - 1, quick_comparison, thresholdComparisons);
		quickSort(arr, threshold, pivot + 1, last, quick_comparison, thresholdComparisons);
	}
}
