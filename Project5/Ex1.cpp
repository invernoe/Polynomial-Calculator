#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
using namespace std;

struct poly {
	int order;
	double x;
	double coeffVal[20];
};

poly readPoly(){
	poly m;
	cout << "Enter polynomial order: ";
	cin >> m.order;
	cout << "Enter polynomial coefficients: ";
	for (int i = 0; i <= m.order; i++)
	{
		cin >> m.coeffVal[i];
	}
	cout << "Enter the value of x: ";
	cin >> m.x;

	return m;
}

double evalPoly(poly p) {
	int order = p.order;
	double m = 0;
	for (int i = 0; i <= p.order; i++)
	{
		m += p.coeffVal[i] * pow(p.x, order);
		order--;
	}
	return m;
}

void main() {
	poly x = readPoly();
	int power = x.order;
	cout << "f(x) = ";
	for (int i = 0; i <= x.order; i++)
	{
		if (x.coeffVal[i] != 0) {
			if (power == 1) {
			cout << x.coeffVal[i] << "x ";
			if (x.coeffVal[i + 1] > 0)
				cout << "+";
			}
			else if (power == 0)
				cout << x.coeffVal[i];
			else {
				cout << x.coeffVal[i] << "x^" << power << " ";
				if (x.coeffVal[i + 1] > 0)
					cout << "+";
			}

		}
		power--;
	}
	cout << endl << "f(x = " << x.x << ") = " << evalPoly(x) << endl;
	system("pause");
}