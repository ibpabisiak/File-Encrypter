#pragma once
#include <iostream>

class Coder
{
	public:
		static std::string Encryption(std::string, std::string key);
		static std::string Decryption(std::string, std::string key);
};

