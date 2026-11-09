#include <iostream>
#include "utils.cpp"
using namespace std;

int main()
{
	int arr[10] = {};
	cout << "You are required to input 10 values into an array...\n";
	
	// Loop 10 times for user input
	for (int i = 0; i < 10; ++i) {
		cout << "\tElement " << i + 1 << ": ";
		cin >> arr[i];
	} 
	
	cout << "\nHere is your reversed array...\n";
	displayReverse(arr, 10);
}