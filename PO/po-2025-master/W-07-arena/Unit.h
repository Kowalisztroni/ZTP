#ifndef UNIT_H__
#define UNIT_H__

#include <string>

class Unit {
    std::string name;
    int health;

public:
    Unit (const std::string & name, int hp);

    virtual int getAttackStr() const;
    virtual void   hitUnit(int damage);
    
    int getHealth() const;
    std::string getName() const;
    bool isAlive() const;

    virtual ~Unit() {}
};


#endif


