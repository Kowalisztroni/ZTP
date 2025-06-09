#ifndef GRACZ_H__
#define GRACZ_H__

#include <string>
#include "Plansza.h"

class Gracz
{
    std::string imie;
    Plansza & plansza;
public:
    Gracz (const std::string & im, Plansza & p);
    std::string get_imie() const { return imie; }
    void skresl();
};

#endif