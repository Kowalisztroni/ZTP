#ifndef GRA_H__
#define GRA_H__

#include <string>
#include "Plansza.h"
#include "Gracz.h"

class Gra
{
    Plansza & plansza;
    Gracz & gracz1;
    Gracz & gracz2;
public:
    Gra (Plansza & p, Gracz & g1, Gracz & g2 );
    std::string graj();
};


#endif