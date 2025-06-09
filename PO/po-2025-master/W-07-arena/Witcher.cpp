#include "Witcher.h"

Witcher::Witcher (const std::string & name) : Unit {name, 80}
{
    healing_potion_cooldown = 0;
}

int Witcher::getAttackStr() const
{
    return rand()%10;
}

void Witcher::hitUnit(int damage)
{
    Unit::hitUnit(damage);
    if (healing_potion_cooldown == 0)
    {
        if (getHealth() < 40)
        {
            // health += 5;
            Unit::hitUnit(-5);
            // byc może rozsądniejsze byłoby przeniesienie health do składowych chronionych...
            healing_potion_cooldown = 5;
        }
    }
    else
        --healing_potion_cooldown;
}