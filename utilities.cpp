/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include <sstream>
#include <ctime>
#include "utilities.hpp"


/**********************************************************
                 returnValidIntInRange()
parameters: minimum and maximum value (ints)
description: Gets input from user, as a string, checks if it
 is a valid integer between min and max values (inclusive).
 If not valid, error messages are printed. Loops until a valid
 integer is entered.
returns: valid integer (int)
**********************************************************/
int returnValidIntInRange(int min, int max)
{
    bool isInt = false;
    std::string userInp;
    int validInt;
    char c;
    
    do
    {
        // Get user input & convert to stringstream object
        getline(std::cin, userInp);
        std::stringstream ss(userInp);
        
        // If integer successfully stored & nothing left on buffer
        if (ss >> validInt && !(ss >> c))
        {
            // Ensure int also within range
            if (validInt >= min && validInt <= max)
            {
                isInt = true;
            }
            else
            {
                std::cout << "Not a valid entry. Please try again."
                          << std::endl;
            }  
        }
        else
        {
            std::cout << "Not a valid entry. Please try again."
                      << std::endl;
        }
    }
    while (!isInt);
    
    return validInt;
}


/**********************************************************
                     returnValidInt()
parameters: none
description: Gets input from user, as a string, checks if it
 is a valid integer.
 If not valid, error messages are printed. Loops until a valid
 integer is entered.
returns: valid integer (int)
**********************************************************/
int returnValidInt()
{
    bool isInt = false;
    std::string userInp;
    int validInt;
    char c;
    
    do
    {
        // Get user input & convert to stringstream object
        getline(std::cin, userInp);
        std::stringstream ss(userInp);
        
        // If integer successfully stored & nothing left on buffer
        if (ss >> validInt && !(ss >> c))
        {
                isInt = true;
        }
        else
        {
            std::cout << "Not a valid entry. Please try again."
                      << std::endl;
        }
    }
    while (!isInt);
    
    return validInt;
}


/**********************************************************
                    returnFirstChar()
parameters: string to be parsed (string)
description: Returns the first character of string and returns
 the first character as a char. If the string is empty (e.g.,
 user has only hit <RETURN>), nothing is returned.
returns: nothing
**********************************************************/
char returnFirstChar(std::string strIn)
{
    if (!strIn.empty())
    {    
        char validChar = strIn.at(0);
        return validChar;
    }
}


/**********************************************************
                     randSubscript()
parameters: array/vector size (int)
description: Gets seed value via time() only 1st call only
 Runs rand() to obtain pseudorandom number & uses modulus to
 convert random value to an integer between 0 and (size - 1)
 inclusive, i.e., an in-bounds subscript.
returns: random integer between 0 and (size - 1) (int)
**********************************************************/
int randSubscript(int contSize)
{
    // get seed via time function only on first call
    static int runCount = 0;
    if (runCount == 0)
    {
        std::srand(time(0));
        runCount++;
    }

    return (std::rand() % contSize);
}


/**********************************************************
                     randMinToMax()
parameters: min and max values (ints)
description: Gets seed value via time() only 1st call only
 Runs rand() to obtain pseudorandom number & uses modulus &
 formula to convert random value to an integer between min
 & max, inclusive.
returns: random integer between min & max (int)
**********************************************************/
int randMinToMax(int minIn, int maxIn)
{
    // get seed via time function only on first call
    static int runCount = 0;
    if (runCount == 0)
    {
        std::srand(time(0));
        runCount++;
    }

    return ((std::rand() % (maxIn - minIn + 1)) + minIn);
}