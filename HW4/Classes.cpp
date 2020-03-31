#include "Classes.h"

Node::Node(string val) {
	m_value = val;
}

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