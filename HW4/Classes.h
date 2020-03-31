#pragma once
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	int m_label;
	string m_value;
	Node* m_next;

	Node(string);
	~Node();

public:
	string getValue();
	Node* getNext();
	int getLabel();

	void setLabel(int);
	void setNext(Node*);
};

class Digraph {
private:
	vector<Node*> headers;
	Digraph();
	~Digraph();

public:
	void addEdge(int, int);
	void removeEdge(int, int);
	void sort();
	bool checkAcyclic();
};

