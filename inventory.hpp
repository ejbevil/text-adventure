/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>

class Inventory
{
    private:
        const int MAXITEMS = 2;
        std::vector<std::string> inv;

    public:
        Inventory() = default;
        void addToInventory(std::string);
        void listInventory();
        bool searchInInventory(std::string);
        void removeFromInventory(std::string);
        void clearInventory();
        ~Inventory() = default;
};


#endif
