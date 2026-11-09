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
	
	// Display sum and average
	int sum = calculateSum(arr, 10);
	int average = sum / 10.0;
	
	cout << "\nYour array is:\n";
	displayArr(arr, 10);
	cout << "Sum of elements: " << sum << endl;
	cout << "Average of elements: " << average << endl;
}