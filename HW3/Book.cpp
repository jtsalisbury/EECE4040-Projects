#include "Book.h"


Book::Book() {
	m_size = 0;
}

Book::Book(string path) {
	restoreTree(path);
}

Book::~Book() {
	EmptyTree();

	delete m_head;
}

int Book::size() {
	return m_size;
}

void Book::restoreTree(string path) {

}

void Book::saveTree(string path) {

}

void Book::EmptyTree() {

}

void Book::EmptyTree(Person* p) {

}

vector<string> Book::getAllAscending() {

}

void Book::insert(string fname, string lname, string number) {

}

void Book::remove(string fname, string lname) {

}

Person* Book::find(string fname, string lname, Person*& parent) {

}

Person* Book::find(string fname, string lname) {

}

void Book::change(string fname, string lname, string number) {

}

string Book::findNumber(string fname, string lname) {

}

void Book::rotateLeft(Person* pivot) {

}

void Book::rotateRight(Person* pivot) {

}

void Book::fixViolation(Person* p) {

}

void Book::inorder(vector<string>* members, Person* p) {

}