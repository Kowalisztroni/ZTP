#include "Ogre.h"

Ogre::Ogre (const std::string & name) : Unit {name, 100}
{

}


int Ogre::getAttackStr() const
{
    return rand() % 20;
}