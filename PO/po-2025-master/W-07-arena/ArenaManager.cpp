#include "ArenaManager.h"
#include <iostream>

ArenaManager::ArenaManager( Unit & u1,  Unit & u2) :unit1{u1}, unit2{u2}
{
    // unit1 = u1;
    // unit2 = u2;
}

void ArenaManager::fight()
{
    while (unit1.isAlive() and unit2.isAlive())
    {
        int dmg1 = unit1.getAttackStr();
        int dmg2 = unit2.getAttackStr();

        unit1.hitUnit(dmg2);
        unit2.hitUnit(dmg1);

        std::cout << unit1.getName() << "::" << unit1.getHealth() << " hits for " << dmg1 << std::endl;
        std::cout << unit2.getName() << "::" << unit2.getHealth() << " hits for " << dmg2 << std::endl;
    }
}

// funkcja powinna być wywołana po przeprowadzeniu walki
std::string ArenaManager::getWinnerName() const
{
    if (unit1.isAlive())
        return unit1.getName();
    if (unit2.isAlive())
        return unit2.getName();
    return "Gravedigger";
}