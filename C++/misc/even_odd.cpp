#include <iostream>
#include <iomanip>
#include "utils.cpp"
using namespace std;

int main()
{
	int arr[10] = {};
	cout << "----- EVEN AND ODD NUMBER COUNTER PROGRAM -----\n" << endl;
	cout << "You are required to input 10 values into an array...\n";
	
	// Loop 10 times for user input
	for (int i = 0; i < 10; ++i) {
		cout << "\tElement " << i + 1 << ": ";
		cin >> arr[i];
	} 
	
	// Compute number of even and odd elements
	int even = 0;
	int odd = 0;
	
	for (int i = 0; i < 10; ++i)
	{
		if (isEven(arr[i])) {
			even++;
			continue;
		}
		odd++;
	}
	
	cout << "\nRESULTS:" << endl;
	cout << "Even numbers: " << even << endl;
	cout << "Odd numbers: " << odd << endl;
}