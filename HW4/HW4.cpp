// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Classes.h"

using namespace std;

// Helper function to split a string into words based on spaces
vector<string> split(string s) {
	vector<string> words;
	string word = "";

	// Loop through the string. If we come across a space, we've formulated a new word
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			words.push_back(word);
			word = "";
		}
		else {
			word += s[i];
		}
	}

	words.push_back(word);

	return words;
}

int main() {
	Digraph* DAG = new Digraph();
	string task;
	int count = 1;

    cout << "Please enter in tasks. Enter 0 to finish." << endl;

	// Continually record tasks from the user until we get a 0
    while (true) {
        cout << "Please enter a value for task #" << count << ": ";
		getline(cin, task);

        if (task == "0") {
            break;
        }

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid option. Please try again." << endl;
			continue;
		}

		count++;
		DAG->addVertex(task);
    }

	// Continually add edges from the user until we get a 0
	cout << endl << "Please enter in the order of precedence. Use the number assigned for each task above." << endl;
	cout << "Ex: 1 3, indicates task one must come before task 3. Enter a 0 to finish" << endl;

	string order;
	while (true) {
		cout << "Please enter an order of precendence: ";
		getline(cin, order);

		if (order == "0") {
			break;
		}

		// Separate the to and from node indices
		vector<string> words = split(order);
		if (words.size() != 2) {
			cout << "Invalid option. Please try again." << endl;
			continue;
		}

		// Convert to integers
		int from = stoi(words[0]) - 1;
		int to = stoi(words[1]) - 1;

		// Try and add the edge. If it returns false, we had a problem
		if (!DAG->addEdge(from, to)) {
			cout << "Invalid option. Please try again." << endl;
			continue;
		}
	}

	cout << endl;

	// Sort the DAG. If there are cycles, it will set a boolean which we can check.
	Node* current = DAG->sort();

	if (DAG->hasCycles()) {
		cout << "Error: This graph is not a DAG!" << endl;
	} else {
		cout << "Topological order of tasks:" << endl;
		while (current != nullptr) {
			cout << current->getValue() << endl;

			current = current->getNext();
		}
	}
}