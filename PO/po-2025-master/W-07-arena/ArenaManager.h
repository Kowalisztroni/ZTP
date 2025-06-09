#ifndef ARENA_MANAGER_H__
#define ARENA_MANAGER_H__

#include <string>
#include "Ogre.h"
#include "Dwarf.h"


class ArenaManager
{
    Unit &unit1;
    Unit &unit2;

public:
    ArenaManager( Unit & u1,  Unit & u2);
    
    void fight();
    std::string getWinnerName() const;
};


#endif