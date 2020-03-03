#include "Book.h"

enum colors {
	RED,
	BLACK
};


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
	if (m_size == 0) {
		return;
	}

	EmptyTree(m_head);
}

void Book::EmptyTree(Person* p) {
	if (p->getLeft() != nullptr) {
		EmptyTree(p->getLeft());
	}

	if (p->getRight() != nullptr) {
		EmptyTree(p->getRight());
	}

	p->setLeft(nullptr);
	p->setRight(nullptr);

	m_size--;

	delete p;
}

vector<string> Book::getAllAscending() {
	vector<string> v;

	if (m_size == 0) {
		return v;
	}

	inorder(&v, m_head);

	return v;
}

void Book::insert(string fname, string lname, string number) {
	Person* n = new Person(fname, lname, number);

	// Update the head Person if the size is 0
	if (m_size == 0) {

		m_head = n;

		m_size++;

		return;
	}

	Person* curPerson = m_head;
	string ourName = lname + ' ' + fname; // combine name like this for alphabetical order

	bool greaterThan;
	while (curPerson != nullptr) {
		greaterThan = ourName > curPerson->getLastName() + ' ' + curPerson->getFirstName();

		if (curPerson->getLeft() == nullptr && !greaterThan) {
			curPerson->setLeft(n);
			n->setParent(curPerson);

			break;
		}
		else if (curPerson->getRight() == nullptr && greaterThan) {
			curPerson->setRight(n);
			n->setParent(curPerson);

			break;
		}

		if (greaterThan) {
			curPerson = curPerson->getRight();
		}
		else {
			curPerson = curPerson->getLeft();
		}
	}

	fixViolation(n);

	m_size++;
}

// TODO
void Book::remove(string fname, string lname) {

}

Person* Book::find(Person* root, string fname, string lname) {
	string targetName = lname + ' ' + fname;

	if (root == nullptr || root->getLastName() + ' ' + root->getFirstName() == targetName) {
		return root;
	}

	if (root->getLastName() + ' ' + root->getFirstName() < targetName) {
		return find(root->getRight(), fname, lname);
	}

	return find(root->getLeft(), fname, lname);
}

void Book::change(string fname, string lname, string number) {
	Person* target = find(m_head, fname, lname);

	if (target == nullptr) {
		return;
	}

	target->setNumber(number);
}

string Book::findNumber(string fname, string lname) {
	Person* target = find(m_head, fname, lname);

	return target != nullptr ? target->getNumber() : "";
}

void Book::rotateLeft(Person* pivot) {
	Person* temp = pivot->getRight();

	if (temp != nullptr)
		pivot->setRight(temp->getLeft());

	if (temp != nullptr && temp->getLeft() != nullptr) {
		temp->getLeft()->setParent(pivot);
	}

	if (temp != nullptr) {
		temp->setParent(pivot->getParent());
		temp->setLeft(pivot);
	}

	if (pivot->getParent() == nullptr) {
		m_head = temp;
	}
	else if (pivot == pivot->getParent()->getLeft()) {
		pivot->getParent()->setLeft(temp);
	}
	else {
		pivot->getParent()->setRight(temp);
	}

	pivot->setParent(temp);
}

void Book::rotateRight(Person* pivot) {
	Person* temp = pivot->getLeft();

	if (temp != nullptr)
		pivot->setLeft(temp->getRight());

	if (temp != nullptr && temp->getRight() != nullptr) {
		temp->getRight()->setParent(temp);
	}

	if (temp != nullptr) {
		temp->setParent(pivot->getParent());
		temp->setRight(pivot);
	}

	if (pivot->getParent() == nullptr) {
		m_head = temp;
	}
	else if (pivot == pivot->getParent()->getLeft()) {
		pivot->getParent()->setLeft(temp);
	}
	else {
		pivot->getParent()->setRight(temp);
	}

	pivot->setParent(temp);
}

void Book::fixViolation(Person* pivot) {
	bool left;
	Person* uncle = nullptr;
	Person* grandparent = nullptr;
	Person* t;

	if (pivot->getParent() != nullptr && pivot->getParent()->getParent() != nullptr) {
		grandparent = pivot->getParent()->getParent();

		uncle = (grandparent->getLeft() == pivot->getParent()) ? grandparent->getRight() : grandparent->getLeft();
	}

	if (pivot->getParent() == nullptr) {
		// Case 1

		pivot->setColor(BLACK);
	} else if (pivot->getParent()->getColor() == BLACK) {
		// case 2

		return;
	} else if (uncle != nullptr && uncle->getColor() == RED) {
		// case 3

		pivot->getParent()->setColor(BLACK);
		uncle->setColor(BLACK);
		grandparent->setColor(RED);

		fixViolation(grandparent);
	} else {
		// case 4

		if (grandparent != nullptr && grandparent->getLeft() != nullptr && pivot == grandparent->getLeft()->getRight()) {
			rotateLeft(pivot->getParent());
			pivot = pivot->getLeft();
		}
		else if (grandparent != nullptr && grandparent->getRight() != nullptr && pivot == grandparent->getRight()->getLeft()) {
			rotateRight(pivot->getParent());
			pivot = pivot->getRight();
		}

		if (grandparent != nullptr && pivot == pivot->getParent()->getLeft()) {
			rotateRight(grandparent);
		}
		else {
			if (grandparent != nullptr) {
				rotateLeft(grandparent);
				grandparent->setColor(RED);
			}

			pivot->getParent()->setColor(BLACK);
		}
	}
}

void Book::inorder(vector<string>* members, Person* p) {

	if (p == nullptr) {
		return;
	}
	
	// Recursively do the left
	inorder(members, p->getLeft());

	// Then the current
	string current;
	current = (p->getFirstName() + " " + p->getLastName() + " " + p->getNumber());

	// Then recursively do the right
	inorder(members, p->getRight());

}

void Book::preorder(vector<string>* members, Person* p) {

	if (p == nullptr) {
		return;
	}

	// Then the current
	string current;
	current = (p->getFirstName() + " " + p->getLastName() + " " + p->getNumber());

	// Recursively do the left
	preorder(members, p->getLeft());

	// Then recursively do the right
	preorder(members, p->getRight());


}