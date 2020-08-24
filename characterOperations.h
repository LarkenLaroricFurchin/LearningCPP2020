#ifndef CHARACTEROPERATIONS
#define CHARACTEROPERATIONS
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>  //used to make the stuff in "getTime()" work
#include <chrono> //used to make the stuff in "getTime()" work

inline std::string defaultCharacterFileDir = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Character Files/";


class CharacterOperations
{
	std::string characterName{ "Name Name" };
	std::string characterRace{ "Race" };
	std::string characterClass{ "Class" };
	short characterAge{ 0 };
	short characterLevel{ 0 };
	int characterExperience{ 0 };
public:
	

	void characterCreation() //gets user input to create a new character
	{
		std::cout << "Enter characters name: ";
		std::getline(std::cin, characterName);

		std::cout << "Enter characters race: ";
		std::getline(std::cin, characterRace);

		std::cout << "Enter characters class: ";
		std::getline(std::cin, characterClass);

		std::cout << "Enter characters age: ";
		std::string age;
		std::getline(std::cin, age);
		std::stringstream convertedAge(age); //stringstream converts integers within a string into actual integers
		convertedAge >> characterAge;		 //you have to access a stringstream the same way you access std::cin

		characterExperience = 0;

		characterLevel = 0;

		saveCharacterDetails();
	}

	void saveCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir.append(characterName).append(".txt"); //using .append() because just doing "string + string" is a big no no in classes.


		std::ofstream characterFile(characterDirectory);

		characterFile << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience;

		characterFile.close();
	}

	void loadCharacterDetails()
	{
		std::string characterDirectory = defaultCharacterFileDir.append(characterName).append(".txt");

		std::ifstream characterFile(characterDirectory);

		std::getline(characterFile, characterName);
		std::getline(characterFile, characterRace);
		std::getline(characterFile, characterClass);

		std::string age;
		std::getline(characterFile, age);
		std::stringstream convertedAge(age);
		convertedAge >> characterAge;

		std::string level;
		std::getline(characterFile, level);
		std::stringstream convertedLevel(level);
		convertedLevel >> characterLevel;

		std::string xp;
		std::getline(characterFile, xp);
		std::stringstream convertedXp(xp);
		convertedXp >> characterExperience;

		printCharacterDetails();

		characterFile.close();
	}

	void printCharacterDetails()
	{
		std::cout << characterName << "\n" << characterRace << "\n" << characterClass << "\n" << characterAge << "\n" << characterLevel << "\n" << characterExperience;
	}

	void incrementCharacterXP()
	{

	}

	void incrementCharacterLevel()
	{

	}
};

#endif