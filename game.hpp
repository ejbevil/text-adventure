/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "inventory.hpp"
#include "space.hpp"
#include "utilities.hpp"


class Game
{
    enum Direction {UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

    private:
        Inventory inv;
        int airSupply;
        bool doorUnlocked,
             portholeOpened;
        Space* head;
        Space* currSpace;

        void createWorld();
        void move();
        bool validMove(Space*);
        void act();
        void processAction();
        void readMap();
        bool checkEndConditions();

    public:
        Game();
        void runGame();
        ~Game();

};
#endif