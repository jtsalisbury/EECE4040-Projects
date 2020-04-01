#include "Classes.h"

Node::Node(string val) {
	m_value = val;
	m_next = nullptr;
}

Node::~Node() { }

string Node::getValue() {
	return m_value;
}

Node* Node::getNext() {
	return m_next;
}

void Node::setNext(Node* next) {
	m_next = next;
}

Digraph::Digraph() { }
Digraph::~Digraph() {
	Node* current;
	Node* next;

	// Loop through each header
	for (int i = 0; i < m_headers.size(); i++) {
		current = m_headers[i];

		// Loop through the edges connected to the header and delete them
		while (current != nullptr) {
			next = current->getNext();
			current->setNext(nullptr);

			delete current;

			current = next;
		}

		m_headers[i] = nullptr;
	}
}

void Digraph::addVertex(string val) {
	// Create a new node and add it to the header list
	Node* vertex = new Node(val);

	m_headers.push_back(vertex);
}

bool Digraph::hasEdge(int from, int to) {
	// Out of bounds
	if (from > m_headers.size() - 1 || to > m_headers.size() - 1) {
		return false;
	}

	// Using the index of the node, get the header
	Node* header = m_headers[from];

	// Get the value of the to node
	string targetValue = m_headers[to]->getValue();

	// Loop through the edges connected to the header and see if we have a match
	while (header->getNext() != nullptr) {
		Node* next = header->getNext();

		// A match!
		if (next->getValue() == targetValue) {
			return true;
		}

		header = next;
	}

	return false;
}

bool Digraph::addEdge(int from, int to) {
	if (from > m_headers.size() - 1 || to > m_headers.size() - 1) {
		return false;
	}

	// Make a new node with the info
	string toValue = m_headers[to]->getValue();
	Node* newNode = new Node(toValue);

	// Get the last node in the linked list
	Node* header = m_headers[from];
	while (header->getNext() != nullptr) {
		header = header->getNext();
	}

	// Add the node
	header->setNext(newNode);

	return true;
}

bool Digraph::removeEdge(int from, int to) {
	// Out of bounds
	if (from > m_headers.size() - 1 || to > m_headers.size() - 1) {
		return false;
	}

	// Get the header 
	Node* current = m_headers[from];
	Node* previous = current;

	// Get the target node value
	string targetValue = m_headers[to]->getValue();

	// No edges 
	if (current->getNext() == nullptr) {
		return false;
	}

	// Loop through the edges and look for a match
	while (current->getNext() != nullptr) {
		Node* next = current->getNext();

		previous = current;
		current = next;

		// Match found
		if (current->getValue() == targetValue) {
			break;
		}
	}

	// Delete the node and update references
	previous->setNext(current->getNext());
	current->setNext(nullptr);

	delete current;

	return true;
}

void Digraph::sortUtil(map<string, int> *mark, map<string, bool>* inStack, Node** head, Node* v) {
	// Make the node as visited, and add it to our "stack"
	(*mark)[v->getValue()] = 1;
	(*inStack)[v->getValue()] = true;

	Node* w;
	Node* edge = v;
	// Loop through all connected edges
	while (edge != nullptr) {
		w = edge->getNext();

		// If the next edge is valid, see if we've already visited it in this cycle. If we have, this indicates a cycle.
		if (w != nullptr) {
			if ((*inStack)[w->getValue()]) {
				m_hascycles = true;
				return;
			}
		}

		// If the next edge is valid and we haven't visited it, lets visit it!
		if (w != nullptr && (*mark)[w->getValue()] == 0) {

			// We have to find the header node associated with the edge
			for (int i = 0; i < m_headers.size(); i++) {
				if (m_headers[i]->getValue() == w->getValue()) {
					// Start sorting from this header node
					sortUtil(mark, inStack, head, m_headers[i]);
					break;
				}
			}
		}

		edge = w;
	}

	// Remove v from the "stack"
	(*inStack)[v->getValue()] = false;

	// Add v to the sorted linked list
	if (*head == nullptr) {
		*head = new Node(v->getValue()); // no header node previously
	} else {
		Node* prev = new Node(v->getValue());
		prev->setNext(*head);
		*head = prev;
	}
}

Node* Digraph::sort() {
	// Create a few maps. One to mark which nodes have been visited overall, one to mark visited in a cycle
	map<string, int> mark;
	map<string, bool> inStack;

	// The first node which will be returned
	Node* m_head = nullptr;

	// Init all visited to zero
	for (int i = 0; i < m_headers.size(); i++) {
		mark[m_headers[i]->getValue()] = 0;
	}

	// Begin looping through the header nodes and sorting from each
	for (int i = 0; i < m_headers.size(); i++) {
		string val = m_headers[i]->getValue();

		if (mark[val] == 0) {
			inStack.clear(); // make sure we clear the stack
			sortUtil(&mark, &inStack, &m_head, m_headers[i]);
		}
	}

	return m_head;
}


bool Digraph::hasCycles() {
	// This will be set AFTER a sort has been ran
	return m_hascycles;
}