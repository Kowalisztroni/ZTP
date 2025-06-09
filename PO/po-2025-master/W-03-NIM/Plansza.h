#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <vector>
#include <iostream>

class Plansza {
	std::vector<int> stan; 
public:
	Plansza();
	
	void wyswietl(std::ostream & out = std::cout) const;

	bool skresl(int rzad, int kreski);

	bool czy_koniec() const;
	

};

#endif /* PLANSZA_H_ */
