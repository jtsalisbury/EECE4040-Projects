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
    srand((unsigned)time(0));

    int threshold, size;
    char mode, display;
    string strList;
    SortHandler SortHandler;

    while (true) {
        system("cls");
        mode = 'n';
        display = 'n';

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

        int* unsortedArr = new int[size];
        if (mode == 'n') {
            for (int i = 0; i < size; i++) {
                unsortedArr[i] = (rand() % 1000) + 1; //random number between 1 and 1000
            }
        }
        else {
            int arrInd = 0;
            int num;

            while (true) {
                cout << "Please enter the " << (arrInd + 1) << " list value: ";
                cin >> num;

                unsortedArr[arrInd] = num;
                arrInd++;

                if (arrInd >= size) {
                    break;
                }
            }
        }

        int* mergeSortArr = new int[size];
        int* quickSortArr = new int[size];

        for (int i = 0; i < size; i++) {
            mergeSortArr[i] = unsortedArr[i];
            quickSortArr[i] = unsortedArr[i];
        }

        // todo 
        int mergeComps = 0;
        int quickComps = 0;
        int mergeThreshComps = 0;
        int quickThreshComps = 0;
        SortHandler.mergeSort(mergeSortArr, threshold, 0, size - 1, mergeComps, mergeThreshComps);
        SortHandler.quickSort(quickSortArr, threshold, 0, size - 1, quickComps, quickThreshComps);

        string unsortedStr, mergeSortStr, quickSortStr;
        if (display == 'y') {
            for (int i = 0; i < size; i++) {
                unsortedStr += " " + to_string(unsortedArr[i]);
                mergeSortStr += " " + to_string(mergeSortArr[i]);
                quickSortStr += " " + to_string(quickSortArr[i]);
            }

            unsortedStr = unsortedStr.erase(0, 1);
            mergeSortStr = mergeSortStr.erase(0, 1);
            quickSortStr = quickSortStr.erase(0, 1);

            cout << "Unsorted array: " << unsortedStr << endl;
            cout << "Merge-sorted array: " << mergeSortStr << endl;
            cout << "Quick-sorted array: " << quickSortStr << endl;
        }

        cout << "Mergesort comparisons: " << to_string(mergeComps) << endl;
        cout << "Mergesort threshold comparisons: " << to_string(mergeThreshComps) << endl;

        cout << "Quicksort comparisons: " << to_string(quickComps) << endl;
        cout << "Quicksort threshold comparisons: " << to_string(quickThreshComps) << endl;

        char notDone;
        cout << "Would you like run this again (y/n)? ";
        cin >> notDone;

        if (notDone == 'n') {
            break;
        }

        delete[] unsortedArr;
        delete[] mergeSortArr;
        delete[] quickSortArr;
    }
}