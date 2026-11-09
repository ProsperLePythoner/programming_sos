#include <iostream>
#include <cmath>
using namespace std;

// Global constant for interest rate
const double RATE = 0.12;

// function prototype for final amount calculator
double calculateAmount(double, int);

int main()
{
	int years;
	double principal;
	cout << "Enter principal amount: $";
	cin >> principal;
	cin.ignore();
	cout << "Enter number of years: ";
	cin >> years;
	cin.ignore();
	
	cout << "\nYour final amount after " << years << " years is: $" 
		<< calculateAmount(principal, years);
	cout << "\nInterest thus earned: $" << calculateAmount(principal, years) - principal << endl;
	return 0;
}

double calculateAmount(double p, int n) {
	return p * pow((1 + RATE), n);
}