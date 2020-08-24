/*
#include <filesystem>//Used to make the stuff in "createDirectory()" work
#include <iostream> //Used for I/O operations with the console
#include <fstream> //used for I/O operations with files
#include <string> //lets me use strings
#include <exception> //stuff for exceptions
#include <ctime>  //used to make the stuff in "getTime()" work
#include <chrono> //used to make the stuff in "getTime()" work
#include "createDirectories.h"


namespace fs = std::filesystem;

std::string getTime()
{
	auto measuredTime = std::chrono::system_clock::now(); //gets the current system time
	std::time_t curTime = std::chrono::system_clock::to_time_t(measuredTime); //converts the measured time into a readable format

	std::string finalTime = ctime(&curTime); //assigns the current, converted, time to the "finalTime" string
	finalTime = finalTime.substr(0, finalTime.length() - 1); //chops the newline off the end!
	//these two lines are there to simply cut the sodding newline off the end of "ctime(&curTime)" 
	return finalTime;
}

void createDirectory(std::string desiredDirectory)
{
	if (fs::exists(desiredDirectory))
	{
		std::cout << "Directory already exists!\n";
	}
	else
	{
		try
		{


			fs::create_directory(desiredDirectory);


			if (fs::exists(desiredDirectory))
			{
				std::cout << "Directory created succesfully at: " << desiredDirectory << std::endl;
			}
			else
			{
				std::cout << "Error! Directory creation failed!\n";
			}
		}
		catch (const std::exception& e) //passing the exception by reference to "e"
		{

			std::cout << "Error!![ " << e.what() << " ]Restarting program!\n"; //prints the error to the console for the user to see

			std::ofstream exceptionFile("C:/Users/LIAMF/Documents/C++ Projects/Learning C++/Log/Exceptions.txt", std::ios::app); //opening the "exceptionFile" file for writing

			std::string finalTime{ getTime() };

			exceptionFile << "Error!![ " << e.what() << " ]Restarting program! [" << finalTime << "]\n"; //writes the error message to the opened file

			exceptionFile.close(); //closes the file
		}
	}
	
	
}
*/