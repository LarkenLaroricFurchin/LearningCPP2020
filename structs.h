#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <fstream>
#include <sstream>

inline std::string defaultCharacterFileDir = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Character Files/"; //An inline variable can be declared in multiple different files, but will only be instantiated once; so here.

struct TestCharacter //defines a struct called "TestCharacter" struct names start with a capital letter to distinguish them from variables
{
	std::string characterName;
	short characterAge;
	std::string characterRace;
	std::string characterClass;

	void fillCharacterDetails()
	{
		std::cout << "Enter the characters name: ";
		std::getline(std::cin, characterName);

		std::cout << "Enter the characters age: ";
		std::string age; //A string to store the number, that is still a string, in
		std::getline(std::cin, age); //reads a line from the file and assigns it to "age"; i know this line will be a number, but its stored as a string!!
		std::stringstream convertedAge(age); //Converts the string into an integer
		convertedAge >> characterAge; //stores the converted integer in "liam.characterAge";

		std::cout << "Enter the characters race: ";
		std::getline(std::cin, characterRace);

		std::cout << "Enter the characters class: ";
		std::getline(std::cin, characterClass);
	}

	void saveCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir + characterName + ".txt";
		std::ofstream file(characterDirectory);
		file << characterName << "\n" << characterAge << "\n" << characterRace << "\n" << characterClass << "\n";
		std::cout << "Character Saved\n";
		file.close(); //"file.close()" closes the opened file
	}

	void loadCharacterDetails()
	{
		std::cout << "Enter the characters name: ";
		std::getline(std::cin, characterName);

		std::string characterDirectory = defaultCharacterFileDir + characterName + ".txt";	//creates a string, by joining multiple strings, that holds the directory of the characters file. 
		std::ifstream file(characterDirectory);												//opens the file in the directory that is stored in "characterDirectory"

		std::getline(file, characterName);													//Reads the first line, then stores the text in the "characterName" string

		std::string age;
		std::getline(file, age);
		std::stringstream convertedAge(age);												//uses "stringsteam" to convert the string into an integer
		convertedAge >> characterAge;														//reads from the created stringstream and assigns the integer to "characterAge" 
																							//(using >> to read from a streamstream is the same as using >> to read from cin

		std::getline(file, characterRace);

		std::getline(file, characterClass);

		file.close();
	}

	void printCharacterDetails()
	{
		std::cout << characterName << "\n" << characterAge << "\n" << characterRace << "\n" << characterClass << "\n"; //A method that makes it MUCH easier to print the characters details
	}
};

void createStruct();
void readStructFromFile();
#endif