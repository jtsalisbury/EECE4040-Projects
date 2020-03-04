#include "Person.h"
#include <iostream>

//Person Constructor
Person::Person(string fname, string lname, string phonenumber) {
	m_fname = fname;
	m_lname = lname;
	m_phonenumber = phonenumber;
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

void Person::setNumber(string num) {
	m_phonenumber = num;
}

void Person::setName(string fname, string lname) {
	m_fname = fname;
	m_lname = lname;
}