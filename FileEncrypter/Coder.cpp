#include "stdafx.h"
#include "Coder.h"

std::string Coder::Encryption(std::string value, std::string key)
{
	std::string ret;
	ret = value;
	
	for (int i = 0, j = 0; i < value.length(); i++)
		ret[i] = ret[i] + key[(j < key.length()) ? j++ : j = 0] + 14;

	return ret;
}

std::string Coder::Decryption(std::string value, std::string key)
{
	std::string ret;
	ret = value;

	for (int i = 0, j = 0; i < value.length(); i++)
		ret[i] = ret[i] - key[(j < key.length()) ? j++ : j = 0] - 14;

	return ret;
}
