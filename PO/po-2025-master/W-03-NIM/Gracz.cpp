#include "Gracz.h"
#include <iostream>

Gracz::Gracz (const std::string & im, Plansza & p) : plansza{p}
{
    imie = im;
}

void Gracz::skresl()
{
    int rzad, kreski;
    do {
        plansza.wyswietl();
        //std::cin.ignore(100000, '\n');
        std::cout << imie << ", podaj rzad: ";
        std::cin >> rzad;

        std::cout << "Ile kresek: ";
        std::cin >> kreski;
    } while (plansza.skresl(rzad-1, kreski) == false);
}