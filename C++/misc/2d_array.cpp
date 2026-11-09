#include <iostream>
#include <iomanip>
#include "utils.cpp"
using namespace std;

int main()
{
	double matrix[2][2] = {};
	cout << "You're required to input numerical values into a 2d matrix..." << endl;
	
	// Loop for user input
	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < 2; ++col) {
			cout << "Position [" << row << "][" << col << "]: ";
			cin >> matrix[row][col];
		}
	}
	
	// Display the 2d matrix
	cout << "\nHere is your matrix in tabular form." << endl;
	for (int row = 0; row < 2; ++row)
	{
		for (int col = 0; col < 2; ++col)
		{
			cout << setw(2) << matrix[row][col] << " ";
		}
		cout << endl;
	}
}