#pragma once
#include <vector>
#include <string>
#include "Person.h"

class Book {
	Person* m_head;
	int m_size;

	void EmptyTree(Person* c);

	Person* find(string fname, string lname, Person*& parent);
	Person find(string fname, string lname);


	void printTree(Person* p, int depth);

	void rotateLeft(Person* pivot);
	void rotateRight(Person* pivot);

	void fixViolation(Person* n);

	void inorder(std::vector<string>*, Person* c);

public:
	Book();
	Book(string path);
	~Book();

	int size();

	void printTree();

	void saveTree();
	void restoreTree();

	void save(string filename);

	void EmptyTree();

	vector<string> getAllAscending();

	void insert(string fname, string lname, string number);
	void remove(string fname, string lname);
	void change(string fname, string lname, string newNumber);

	string findNumber(string fname, string lname);
};

