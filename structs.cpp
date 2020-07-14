#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "structs.h"



void createStruct()
{
	TestCharacter test{"Test", 18, "Human", "Sorcerer"}; //creates a struct called "test" and initialises it with 4 values.
	std::ofstream characterFile("C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Structs/test.txt"); //opens a text file in write mode
	characterFile << test.characterName << "\n" <<test.characterAge << "\n" << test.characterRace << "\n" << test.characterClass << "\n"; //writes the 4 values within the "test" struct to the opened file
	characterFile.close(); //closes the file
	
}

void readStructFromFile()
{
	TestCharacter liam; //creates an uninitialised struct
	std::ifstream characterFile("C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Structs/test1.txt"); //opens a file in read mode
	
	getline(characterFile, liam.characterName); //reads a lines from the opened file and assigns its value to "liam.characterName"

	std::string age; //A string to store the number that is still a string in
	getline(characterFile, age); //reads a line from the file and assigns it to "age"; i know this line will be a number, but its stored as a string!!
	std::stringstream characterAge(age); //Converts the string into an integer
	characterAge >> liam.characterAge; //stores the converted integer in "liam.characterAge";
	//reads a lines from the opened file and assigns its value to "liam.characterAge"

	getline(characterFile, liam.characterRace); //reads a lines from the opened file and assigns its value to "liam.characterRace"
	getline(characterFile, liam.characterClass); //reads a lines from the opened file and assigns its value to "liam.characterClass"
	characterFile.close();

	liam.printCharacterDetails(); //A method within the "TestCharacter" struct that prints the contents of the struct.

	//std::cout << liam.characterName << "\n" << liam.characterAge << "\n" << liam.characterRace << "\n" << liam.characterClass << "\n"; //prints the 4 values that were just retrieved from the files
}

