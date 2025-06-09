#include "Unit.h"

Unit::Unit (const std::string & name, int hp) : name{name}, health{hp} {}

int Unit::getAttackStr() const
{
    return 1;
}
void Unit::hitUnit(int damage)
{
    health -= damage;
}
int Unit::getHealth() const
{
    return health;
}
std::string Unit::getName() const
{
    return name;
}

 bool Unit::isAlive() const
 {
    return health > 0;
 }