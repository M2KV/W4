#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction ft1, ft2, res_ft;

	cout << "Input first fraction: \n\t";
	cin >> ft1;

	cout << "\n";

	cout << "Input second fraction: \n\t";
	cin >> ft2;

	cout << "\n--------------------------------\n";
	cout << "First fraction (a/b): " << ft1 << "\n";
	cout << "Second fraction (a/b): " << ft2 << "\n";

	cout << "\n--------------------------------\n";
	cout << "First fraction (k.xyz): " << ft1.tof() << "\n";
	cout << "Second fraction (k.xyz): " << ft2.tof() << "\n";

	cout << "\n--------------------------------\n";
	cout << "Reduction of first fraction: " << ft1.reduction() << "\n";
	cout << "Reduction of second fraction: " << ft2.reduction() << "\n";

	cout << "\n--------------------------------\n";
	cout << "Inversion of first fraction: " << ft1.inversion() << "\n";
	cout << "Inversion of second fraction: " << ft2.inversion() << "\n";

	cout << "\n--------------------------------\n";
	cout << ft1 << " + " << ft2 << " = " << (res_ft = ft1 + ft2)
		<< "\t- reduction: " << res_ft.reduction()
		<< "\t- float number: " << res_ft.tof() << "\n";

	cout << ft1 << " - " << ft2 << " = " << (res_ft = ft1 - ft2)
		<< "\t- reduction: " << res_ft.reduction()
		<< "\t- float number: " << res_ft.tof() << "\n";

	cout << ft1 << " * " << ft2 << " = " << (res_ft = ft1 * ft2)
		<< "\t- reduction: " << res_ft.reduction()
		<< "\t- float number: " << res_ft.tof() << "\n";

	cout << ft1 << " / " << ft2 << " = " << (res_ft = ft1 / ft2)
		<< "\t- reduction: " << res_ft.reduction()
		<< "\t- float number: " << res_ft.tof() << "\n";

	return 0;
}