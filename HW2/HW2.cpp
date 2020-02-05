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
        int mergeComps, quickComps;
        SortHandler.mergeSort(mergeSortArr, threshold, 0, size - 1, mergeComps);
        SortHandler.quickSort(quickSortArr, threshold, 0, size - 1, quickComps);

        string unsortedStr, mergeSortStr, quickSortStr;
        if (size <= 15 && display == 'y') {
            for (int i = 0; i < size; i++) {
                unsortedStr += " " + unsortedArr[i];
                mergeSortStr += " " + mergeSortStr[i];
                quickSortStr += " " + quickSortStr[i];
            }

            unsortedStr = unsortedStr.substr(1, unsortedStr.length());
            mergeSortStr = mergeSortStr.substr(1, mergeSortStr.length());
            quickSortStr = quickSortStr.substr(1, quickSortStr.length());

            cout << "Unsorted array: " << unsortedStr << endl;
            cout << "Merge-sorted array: " << mergeSortStr << endl;
            cout << "Quick-sorted array: " << quickSortStr << endl;
        }

        cout << "Mergesort comparisons: " << mergeComps << endl;
        cout << "Quicksort comparisons: " << quickComps << endl;

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