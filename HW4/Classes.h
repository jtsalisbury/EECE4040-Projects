#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
private:
	int m_label;
	string m_value;
	Node* m_next;

public:
	Node(string);
	~Node();

	string getValue();
	Node* getNext();
	int getLabel();

	void setLabel(int);
	void setNext(Node*);
};

class Digraph {
private:
	vector<Node*> m_headers;

public:
	Digraph();
	~Digraph();

	void addVertex(string);
	bool addEdge(int, int);
	bool removeEdge(int, int);
	bool hasEdge(int, int);
	Node* sort();
	bool checkAcyclic();
};

