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

vector<string> split(string s) {
	vector<string> words;
	string word = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			words.push_back(word);
			word = "";
		} else {
			word += s[i];
		}
	}

	words.push_back(word);

	return words;
}

void Book::restoreTree(string path) {
	string info; 

	ifstream input(path);

	if (!input.is_open()) {
		cout << "Unable to open file" << endl;
		return;
	}

	while (getline(input, info)) {
		istringstream iss(info);
		vector<string> words = split(info);

		insert(words[0], words[1], words[2]);
	}

	input.close();
}

void Book::saveTree(string path) {
	ofstream output;

	output.open(path);
	if (!output) {
		return;
	}

	vector<string> members;
	preorder(&members, m_head);

	for (int i = 0; i < members.size(); i++) {
		output << members[i] << endl;
	}

	output.close();
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

	fixInsertViolation(n);

	m_size++;
}

Person* Book::getMin(Person* m_head) {
	while (m_head->getLeft() != nullptr) {
		return getMin(m_head->getLeft());
	}

	return m_head;
}

void Book::transplant(Person* one, Person* two) {
	if (one->getParent() == nullptr) {
		m_head = two;
	}
	else if (one == one->getParent()->getLeft()) {
		one->getParent()->setLeft(two);
	}
	else {
		one->getParent()->setRight(two);
	}

	if (two != nullptr) {
		two->setParent(one->getParent());
	}
}

// TODO
void Book::remove(string fname, string lname) {
	Person* node = find(m_head, fname, lname);

	if (node == nullptr) {
		return;
	}

	Person* x;
	Person* y;

	y = node;
	bool yColor = y->getColor();

	if (node->getLeft() == nullptr) {
		x = node->getRight();
		transplant(node, node->getRight());
	} else if (node->getRight() == nullptr) {
		x = node->getLeft();
		transplant(node, node->getLeft());
	} else {
		y = getMin(node->getRight());
		yColor = y->getColor();

		x = y->getRight();
		if (y->getParent() == node) {
			x->setParent(y);
		} else {
			transplant(y, y->getRight());
			y->setRight(node->getRight());
			y->getRight()->setParent(y);
		}

		transplant(node, y);
		y->setLeft(node->getLeft());
		y->getLeft()->setParent(y);
		y->setColor(node->getColor());
	}

	if (yColor == BLACK) {
		fixDeleteViolation(x); //red_black_delete_fixup
	}
}

Person* Book::find(Person* m_head, string fname, string lname) {
	string targetName = lname + ' ' + fname;

	if (m_head == nullptr || m_head->getLastName() + ' ' + m_head->getFirstName() == targetName) {
		return m_head;
	}

	if (m_head->getLastName() + ' ' + m_head->getFirstName() < targetName) {
		return find(m_head->getRight(), fname, lname);
	}

	return find(m_head->getLeft(), fname, lname);
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
	} else if (pivot == pivot->getParent()->getLeft()) {
		pivot->getParent()->setLeft(temp);
	} else {
		pivot->getParent()->setRight(temp);
	}

	pivot->setParent(temp);
}

void Book::fixDeleteViolation(Person* node) {
	Person* w;

	while (node != m_head && node->getColor() == BLACK) {

		if (node == node->getParent()->getLeft()) {
			w = node->getParent()->getRight();

			if (w->getColor() == RED) {
				w->setColor(BLACK);
				node->getParent()->setColor(RED);
				rotateLeft(node->getParent());
				w = node->getParent()->getRight();
			}

			if (w->getLeft()->getColor() == BLACK && w->getRight()->getColor() == BLACK) {
				w->setColor(RED);
				node->getParent()->setColor(BLACK);
				node = node->getParent();
			}
			else {

				if (w->getRight()->getColor() == BLACK) {
					w->setColor(RED);
					w->getLeft()->setColor(BLACK);
					rotateRight(w);
					w = node->getParent()->getRight();
				}

				w->setColor(node->getParent()->getColor());
				node->getParent()->setColor(BLACK);
				node->getRight()->setColor(BLACK);
				rotateLeft(node->getParent());
				node = m_head;

			}

		}
		else {
			w = node->getParent()->getLeft();

			if (w->getColor() == RED) {
				w->setColor(BLACK);
				node->getParent()->setColor(BLACK);
				rotateRight(node->getParent());
				w = node->getParent()->getLeft();
			}

			if (w->getLeft()->getColor() == BLACK && w->getRight()->getColor() == BLACK) {
				w->setColor(RED);
				node->getParent()->setColor(BLACK);
				node = node->getParent();
			}
			else {

				if (w->getLeft()->getColor() == BLACK) {
					w->setColor(RED);
					w->getRight()->setColor(BLACK);
					rotateLeft(w);
					w = node->getParent()->getLeft();
				}

				w->setColor(node->getParent()->getColor());
				node->getParent()->setColor(BLACK);
				w->getLeft()->setColor(BLACK);
				rotateRight(node->getParent());
				node = m_head;

			}
		}

	}

	node->setColor(BLACK);
}

void Book::fixInsertViolation(Person* pivot) {
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

		fixInsertViolation(grandparent);
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
	members->push_back(current);

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
	members->push_back(current);

	// Recursively do the left
	preorder(members, p->getLeft());

	// Then recursively do the right
	preorder(members, p->getRight());

}