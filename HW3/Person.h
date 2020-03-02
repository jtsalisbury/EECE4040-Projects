#pragma once
#include <string>

using namespace std;

class Person {
	Person* m_left = nullptr;
	Person* m_right = nullptr;
	Person* m_parent = nullptr;

	bool color;

	std::string m_fname;
	std::string m_lname;
	std::string m_phonenumber;

public: 
	Person(std::string m_fname, std::string m_lname, std::string m_phonenumber);
	~Person();

	Person* getLeft();
	Person* getRight();
	Person* getParent();

	bool getColor();

	std::string getFirstName();
	std::string getLastName();
	std::string getNumber();

	void setLeft(Person* p);
	void setRight(Person* p);
	void setParent(Person* p);
	void setColor(bool c);
	void setNumber(string n);
};

