/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include "space.hpp"


/**********************************************************
                 constructor - default
parameters: none
description: Initializes all pointers to other Spaces and
 actionTaken
returns: n/a
**********************************************************/
Space::Space()
{
    left = nullptr;
    right = nullptr;
    top = nullptr;
    bottom = nullptr;
    actionTaken = false;
}

/**********************************************************
                        setters
parameters: values used to set member variables (data type
 appropriate to variable)
description: Set member variables to passed values
return: nothing
**********************************************************/
void Space::setLeft(Space* leftIn)
{
    left = leftIn;
}

void Space::setRight(Space* rightIn)
{
    right = rightIn;
}

void Space::setTop(Space* topIn)
{
    top = topIn;
}

void Space::setBottom(Space* bottomIn)
{
    bottom = bottomIn;
}

void Space::setActionTaken()
{
    actionTaken = true;
}

/**********************************************************
                        getters
parameters: nothing
description: Return values of member variables
return: member variables (as respective data types)
**********************************************************/
std::string Space::getType()
{
    return type;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getTop()
{
    return top;
}

Space* Space::getBottom()
{
    return bottom;
}

bool Space::getActionTaken()
{
    return actionTaken;
}

std::string Space::getDescrip()
{
    if (!actionTaken)
    {
        // Pre-action space description
        return descrip1;
    }
    else
    {
        // Slightly different post-action description
        return descrip2;
    }
}


/**********************************************************
                   creatureAttack()
parameters: whether player has dagger (bool)
description: Overridden in derived class CreatureSpace.
 Simply returns false for all other classes.
returns: false (bool)
**********************************************************/
bool Space::creatureAttack(bool hasDagger)
{
    return false;
}


/**********************************************************
                        destructor
parameters: n/a
description: Pure virtual
returns: n/a
**********************************************************/
Space::~Space()
{}



