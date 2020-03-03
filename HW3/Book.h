#pragma once
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

class Book {
	Person* m_head;
	int m_size;

	void EmptyTree(Person* p);

	Person* find(Person* root, string fname, string lname);

	void rotateLeft(Person* pivot);
	void rotateRight(Person* pivot);

	void fixViolation(Person* n);

	void inorder(std::vector<string>* members, Person* c);
	void preorder(std::vector<string>* members, Person* c);

	void restoreTree(string path);
	void saveTree(string path);


public:
	Book();
	Book(string path);
	~Book();

	int size();

	void EmptyTree();

	vector<string> getAllAscending();

	void insert(string fname, string lname, string number);
	void remove(string fname, string lname);
	void change(string fname, string lname, string newNumber);

	string findNumber(string fname, string lname);
};

