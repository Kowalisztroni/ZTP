
#include <iostream>
#include "Plansza.h"
#include <ranges>

Plansza::Plansza()  {
	// vec.size();
	// vec.clear();
	// vec.push_back(value);
	// vec.resize(4);  
	//vec[0];
	// vec.at(0)
	stan = {1,3,5,7};
}

void Plansza::wyswietl(std::ostream & out) const
{
	// for (size_t i=0; i<stan.size(); ++i)
	// 	std::cout << stan[i] << std::endl;
	
	// //int row=1;
	// for (int row=1; auto &count: stan){  
	// 	std::string txt (count, '|');
	// 	std::cout << row << ": " << txt << std::endl;
	// 	++row;
	// }
	// for (int row=0; auto &count: stan){  // c++20 - range for with initializer
	for (auto [row, count]: std::views::zip(std::views::iota(1), stan)) // c++23 ?
	{
		std::string txt (count, '|');
		out << row << ": " << txt << std::endl;
	}
}

// rzad - startuje od 0
bool Plansza::skresl(int rzad, int kreski)
{
	// if ( 0 <= rzad and rzad < std::ssize(stan) ) {
	// 	if (kreski > 0) {
	// 		if (stan[rzad] >= kreski )
	// 		{
	// 			stan[rzad] -= kreski;
	// 			return true;
	// 		}
	// 	}
	// }

	if (rzad <0 or rzad >= std::ssize(stan))
		return false;

	if (kreski <= 0)
		return false;

	if (stan[rzad] < kreski)
		return false;

	stan[rzad] -= kreski;
	return true;
}
#include <algorithm>

bool Plansza::czy_koniec() const
{
	for (auto v: stan)
		if ( v>0 ) 
			return false;
	
	return true;

	return std::all_of(stan.begin(), stan.end(), [](int v) { return v==0;});
}