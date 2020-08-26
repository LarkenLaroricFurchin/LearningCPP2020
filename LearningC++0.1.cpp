#include <iostream>
#include <fstream>
#include <string>
#include <exception> //stuff for exceptions
#include <ctime>  //used to make the stuff in "getTime()" work
#include <chrono> //used to make the stuff in "getTime()" work
//#include "createDirectories.h"
//#include "structs.h"
//#include "arrays.h"
//#include "strings.h"
#include "getTime.h"
#include "characterOperations.h"
#include "LearningC++0.1.h"
using namespace std;

/*

bool getUserInput() //used to ask the user if they want to use the default directory, or a custom one
{
	cout << "Use default directory? (Y/N): ";
	string answer;
	std::cin >> answer;
	if (answer == "Y" || answer == "y")
	{
		return true;
	}
	else if (answer == "N" || answer == "n")
	{
		return false;
	}
	
	return true; // uses default directory if some weird voodoo happens and the program exits the loop.
}



string getFileName()
{
	cout << "Enter the file name: ";
	string answer; //creates a string
	std::cin.ignore(); //waits until the return key is pressed before moving on to the next statement.
	getline(std::cin, answer); //assigns the text entered in the console to the string. getline is used so the whole line is used, in the event of there being whitespace in the text.
	return answer; //returns the string
}



string getUserInputWR() //used to ask the user if they want to read or write to a file then returns their answer.
{
	cout << "Do you wish to read or write to the file? ";
	string answer; //creates a string
	std::cin >> answer; //assigns the text entered in the console to the string
	return answer; //returns the string
}



void readFile(string fileName)
{
	ifstream userFile(fileName); //opens the specified file in read mode (ifstream = input/read)

	if (userFile.is_open()) //checks to see if the file is open before proceeding
	{
		string a; //creates a string which will store one line of the opened file at a time
		while (getline(userFile, a))
		{
			std::cout << a << endl; //prints the value of the string "a"
			
		}
		userFile.close(); // closes the file
	}
	else std::cout << "Unable to open file\n";
}



void writeFile(string fileName)
{
	ofstream testFile(fileName, ios::app); //opens the specified file in write mode, specifically append so it doesn't overwite everything (app = append) (ofstream = output/write)

	if (testFile.is_open()) //checks to see if the file is open before proceeding
	{
		std::cout << "Enter some text: "; //asks the user for some input
		string text; //creates a string to store the text that is going to be written to the file
		std::cin.ignore();
		getline(std::cin, text); // assigns some texts to the string
		testFile << "[" << getTime() << "] " << text << "\n"; //writes the strings value to the opened files with its time
		testFile.close(); // closes the file
	}
	else std::cout << "Unable to open file!\n";
}

void enterNewDirectory()
{
	std::cout << "Enter a new directory: ";//keep cin.ignore() and cin.get() away from this little section XD
	string newDir{};
	getline(std::cin, newDir);
	std::cout << newDir << "\n";
	createDirectory(newDir);
}

void programCore()
{
	bool usingDefaultDirectory{ getUserInput() };
	string fileLocation{ "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/" }; //creates a string called "fileName" which stores the location of the chosen text file
	string fileName{ getFileName() };
	string fileUsed;
	if (usingDefaultDirectory == true)
	{
		fileUsed = fileLocation + fileName; //join two strings together
	}
	else if (usingDefaultDirectory == false)
	{
		fileUsed = fileName; // Trying to get it to work so that it looks at an etered directory!!
	}



	string answer{ getUserInputWR() }; //creates a string called "answer" to store the users answer received from the "getUserInput" function

	if (answer == "read" || answer == "Read") //checks to see if the value of "answer" is either "read" or "Read"
	{
		std::cout << "\n";
		readFile(fileUsed); //calls the "readFile" function, passing the "fileName" variable
	}
	else if (answer == "write" || answer == "Write") //checks to see if the value of "answer" is either "write" or "Writes"
	{
		writeFile(fileUsed); //calls the "writeFile" function, passing the "fileName" variable
	}

	enterNewDirectory();

	cout << "Exit program? (Y/N) ";
	string exitAnswer{}; //stores the value for the users choice on whether to exit the program or not.
	std::cin >> exitAnswer;
	
	if (exitAnswer == "n" || exitAnswer == "N")
	{
		programCore(); //goes back to the beginning of the function... I hope?
	}
}


*/



int main()
{
	try
	{
		 //creates a new instance of CharacterOperations to store the current users character details in
		std::cout << "Create new character or load character? ";
		std::string userAnswer;
		std::getline(std::cin, userAnswer);

		if (userAnswer == "new" || userAnswer == "New") //decides whether to call the character creation function or the load character function based on previous user input
		{
			playerCharacter.characterCreation();
		}
		else if (userAnswer == "load" || userAnswer == "Load")
		{
			std::cout << "What is the characters name? ";
			std::getline(std::cin, userAnswer);
			playerCharacter.characterName = userAnswer;
			playerCharacter.loadCharacterDetails();
		}


		//std::cin.get();
	}
	catch (const std::exception& e) //passing the exception by reference to "e"
	{

		std::cout << "Error!![ " << e.what() << " ]Restarting program!\n"; //prints the error to the console for the user to see

		std::ofstream exceptionFile("C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/Exceptions.txt", std::ios::app); //opening the "exceptionFile" file for writing

		std::string finalTime{ getTime() };

		exceptionFile << "Error!![ " << e.what() << " ]Restarting program! [" << finalTime << "]\n"; //writes the error message to the opened file

		exceptionFile.close(); //closes the file
	}
	//defaultCharacterFileDir = "C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Character Files/" ;
	//createStruct();
	//TestCharacter liam;
	//liam.loadCharacterDetails();
	//liam.printCharacterDetails();
	/*
	liam.fillCharacterDetails();
	liam.saveCharacterDetails();
	liam.printCharacterDetails();
	*/
	//readStructFromFile();
	
	//programCore();

	//createCharacters();
	
	return 0;
}
