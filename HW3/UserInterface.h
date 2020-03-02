#pragma once
#include "Book.h"
#include <map>

class UserInterface {
	bool m_quit;

public:
	void printOptions();
	bool validateOption(int option);
	void executeOption(Book* book, int option);
	bool shouldQuit();
};

