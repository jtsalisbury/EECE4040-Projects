#pragma once
class UserInterface {
	bool m_quit;

public:
	void printOptions();
	void executeOption(int optionNum);

	bool shouldQuit();
};

