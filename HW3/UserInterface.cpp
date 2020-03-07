#include "UserInterface.h"
#include <iostream>

using namespace std;

// Print all the valid options
void UserInterface::printOptions() {
	cout << endl << "1. Add a new person" << endl <<
		"2. Delete a person" << endl <<
		"3. Find a phone number" << endl <<
		"4. Change someone's phone number" << endl <<
		"5. Display all members" << endl <<
		"6. Quit and save to a file" << endl;
}

// Is the option valid?
bool UserInterface::validateOption(int option) {
	return !(option < 1 || option > 6);
}

// Interface with the tree and execute a validated option
void UserInterface::executeOption(Book* book, int option) {
	string fname, lname, number, path;
	vector<string> members;

	switch (option) {
		case 1: // Add a new member
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			cout << "Please enter the person's phone number: ";
			cin >> number; 

			book->insert(fname, lname, number);
			break;
		case 2: // Delete a member
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			book->remove(fname, lname);
			break;
		case 3:  // Find the number for a person
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			number = book->findNumber(fname, lname);
			cout << endl << fname << ' ' << lname << "'s number: " << number;
			break;
		case 4:  // Change a person's phone number
			cout << "Please enter the person's first name: ";
			cin >> fname;

			cout << "Please enter the person's last name: ";
			cin >> lname;

			cout << "Please enter the person's new phone number: ";
			cin >> number;

			book->change(fname, lname, number);
			break;
		case 5: // Get all the members of the phonebook and print them out in ascending order
			members = book->getAllAscending();
			cout << endl << "First Name | Last Name | Phone Number" << endl;
			for (int i = 0; i < members.size(); i++) {
				cout << members[i] << endl;
			}
			break;
		case 6: // Quit and save the tree to a file
			cout << "Please enter the full path of where to save the tree: ";
			cin >> path;

			book->saveTree(path);
			m_quit = true;
			break;
	}
}

// Whether or not the UI should quit
bool UserInterface::shouldQuit() {
	return m_quit;
}