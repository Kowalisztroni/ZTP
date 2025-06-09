#ifndef WITCHER_H__
#define WITCHER_H__

#include <string>
#include "Unit.h"

class Witcher : public Unit {
    int healing_potion_cooldown;
public:
    explicit Witcher (const std::string & name);

    int getAttackStr() const;
    void hitUnit(int damage);
};


#endif