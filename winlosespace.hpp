/**********************************************************
** Program name: winlose.hpp (final)
** Author: Erica Bevilacqua
** Date: 6/12/18
** Description: WinLoseSpace (derived) class declaration
**********************************************************/

#ifndef WINLOSESPACE_HPP
#define WINLOSESPACE_HPP

#include <string>
#include "space.hpp"

class WinLoseSpace : public Space
{
    protected:

    public:
        WinLoseSpace(std::string, std::string, std::string);
        WinLoseSpace() = default;
        virtual std::string getDescrip() override;
        virtual bool doAction(bool) override;
        ~WinLoseSpace() override = default;
};
#endif