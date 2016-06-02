#include "stdafx.h"
#include "File.h"

File::File(std::string path, int mode) : mode(mode)
{
	//mode: 0 - only read/write; 1 - read/write with create new file if not exist	
	//default set 0
	
	if (mode)
	{
		this->outputFileHandler.open(path);

		if (!this->outputFileHandler.good())
			exit(0);
	}
	else
	{
		this->inputFileHandler.open(path, std::ios::in | std::ios::out);

		if (!this->inputFileHandler.good())
			exit(0);
	}
}

File::~File(void) {
	if (this->inputFileHandler.good())
		this->inputFileHandler.close();
	
	if (this->outputFileHandler.good())
		this->outputFileHandler.close();
}

std::string File::ReadFile() {
	std::string ret;
	std::string str;

	while (std::getline(this->inputFileHandler, str))
		ret += str;

	return ret;
}

bool File::SaveToFile(std::string value)
{
	if (mode == 1)
	{
		this->outputFileHandler << value;
	}

	return false;
}
