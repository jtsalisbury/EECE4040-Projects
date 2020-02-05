#ifdef SORTING_EXPORTS
#define SORTINGALGORITHMS_API __declspec(dllexport)
#else
#define SORTING_API __declspec(dllimport)
#endif

#include <vector>

class SORTING_API SortMenu 
{
public:
	int insertionSort(int* arr, int threshold, const int len, int& comparison);

	void merge(int* arr, int threshold, int first, int mid, int last, int& comparison);
	int mergeSort(int* arr, int threshold, int first, int last, int& comparison);

	int quick(int* arr, int first, int last);
	int quickSort(int* arr, int threshold, int first, int last, int& comparison);
};

