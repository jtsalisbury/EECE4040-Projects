// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <array>
#include <iostream>
#include <string>
#include "sorting.h"
#include <time.h>

using namespace std;

int main() {
    srand((unsigned)time(0));

    int threshold, size;
    char mode, display;
    string strList;

    while (true) {
        system("cls");
        mode = 'n';

        cout << "This program allows you to use compare mergesort and quicksort." << endl
             << "You will be asked to provide a threshold value and the size of a list to compare. If the size is greater than 15, the list will be auto randomized." << endl
             << "If the size is less than or equal to 15, you can specify to enter in your own values, or to have the list randomized." << endl
             << "If the size is less than or equal to 15, you may opt to display both the sorted and unsorted lists." << endl;

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

        delete[] unsortedArr;
        delete[] mergeSortArr;
        delete[] quickSortArr;
    }
}