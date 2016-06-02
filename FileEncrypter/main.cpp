#include "stdafx.h"
#include <iostream>
#include <regex>
#include "File.h"
#include "Coder.h"

int main(int argc, char * argv[])
{
	int mode = 0; //1 - cod mode; 2 - dec mode
	

	if (argc == 5)
	{
		if (strcmp(argv[1], "cod") == 0)
			mode = 1;
		else if (strcmp(argv[1], "dec") == 0)
			mode = 2;
		else
			return -1;

		std::regex reg("[0-9A-F]{1,16}");
		if (!std::regex_match(argv[4], reg))
			return -1;

		if (mode == 1) //cod mode
		{
			File inputFile(argv[2]);
			File outputFile(argv[3], 1);
			
			std::string str = inputFile.ReadFile();
			str = Coder::Encryption(str, argv[4]);
			outputFile.SaveToFile(str);

			std::cout << " * Kodowanie zakonczone pomyslnie." << std::endl;
			return 1;
		}
		else if (mode == 2) //dec mode
		{
			File inputFile(argv[2]);
			File outputFile(argv[3], 1);

			std::string str = inputFile.ReadFile();
			str = Coder::Decryption(str, argv[4]);
			outputFile.SaveToFile(str);
			std::cout << " * Dekodowanie zakonczone pomyslnie." << std::endl;
			return 1;
		}
		else
		{
			std::cout << " * Wybrano zly tryb pracy programu, dostepne: cod - kodowanie; dec - dekodowanie" << std::endl;
		}
	}
	else
	{
		std::cout << " * Niepoprawna ilosc argumentow." << std::endl;
	}

    return 0;
}
