// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <array>
#include <iostream>
#include <string>
#include "SortHandler.h"
#include <time.h>
#include "HW2.h"

using namespace std;

int main() {
    // Seed random number generator
    srand((unsigned)time(0));

    // Declare variables
    int threshold, size;
    char mode, display;
    string strList;
    SortHandler SortHandler;

    while (true) {
        // Clear console and set defaults
        system("cls");
        mode = 'n';
        display = 'n';

        // Begin outputting the menu and documentation for use
        cout << "This program allows you to use compare mergesort and quicksort." << endl
             << "You will be asked to provide a threshold value and the size of a list. If the size is greater than 15, the list will be auto randomized." << endl
             << "If the size is less than or equal to 15, you can specify to enter in your own values, or to have the list randomized." << endl
             << "If the size is less than or equal to 15, you may opt to display both the sorted and unsorted lists." << endl << endl;

        cout << "Please enter the threshold value: ";
        cin >> threshold;
        cout << "Please enter the list size: ";
        cin >> size;

        if (size <= 15) {
            cout << "Would you like to manually enter this list (y = manual, n = randomize this list)? ";
            cin >> mode;

            cout << "Would you like to display both the sorted and unsorted lists (y/n)? ";
            cin >> display;
        }

        cout << endl;
        
        // Create a new array of specified size
        int* unsortedArr = new int[size];
        if (mode == 'n') {
            // If it's random, get numbers for each index
            for (int i = 0; i < size; i++) {
                unsortedArr[i] = (rand() % 1000) + 1; //random number between 1 and 1000
            }
        }
        else {
            // Start getting numbers if we want to input stuff manually
            int arrInd = 0;
            int num;

            while (arrInd < size) {
                cout << "Please enter the " << (arrInd + 1) << " list value: ";
                cin >> num;

                unsortedArr[arrInd] = num;
                arrInd++;
            }
        }

        // Since we are merging and quick sorting the original array, make copies of the unsorted one
        int* mergeSortArr = new int[size];
        int* quickSortArr = new int[size];

        for (int i = 0; i < size; i++) {
            mergeSortArr[i] = unsortedArr[i];
            quickSortArr[i] = unsortedArr[i];
        }

        // Init the comparisons for each sorting algorithm
        // We will also record the threshold comparisons
        int mergeComps = 0;
        int quickComps = 0;
        int mergeThreshComps = 0;
        int quickThreshComps = 0;

        // Do the sorting!
        SortHandler.mergeSort(mergeSortArr, threshold, 0, size - 1, mergeComps, mergeThreshComps);
        SortHandler.quickSort(quickSortArr, threshold, 0, size - 1, quickComps, quickThreshComps);

        string unsortedStr, mergeSortStr, quickSortStr;

        // If we want to display the lists, go ahead and do it!
        if (display == 'y') {
            // Construct array strings
            for (int i = 0; i < size; i++) {
                unsortedStr += " " + to_string(unsortedArr[i]);
                mergeSortStr += " " + to_string(mergeSortArr[i]);
                quickSortStr += " " + to_string(quickSortArr[i]);
            }

            // Remove the first space from the strings
            unsortedStr = unsortedStr.erase(0, 1);
            mergeSortStr = mergeSortStr.erase(0, 1);
            quickSortStr = quickSortStr.erase(0, 1);

            // Output the arrays
            cout << "Unsorted array: " << unsortedStr << endl;
            cout << "Merge-sorted array: " << mergeSortStr << endl;
            cout << "Quick-sorted array: " << quickSortStr << endl;
        }

        // Output the comparison counts for each sorting algorithm
        cout << "Mergesort comparisons: " << to_string(mergeComps) << endl;
        cout << "Mergesort threshold comparisons: " << to_string(mergeThreshComps) << endl;

        cout << "Quicksort comparisons: " << to_string(quickComps) << endl;
        cout << "Quicksort threshold comparisons: " << to_string(quickThreshComps) << endl;

        // Since we create new arrays dynamically, we have to delete the memory space
        delete[] unsortedArr;
        delete[] mergeSortArr;
        delete[] quickSortArr;

        // Determine whether we should continue running the program
        char notDone;
        cout << "Would you like run this again (y/n)? ";
        cin >> notDone;

        if (notDone == 'n') {
            break;
        }
    }
}