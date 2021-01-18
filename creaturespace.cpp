/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include "creaturespace.hpp"
#include "utilities.hpp"


/**********************************************************
                        constructor
parameters: none
description: Initializes space type, description, & creature
 type. No menu or post-action descriptions required.
 Pointers initialized to null & actionTaken to false in 
 base constructor.
returns: n/a
**********************************************************/
CreatureSpace::CreatureSpace(std::string typeIn, std::string desc1In,
                             std::string creatureTypeIn)
{
    type = typeIn;
    descrip1 = desc1In;
    creatureType = creatureTypeIn;
}


/**********************************************************
              creatureAttack() - overridden
parameters: whether player has dagger or not (bool)
description: Sets probabilities of attack by either shark or
 stingray (depending on space). If player has dagger, chance
 of attack reduced by half. Uses rand to determine if attack
 takes place & if so, displays message re: attack. Back in Game,
 if attack occurs, game immediately ends.
returns: true if player is attacked; false if not
**********************************************************/
bool CreatureSpace::creatureAttack(bool hasDagger)
{
    bool attacked = false;
    
    // Set attack probabilities
    int attackProb = 0;
    if (creatureType == "shark")
    {
        attackProb = 50;
    }
    else
    {
        attackProb = 25;
    }
    // If carrying dagger, reduce chance of attack by half
    if (hasDagger)
    {
        attackProb /= 2;
    }

    // Determine whether attack occurs & if so, print message
    int randAttack = randMinToMax(1,100);
    if (randAttack <= attackProb)
    {
        attacked = true;
        if (creatureType == "shark")
        {
            std::cout << "\nShark attack!\nBefore you can even turn to"
                         " flee, the creature charges towards you!\n"
                         "The last thing you see is a pair of cold,"
                         " dead eyes as the flesh is ripped from your"
                         " body...\n\n";
        }
        else if (creatureType == "stingray")
        {
            std::cout << "\nStingray attack!\nAs you brush past it, the"
                         " disturbed creature whips up its tail and"
                         " pierces your suit with its stinger!\nYou grasp"
                         " at the sharp pain in your chest as you sink" 
                         " to the ship floor...\n\n";
        }
    }

    return attacked;
}


/**********************************************************
                getDescrip() - overridden
parameters: none
description: Returns single description of space (vs. before
 & after action descriptions required in other spaces)
returns: description of space (string)
**********************************************************/
std::string CreatureSpace::getDescrip()
{
    return descrip1;
}


/**********************************************************
                       doAction()
parameters: bool
description: Dummy definition for pure virtual function.
 Never used for this class
returns: bool
**********************************************************/
bool CreatureSpace::doAction(bool)
{
    return false;
}

