#include "Fraction.h"

int Fraction::gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

Fraction::Fraction()
{
	numerator	= new int;
	denominator	= new int;

	*numerator		= NULL;
	*denominator	= 1;
}

Fraction::Fraction(const int& _numerator)
{
	numerator	= new int;
	denominator = new int;
	
	*numerator		= _numerator;
	*denominator	= 1;
}

Fraction::Fraction(const int& _numerator, const int& _denominator)
{
	numerator	= new int;
	denominator = new int;

	*numerator		= _numerator;
	*denominator	= _denominator;
}

Fraction::Fraction(const Fraction& fr)
{
	numerator	= new int;
	denominator = new int;

	*numerator		= *fr.numerator;
	*denominator	= *fr.denominator;
}

Fraction::~Fraction()
{
	delete numerator;
	delete denominator;

	numerator	= nullptr;
	denominator = nullptr;
}

void Fraction::s_numerator(const int& _numerator)
{
	*numerator = _numerator;
}

void Fraction::s_denominator(const int& _denominator)
{
	*denominator = _denominator;
}

int Fraction::g_numerator()
{
	return *numerator;
}

int Fraction::g_denominator()
{
	return *denominator;
}

Fraction Fraction::reduction()
{
	int g = gcd(*numerator, *denominator);

	Fraction tmp(*numerator / g, *denominator / g);
	return tmp;
}

Fraction Fraction::inversion()
{
	Fraction tmp(*denominator, *numerator);

	return tmp;
}

Fraction Fraction::operator+(const Fraction& a)
{
	Fraction temp((*numerator) * (*a.denominator) + (*a.numerator) * (*denominator), *(denominator) * *(a.denominator));
	return temp;
}
Fraction Fraction::operator-(const Fraction& a)
{
	Fraction temp((*numerator) * (*a.denominator) - (*a.numerator) * (*denominator), (*denominator) * (*a.denominator));
	return temp;
}

Fraction Fraction::operator*(const Fraction& a)
{
	Fraction temp((*numerator) * (*a.numerator), (*denominator) * (*a.denominator));
	return temp;
}

Fraction Fraction::operator/(const Fraction& a)
{
	Fraction temp((*numerator) * (*a.denominator), (*denominator) * (*a.numerator));
	return temp;
}

Fraction Fraction::operator=(const Fraction& fr)
{
	*numerator		= *fr.numerator;
	*denominator	= *fr.denominator;

	return *this;
}

double Fraction::tof()
{
	return 1.f * (*numerator) / (*denominator);
}

istream& operator>>(istream& input, Fraction& temp)
{
	cout << "Input numerator and denominator: ";
	input >> *temp.numerator;

	do
	{
		input >> *temp.denominator;
		
		if (*temp.denominator == 0) 
			cout << "Invalid denominator. \nInput agains: ";

	} while (*temp.denominator == 0);
	return input;
}

ostream& operator<<(ostream& output, const Fraction& temp)
{
	output << *temp.numerator << "/" << *temp.denominator;
	return output;
}