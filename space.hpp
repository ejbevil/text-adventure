/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

class Space
{
    protected:
        std::string type;
        std::string descrip1,
                    descrip2,
                    postAction,
                    menu;
        Space* left;
        Space* right;
        Space* top;
        Space* bottom;
        bool actionTaken;

        Space();    // constructor protected to prevent instantiation

    public:

        void setLeft(Space*);
        void setRight(Space*);
        void setTop(Space*);
        void setBottom(Space*);
        void setActionTaken();

        Space* getLeft();
        Space* getRight();
        Space* getTop();
        Space* getBottom();
        std::string getType();
        bool getActionTaken();
        virtual std::string getDescrip();

        virtual bool creatureAttack(bool);
        virtual bool doAction(bool) = 0;

        virtual ~Space() = 0;
};
#endif