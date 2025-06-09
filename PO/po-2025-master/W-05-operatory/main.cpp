#include <iostream>

class Zespolona
{
	double re;
	double im;
public:
	Zespolona ( double r, double i);

	friend Zespolona operator+(const Zespolona & lewy, const Zespolona & prawy);
	friend std::ostream &  operator<<(std::ostream & str, const Zespolona & value);

	Zespolona operator-(const Zespolona & prawy) const;

	void info() const;
};


Zespolona::Zespolona( double r, double i) : re {r}, im{i} {}
void Zespolona::info() const
{
	std::cout << re << " + " << im << "i" << std::endl;
}

Zespolona operator+(const Zespolona & lewy, const Zespolona & prawy)
{
	Zespolona tmp { 0, 0 };
	tmp.re = lewy.re + prawy.re;
	tmp.im = lewy.im + prawy.im;

	return tmp;
}

Zespolona Zespolona::operator-(const Zespolona & prawy) const
{
	Zespolona tmp { 0, 0 };
	tmp.re = re - prawy.re;
	tmp.im = im - prawy.im;

	return tmp;
}

std::ostream & operator<<(std::ostream & str, const Zespolona & value)
{
	str << "Operator: " << value.re << " + " << value.im << "i";
	return str;
}

int main()
{
	Zespolona z1 {1, 2};
	Zespolona z2 {3, 4};
	Zespolona z3 {0, 0};

	z1.info();

	z3 = z1+z2;
	// z3 = operator+(z1, z2);
	z3.info();

	z3 = z1 - z2;
	z3.info();

	std::cout << z3 << std::endl;
	// std::ostream
}