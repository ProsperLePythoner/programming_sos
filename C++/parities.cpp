#include <iostream>
#include <string>
using namespace std;

// Function prototypes for parity check functions
bool isEven(int);
bool isPrime(int);

int main()
{
	int range;
	int parity;
	int n = 1; // Number counter variable
	
	cout << "Enter a range of numbers to output for a parity check, i.e. even, odd, or prime."
		<< "\nRange: ";
	cin >> range;
	int i = range; // Loop counter variable
	
	cout << "\nParity type:\n1. Even\t2. Odd\t3. Prime\n\nYour choice? ";
	cin >> parity;
	
	// Switch to the appropriate output handler for respective parity input
	switch (parity) {
		case 1:
			cout << "\nOutput of " << range << " even numbers....." << endl;
			while (i > 0) {
				if (isEven(n)) {
					cout << n << "  ";
					i--;
				} n++;
			}
			break;
		
		case 2: {
			cout << "\nOutput of " << range << " odd numbers....." << endl;
			while (i > 0) {
				if (!isEven(n)) {
					cout << n << "  ";
					i--;
				} n++;
			}
			break;
		}
		
		case 3: {
			cout << "\nOutput of " << range << " prime numbers....." << endl;
			while (i > 0) {
				if (isPrime(n)) {
					cout << n << "  ";
					i--;
				} n++;
			}
			break;
		}
		
		default:
			cout << "Invalid value entered! :(" << endl;
	}
	
	cout << endl;
	return 0;
}

// Complete function definitions...
bool isEven(int n)
{
	if (n % 2 == 0)
		return true;
	return false;
}

bool isPrime(int n)
{
	int divisors = 0;
	
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 1; i < n; i++) {
		if (n % i == 0)
			divisors++;
		if (divisors > 1)
			return false;
	}
	return true;
}