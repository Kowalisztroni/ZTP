#include "Dwarf.h"

Dwarf::Dwarf (const std::string & name) : Unit {name, 50}
{

}


int Dwarf::getAttackStr() const
{
    int dmg = rand() % 10;
    if (getHealth() < 30)
        dmg = 5*dmg + 10;

    return dmg;
}