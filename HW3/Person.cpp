#include "Person.h"
#include <iostream>

enum colors
{
	RED,
	BLACK
};

//Person Constructor
Person(std::string m_fname, std::string m_lname, std::string m_phonenumber) {
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


std::string Person::getFirstName() {
	return m_fname;
}
std::string Person::getLastName() {
	return m_lname;
}

std::string Person::getNumber() {
	return m_phonenumber;
}

void Person::setLeft(Person* n) {
	m_left = n;
}

void Person::setRight(Person* n) {
	m_right = n;
}

void Person::setParent(Person* n) {
	parent = n;
}

void Person::setColor(bool c) {
	color = c;
}