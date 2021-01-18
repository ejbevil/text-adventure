/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include "inventory.hpp"


/**********************************************************
                     addToInventory()
parameters: item to add (string)
description: If vector not full, pushes item onto vector.
 If full, displays error message
returns: nothing
**********************************************************/
void Inventory::addToInventory(std::string item)
{
    if (inv.size() < MAXITEMS)
    {
        inv.push_back(item);
    }
    else
    {
        std::cout << "Your bag is full! Remove an item to add a new one\n";
    }
}

/**********************************************************
                     listInventory()
parameters: none
description: Displays list of items (strings) in vector or
 "nothing" if empty.
returns: nothing
**********************************************************/
void Inventory::listInventory()
{
    std::cout << "< Your bag currently contains: >\n";
    if (inv.empty())
    {
        std::cout << "nothing\n";
    }
    else
    {
        for (int i = 0; i < inv.size(); i++)
        {
            if (inv.at(i) != "")
            {
                std::cout << inv.at(i) << "\n";
            }
        }
    }
    std::cout << "\n";
}


/**********************************************************
                   searchInInventory()
parameters: item to look for (string)
description: Converts passed item name to lowercase, then
 attempts locate item in vector.
returns: true if item found; false if not found
**********************************************************/
bool Inventory::searchInInventory(std::string itemToCheck)
{
    bool found = false;
    // Convert passed string to lowercase
    for (int c = 0; c < itemToCheck.size(); c++)
    {
        itemToCheck.at(c) = tolower(itemToCheck.at(c));
    }
    // Check in inventory
    for (int i = 0; i < inv.size() && !found; i++)
    {
        if (inv.at(i) == itemToCheck)
        {
            found = true;
        }
    }
    return found;
}


/**********************************************************
                   removeFromInventory()
parameters: item to remove (string)
description: Converts passed item name to lowercase, then
 locates item in vector & if found, erases it.
returns: nothing
**********************************************************/
void Inventory::removeFromInventory(std::string itemToRemove)
{
    bool found = false;
    // Convert passed string to lowercase
    for (int c = 0; c < itemToRemove.size(); c++)
    {
        itemToRemove.at(c) = tolower(itemToRemove.at(c));
    }
    // Check in inventory & erase item if found
    for (int i = 0; i < inv.size() && !found; i++)
    {
        if (inv.at(i) == itemToRemove)
        {
            found = true;
            inv.erase(inv.begin() + i);
        }
    }
}


/**********************************************************
                   clearInventory()
parameters: none
description: Clears all items from inventory.
returns: nothing
**********************************************************/
void Inventory::clearInventory()
{
    inv.clear();
}

