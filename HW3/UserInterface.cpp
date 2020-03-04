#include "UserInterface.h"
#include <iostream>

using namespace std;

void UserInterface::printOptions() {
	cout << endl << "1. Add a new person" << endl <<
		"2. Delete a person" << endl <<
		"3. Find a phone number" << endl <<
		"4. Change someone's phone number" << endl <<
		"5. Display all members" << endl <<
		"6. Quit and save to a file" << endl;
}

bool UserInterface::validateOption(int option) {
	return !(option < 1 || option > 6);
}

void UserInterface::executeOption(Book* book, int option) {
	string fname, lname, number, path;
	vector<string> members;

	switch (option) {
		case 1: 
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			cout << "Please enter the person's phone number: ";
			cin >> number; 

			book->insert(fname, lname, number);
			break;
		case 2: 
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			book->remove(fname, lname);
			break;
		case 3: 
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			number = book->findNumber(fname, lname);
			cout << endl << fname << ' ' << lname << "'s number: " << number;
			break;
		case 4: 
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			cout << "Please enter the person's new phone number: ";
			cin >> number;

			book->change(fname, lname, number);
			break;
		case 5: 
			members = book->getAllAscending();
			cout << endl << "Phonebook Members:" << endl;
			for (int i = 0; i < members.size(); i++) {
				cout << members[i] << endl;
			}
			break;
		case 6:
			cout << "Please enter the full path of where to save the tree: ";
			cin >> path;

			book->saveTree(path);
			m_quit = true;
			break;
	}
}

bool UserInterface::shouldQuit() {
	return m_quit;
}