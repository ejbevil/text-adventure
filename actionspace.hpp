/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#ifndef ACTIONSPACE_HPP
#define ACTIONSPACE_HPP

#include <string>
#include "space.hpp"

class ActionSpace : public Space
{
    protected:

    public:
        ActionSpace(std::string, std::string, std::string,
                    std::string, std::string);
        ActionSpace() = default;
        virtual bool doAction(bool) override;
        virtual ~ActionSpace() override = default;
};
#endif