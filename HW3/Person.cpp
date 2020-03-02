#include "Person.h"
#include <iostream>

enum colors {
	RED,
	BLACK
};

//Person Constructor
Person::Person(string m_fname, string m_lname, string m_phonenumber) {
	color = RED;
}

//Person destructor
Person::~Person() {
	m_left = nullptr;
	m_right = nullptr;
}

Person* Person::getLeft() {
	return m_left;
}

Person* Person::getRight() {
	return m_right;
}

Person* Person::getParent() {
	return m_parent;
}


bool Person::getColor() {
	return color;
}


string Person::getFirstName() {
	return m_fname;
}
string Person::getLastName() {
	return m_lname;
}

string Person::getNumber() {
	return m_phonenumber;
}

void Person::setLeft(Person* n) {
	m_left = n;
}

void Person::setRight(Person* n) {
	m_right = n;
}

void Person::setParent(Person* n) {
	m_parent = n;
}

void Person::setColor(bool c) {
	color = c;
}

void Person::setNumber(string num) {
	m_phonenumber = num;
}