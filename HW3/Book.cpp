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

Person* Book::getMin(Person* m_head) {
	while (m_head->getLeft() != nullptr) {
		return getMin(m_head->getLeft());
	}

	return m_head;
}

void Book::insert(string fname, string lname, string number) {
	Person* n = new Person(fname, lname, number);

	// Update the head node if the size is 0
	if (m_size == 0) {

		m_head = n;
		m_size++;

		return;
	}

	Person* curNode = m_head;
	string targetVal = n->getLastName() + " " + n->getFirstName();

	bool greaterThan;
	string curVal;
	while (curNode != nullptr) {
		curVal = curNode->getLastName() + " " + curNode->getFirstName();
		greaterThan = targetVal > curVal;

		if (curNode->getLeft() == nullptr && !greaterThan) {
			curNode->setLeft(n);

			break;
		} else if (curNode->getRight() == nullptr && greaterThan) {
			curNode->setRight(n);

			break;
		}

		if (greaterThan) {
			curNode = curNode->getRight();
		} else {
			curNode = curNode->getLeft();
		}
	}

	m_size++;
}

void Book::remove(string fname, string lname) {
	Person* root = find(m_head, fname, lname);

	remove(m_head, fname, lname);
}

Person* Book::remove(Person* root, string fname, string lname) {
	if (root == nullptr) {
		return root;
	}

	string targetVal = lname + " " + fname;
	string rootVal = root->getLastName() + " " + root->getFirstName();

	if (targetVal > rootVal) {
		root->setRight(remove(root->getRight(), fname, lname));
	} else if (targetVal < rootVal) {
		root->setLeft(remove(root->getLeft(), fname, lname));
	} else {
		if (root->getLeft() == nullptr) {
			Person* t = root->getRight();
			delete root;
			return t;
		} else if (root->getRight() == nullptr) {
			Person* t = root->getLeft();
			delete root;
			return t;
		}

		Person* t = getMin(root->getRight());
		root->setName(t->getFirstName(), t->getLastName());
		root->setNumber(t->getNumber());
		root->setRight(remove(root->getRight(), fname, lname));
	} 

	return root;
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