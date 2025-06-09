#ifndef OGRE_H__
#define OGRE_H__

#include <string>
#include "Unit.h"

class Ogre : public Unit {

public:
    explicit Ogre (const std::string & name);

    int getAttackStr() const;
};


#endif