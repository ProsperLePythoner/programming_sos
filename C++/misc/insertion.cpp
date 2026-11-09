#include <iostream>
using namespace std;

void display(int arr[]) {
	for (int i = 0; i < 11; i++) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int array[11] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int position;
	int value;
	
	cout << "Welcome to the << C++ Insertion Emulator Program >>\n\n";
	cout << "We have a simple array here:\n"; display(array);
	cout << "\nEnter any index to insert a number into (0-9, usinilaumu if u choose out of range): ";
	cin >> position;
	cout << "Enter a value to insert into that index: ";
	cin >> value;

	// Perform the insertion operation
	for (int i = 10; i >= position; --i) {
		array[i] = array[i - 1];
	}
	array[position] = value;

	// Display the new array
	cout << "\nHere is your result...\n";
	display(array);
}