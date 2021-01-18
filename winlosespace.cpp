/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include "winlosespace.hpp"
#include "utilities.hpp"


/**********************************************************
                        constructor
parameters: none
description:  Initializes space type, description & space-
 specific sub-menu. Pointers initialized to null & actionTaken
 to false in base constructor.
returns: n/a
**********************************************************/
WinLoseSpace::WinLoseSpace(std::string typeIn, std::string desc1In,
                           std::string menuIn)
{
    type = typeIn;
    descrip1 = desc1In;
    menu = menuIn;
}


/**********************************************************
                   doAction() - overridden
parameters: none
description: Allows user to choose whether to return to boat.
  Note: returning to boat with or without treasure will end
  game.
returns: true if user decides to return to boat, false
 otherwise (bool)
**********************************************************/
bool WinLoseSpace::doAction(bool hasTreasure)
{
    if (!actionTaken)
    {
        std::cout << menu;
        int menuChoice = returnValidIntInRange(1, 2);

        // User chooses to act
        if (menuChoice == 1)
        {
            actionTaken = true;
            // Messages displayed via endGameConditions in Game
        }
        // User chooses not to act
        else
            std::cout << "\nYou are consumed by the temptation of riches"
                         " and decide you must continue your quest.\n\n";
    }
    return actionTaken;
}


/**********************************************************
               getDescrip() - overridden
parameters: none
description: Returns single description of space (vs. before
 & after action descriptions required in other spaces)
returns: description of space (string)
**********************************************************/
std::string WinLoseSpace::getDescrip()
{
    return descrip1;
}

