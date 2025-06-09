#include "Gra.h"

Gra::Gra(Plansza & p, Gracz & g1, Gracz & g2 ) : 
    plansza {p}, gracz1 {g1}, gracz2 {g2}
{
    
}

std::string Gra::graj()
{
    while(true)
    {
        gracz1.skresl();
        if (plansza.czy_koniec())
            return gracz1.get_imie();
        gracz2.skresl();
        if (plansza.czy_koniec())
            return gracz2.get_imie();
    }
}