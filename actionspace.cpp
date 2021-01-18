/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include "actionspace.hpp"
#include "utilities.hpp"


/**********************************************************
                        constructor
parameters: none
description: Initializes space type, before & after action
 descriptions, post-action message, & space-specific sub-menu.
 Pointers initialized to null & actionTaken to false in 
 base constructor.
returns: n/a
**********************************************************/
ActionSpace::ActionSpace(std::string typeIn, std::string desc1In,
std::string desc2In, std::string postActionIn, std::string menuIn)
{
    type = typeIn;
    descrip1 = desc1In;
    descrip2 = desc2In;
    postAction = postActionIn;
    menu = menuIn;
}


/**********************************************************
                       doAction()
parameters: whether key is in inventory (bool)
description:  If space's action has not already been completed,
 prompts user with menu to act or skip action for space. If act
 selected, checks if key is present for spaces requiring it, and
 if present or not required, toggles actionTaken & prints post-
 action message to user. Also prints messages if user chooses
 not to act, key not in possession, or action already taken.
returns: true if action performed this function call, false if
 no action performed (bool)
**********************************************************/
bool ActionSpace::doAction(bool hasKey)
{
    // Flag whether action is performed during this call
    bool actionPerformed = false;

    // If Space's action not yet complete
    if (!actionTaken)
    {
        std::cout << menu;
        int menuChoice = returnValidIntInRange(1,2);

        // User chooses to act
        if (menuChoice == 1)
        {
            // Conditionals for actions requiring key
            if ((type == "chestRoom" || type == "lockedDoorRoom") && !hasKey)
            {
                std::cout << "\nImpossible without a key!\n\n";
            }

            else
            {
                // Toggle space's action flag
                actionTaken = true;

                // Indicate action performed *this* call only
                actionPerformed = true;
                std::cout << postAction;
            }
        }
        // User chooses not to act
        else
            std::cout << "\nYou decide it's best to go about your business.\n\n";
    }

    // Space's action already completed
    else
    {
        std::cout << "\nThere's nothing more to do here.\n\n";
    }

    return actionPerformed;

}
