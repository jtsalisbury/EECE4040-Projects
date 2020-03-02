// HW3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h"
#include "UserInterface.h"

using namespace std;

int main() {
	UserInterface* ui = new UserInterface();
	int option;
	Book* book;

	cout << "Would you like to create a blank tree (1) or one based off a file (2)? ";
	cin >> option;

	if (option == 1) {
		string filepath;

		cout << "Please enter the full path to the tree file: ";
		cin >> filepath;

		book = new Book(filepath);
	}
	else {
		book = new Book();
	}

	while (!ui->shouldQuit()) {
		while (!ui->validateOption(option)) {
			ui->printOptions();

			cout << "Please enter an option: ";
			cin >> option;
		}

		ui->executeOption(book, option);
	}
}