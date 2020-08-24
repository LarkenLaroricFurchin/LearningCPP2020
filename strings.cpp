#include <iostream>
#include <string>
#include "strings.h"

void findWord()
{
    

    std::string input, word;
    std::getline(std::cin, input);
    std::cin >> word;

    int cnt = 0;
    size_t pos = input.find(word, 0);
    while (pos != std::string::npos)
    {
        cnt++;
        pos = input.find(word, pos + 1);
    }
    std::cout << cnt << std::endl;
    
}
