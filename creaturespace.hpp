/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#ifndef CREATURESPACE_HPP
#define CREATURESPACE_HPP

#include <string>
#include "space.hpp"

class CreatureSpace : public Space
{
    protected:
        std::string creatureType;
        
    public:
        CreatureSpace(std::string, std::string, std::string);
        CreatureSpace() = default;
        virtual std::string getDescrip() override;
        virtual bool doAction(bool) override;
        virtual bool creatureAttack(bool) override;
        ~CreatureSpace() override = default;
};
#endif