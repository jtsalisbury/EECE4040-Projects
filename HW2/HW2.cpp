// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
        mode = 'n';

        cout << "This program allows you to use compare mergesort and quicksort." << endl
             << "You will be asked to provide a threshold value and the size of a list to compare. If the size is greater than 15, the list will be auto randomized." << endl
             << "If the size is less than or equal to 15, you can specify to enter in your own values, or to have the list randomized." << endl
             << "If the size is less than or equal to 15, you may opt to display both the sorted and unsorted lists." << endl << endl;

        cout << "Please enter the threshold value: ";
        cin >> threshold;
        cout << endl << "Please enter the list size: ";
        cin >> size;

        if (size <= 15) {
            cout << endl << "Would you like to manually enter this list (y = manual, n = randomize this list)? ";
            cin >> mode;

            cout << endl << "Would you like to display both the sorted and unsorted lists (y/n)? ";
            cin >> display;
        }

        int* arr = new int[size];
        if (mode == 'n') {
            for (int i = 0; i < size; i++) {
                arr[i] = (rand() % 1000) + 1; //random number between 1 and 1000
            }
        }
        else {
            bool invalid = true;

            while (invalid) {
                int spaceCount = 0;
                invalid = false;

                cout << endl << "Please enter in the list values separated by single spaces: ";
                cin >> strList;

                // Quick and dirty validation based on space count
                for (auto letter : strList) {
                    if (letter == ' ') {
                        spaceCount++;
                    }
                }

                // Too many spaces. Don't want to deal with leading or trailing spaces/ extra spaces between words
                if (spaceCount >= size - 1) {
                    invalid = true;
                    cout << endl << "There are too many spaces in this string, please re-enter the list." << endl;
                }
                if (spaceCount < size - 1) {
                    invalid = true;
                    cout << endl << "There aren't enough numbers for the size of " << size << ", please re-enter the list." << endl;
                }

                string word;
                int listInd = 0;

                for (auto letter : strList) {
                    if (letter == ' ') {
                        arr[listInd] = stoi(word);
                        word = "";
                        listInd = listInd + 1;
                    }
                    else {
                        word += letter;
                    }
                }
            }
        }

        delete[] arr;
    }
}