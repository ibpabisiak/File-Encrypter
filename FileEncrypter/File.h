#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <sstream>

class File
{
public:
	File(std::string, int = 0); //mode: 0 - only read/write; 1 - read/write with create new file if not exist - default set 0

	~File(void);
	std::string ReadFile();
	bool SaveToFile(std::string);

private:
	int mode;
	std::ifstream inputFileHandler;
	std::ofstream outputFileHandler;
};

