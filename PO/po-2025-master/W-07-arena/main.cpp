#include <iostream>
#include <cassert>

#include "Unit.h"

#include "Ogre.h"
#include "Dwarf.h"
#include "ArenaManager.h"

void testUnit()
{
    Unit u {"Robert", 10};
    assert ( u.getHealth() == 10);
    u.hitUnit(7);
    assert ( u.getHealth() == 3);
    assert ( u.getName() == "Robert");
    assert ( u.getAttackStr() == 1);
}

void testOgre()
{
    Ogre u {"Shrek"};
    assert ( u.getHealth() == 100);
    u.hitUnit(7);
    assert ( u.getHealth() == 93);
    assert ( u.getName() == "Shrek");
    for (int i=0; i<100; ++i){
        int dmg = u.getAttackStr();
        assert (dmg >=0 );
        assert (dmg < 20);
    }
}

int main()
{
    //testUnit();
    //testOgre();

    srand(time(0));

    Ogre u {"Shrek"};
    Dwarf d {"Jarosław"};

    ArenaManager mgr { u, d };

    mgr.fight();
    std::cout << mgr.getWinnerName() << std::endl;



}
