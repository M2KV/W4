#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int* numerator, * denominator;
	int gcd(int a, int b);

public:
	Fraction();
	Fraction(const int& _numerator);
	Fraction(const int& _numerator, const int& _denominator);
	Fraction(const Fraction& fr);
	~Fraction();

	void s_numerator(const int& _numerator);
	void s_denominator(const int& _denominator);
	int g_numerator();
	int g_denominator();

	Fraction reduction();
	Fraction inversion();

	Fraction operator+(const Fraction& a);
	Fraction operator-(const Fraction& a);
	Fraction operator*(const Fraction& a);
	Fraction operator/(const Fraction& a);
	double tof();
	Fraction operator =(const Fraction& fr);

	friend istream& operator>>(istream& input, Fraction& temp);
	friend ostream& operator<<(ostream& output, const Fraction& temp);

};

