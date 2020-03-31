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

int Node::getLabel() {
	return m_label;
}

void Node::setLabel(int label) {
	m_label = label;
}

void Node::setNext(Node* next) {
	m_next = next;
}

Digraph::Digraph() { }
Digraph::~Digraph() {
	Node* current;
	Node* next;

	for (int i = 0; i < m_headers.size(); i++) {
		current = m_headers[i];

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
	Node* vertex = new Node(val);

	m_headers.push_back(vertex);
}

bool Digraph::hasEdge(int from, int to) {
	// out of bounds
	if (from > m_headers.size() - 1 || to > m_headers.size() - 1) {
		return false;
	}

	Node* header = m_headers[from];
	string targetValue = m_headers[to]->getValue();

	while (header->getNext() != nullptr) {
		Node* next = header->getNext();

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
	if (from > m_headers.size() - 1 || to > m_headers.size() - 1) {
		return false;
	}

	Node* current = m_headers[from];
	Node* previous;

	string targetValue = m_headers[to]->getValue();

	while (current->getNext() != nullptr) {
		Node* next = current->getNext();

		previous = current;
		current = next;

		if (current->getValue() == targetValue) {
			break;
		}
	}

	previous->setNext(current->getNext());
	current->setNext(nullptr);

	delete current;

	return true;
}

void Digraph::sort() {

}

bool Digraph::checkAcyclic() {

}