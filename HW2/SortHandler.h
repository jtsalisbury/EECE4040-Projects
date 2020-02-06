#ifdef SORTING_EXPORTS
#define SortHandler_API __declspec(dllexport)
#else
#define SORTING_API __declspec(dllimport)
#endif

class SORTING_API SortHandler
{
public:
	void insertionSort(int* arr, int first, int last, int& comparison);

	void merge(int* arr, int threshold, int first, int mid, int last, int& comparison);
	void mergeSort(int* arr, int threshold, int first, int last, int& comparison, int& thresholdComparisons);

	int quick(int* arr, int first, int last, int& comparison);
	void quickSort(int* arr, int threshold, int first, int last, int& comparison, int& thresholdComparisons);
};

