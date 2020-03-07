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

//get left person
Person* Person::getLeft() {
	return m_left;
}

//get right person
Person* Person::getRight() {
	return m_right;
}

//get parent
Person* Person::getParent() {
	return m_parent;
}

//get first name of a person
string Person::getFirstName() {
	return m_fname;
}

//get last name of a person
string Person::getLastName() {
	return m_lname;
}

//get number of a contact
string Person::getNumber() {
	return m_phonenumber;
}

//edit left child 
void Person::setLeft(Person* n) {
	m_left = n;
}

//edit right child
void Person::setRight(Person* n) {
	m_right = n;
}

//edit parent
void Person::setParent(Person* n) {
	m_parent = n;
}

//edit number of a contact
void Person::setNumber(string num) {
	m_phonenumber = num;
}

//edit name of a contact
void Person::setName(string fname, string lname) {
	m_fname = fname;
	m_lname = lname;
}