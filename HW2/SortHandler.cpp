#include "SortHandler.h"
#include <iostream>

//insertion sort implementation
int SortHandler::insertionSort(int* arr, int threshold, const int len, int& comparison)
{
	for (int i = 1; i < len; i++) 
	{
		int next = arr[i];
		int loc = i - 1;

		while (loc >= 0 && arr[loc - 1] > next) 
		{
			comparison++;
			arr[loc + 1] = arr[loc];
			loc--;
		}

		arr[loc + 1] = next;
	}

	return 0;
}

//helper function for merge 
void SortHandler::merge(int* arr, int threshold, int first, int mid, int last, int& comparison)
{
	int temp[25000];

	int first1 = first;
	int last1 = mid;

	int first2 = mid + 1;
	int last2 = last;

	int i = first1;
	while ((first1 <= last1) && (first2 <= last2)) 
	{
		comparison++;
		if (arr[first1] <= arr[first2]) 
		{
			temp[i] = arr[first1];
			first1++;
		}
		else 
		{
			temp[i] = arr[first2];
			first2++;
		}
		i++;
	}

	while (first1 <= last1) 
	{
		comparison++;
		temp[i] = arr[first1];
		first1++;
		i++;
	}

	while (first2 <= last2) 
	{
		comparison++;
		temp[i] = arr[first2];
		first2++;
		i++;
	}

	for (i = first; i <= last; i++) 
	{
		arr[i] = temp[i];
	}
}

//mergesort implementation 
int SortHandler::mergeSort(int* arr, int threshold, int first, int last, int& comparison) {
	if (first < last) {

		int mid = first + (last - first) / 2;

		mergeSort(arr, threshold, first, mid, comparison);
		mergeSort(arr, threshold, mid + 1, last, comparison);

		merge(arr, threshold, first, mid, last, comparison);

		return 0;
	}
}

//helper function for quick sort 
int SortHandler::quick(int* arr, int first, int last, int& comparison) {
	int pi = arr[last];
	int i = (first - 1);
	int t;

	for (int j = first; j <= last - 1; j++) 
	{
		comparison++;
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
int SortHandler::quickSort(int* arr, int threshold, int first, int last, int& comparison)
{
	if (first < last) 
	{
		int pivot = quick(arr, first, last, comparison);

		quickSort(arr, threshold, first, pivot - 1, comparison);
		quickSort(arr, threshold, pivot + 1, last, comparison);

		return 0;
	}
}
