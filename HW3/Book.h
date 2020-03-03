#pragma once
#include <vector>
#include <string>
#include "Person.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;
using std::ofstream;

class Book {
	Person* m_head = nullptr;
	int m_size = 0;

	void EmptyTree(Person* p);

	Person* find(Person* root, string fname, string lname);

	void rotateLeft(Person* pivot);
	void rotateRight(Person* pivot);

	Person* getMin(Person* root);
	void transplant(Person* one, Person* two);
	void fixInsertViolation(Person* n);
	void fixDeleteViolation(Person* n);

	void inorder(std::vector<string>* members, Person* c);
	void preorder(std::vector<string>* members, Person* c);

	void restoreTree(string path);

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
	void saveTree(string path);

	string findNumber(string fname, string lname);
};

