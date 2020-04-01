#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
private:
	string m_value;
	Node* m_next;

public:
	Node(string);
	~Node();

	string getValue();
	Node* getNext();

	void setNext(Node*);
};

class Digraph {
private:
	vector<Node*> m_headers;
	void sortUtil(map<string, int>*, map<string, bool>*, Node**, Node*);
	bool m_hascycles = false;

public:
	Digraph();
	~Digraph();

	void addVertex(string);
	bool addEdge(int, int);
	bool removeEdge(int, int);
	bool hasEdge(int, int);
	Node* sort();
	bool hasCycles();
};

