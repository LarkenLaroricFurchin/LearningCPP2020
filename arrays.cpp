#include <iostream>
#include <string>
#include <fstream>
#include "structs.h"

void createCharacters()
{
	TestCharacter character[4]{};

	for (int count{ 0 }; count < 4; ++count)
	{
		character[count].fillCharacterDetails();
		character[count].saveCharacterDetails();
	}
}