#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Create a vector called cars that will store strings
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // Print vector elements
	for (string car : cars) {
  	cout << car << "\n";
	}
	
	cout << "\nFront: " << cars.front() << endl;
	cout << "Back: " << cars.back();
}