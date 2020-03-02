#pragma once
#include <vector>
#include "Person.h"

class Book {
	Person* m_head;
	int m_size;

	void EmptyTree(Person* c);

	Person* find(int i, Person*& parent);

	void printTree(Person* p, int depth);

	void rotateLeft(Person* pivot);
	void rotateRight(Person* pivot);

	void fixViolation(Person* n);

public:
	Book();
	~Book();

	int size();

	void printTree();

	void saveTree();
	void restoreTree();

	void inorder(std::vector<int>*, Person* c);
	void EmptyTree();
	void insert(int i);

	std::vector<int> GetAllAscending();
	std::vector<int> GetAllDescending();

	Person* Remove(int i);
	Person* find(int i);
};

