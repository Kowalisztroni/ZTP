#include <iostream>
#include <string>

#include <sstream>
#include <cassert>
#include "Plansza.h"
#include "Gracz.h"
#include "Gra.h"

void test_planszy()
{
	Plansza p;
	
	// p.wyswietl();

	std::stringstream s;
	p.wyswietl(s);
	std::string result = s.str();

	// tu sprawdzamy, czy result zawiera to co powinien
	if(result[0] == '1')
		std::cout << result << std::endl;

	assert ( p.skresl(-1, 1) == false );
	assert ( p.skresl(4, 1) == false );
	assert ( p.skresl(1, -1) == false ); 
	assert ( p.skresl(1, 0) == false ); 
	assert ( p.skresl(0, 2) == false );
	assert ( p.skresl(0, 1) == true );

	p.wyswietl();

	assert ( p.czy_koniec() == false );
	assert ( p.skresl(1, 3) == true );
	assert ( p.skresl(2, 5) == true );
	assert ( p.skresl(3, 7) == true );
	assert ( p.czy_koniec() == true );

	p.wyswietl();


}

void test_gracza()
{
	Plansza p;
	Gracz g1 {"Adam", p};

	g1.skresl();
	p.wyswietl();
}

int main() 
{
	// test_planszy();
	// test_gracza();

	std::cout << "NIM Game" << std::endl;

	Plansza p;
	Gracz g1 {"Ala", p};
	Gracz g2 {"Jan", p};

	Gra gra {p, g1, g2};

	std::string wygral = gra.graj();

	std::cout << wygral << std::endl;


	return 0;
}
