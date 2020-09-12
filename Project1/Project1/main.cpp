#include <iostream>
#include <locale>
#include <cmath>
#define PI 3.14159265

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const double g = 9.8;
	const double  V = 12.5;

	double a, L;
	cout << "¬ведите значение угла: " ;
	cin >> a;

	L = V * V * sin(2 * a * PI / 180) / g;
	cout << L;
	
}