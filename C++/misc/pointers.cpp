#include <iostream>
#include "utils.cpp"
using namespace std;

int main()
{
	int randomNum = 45;
	int *randomNumPtr = &randomNum;
	
	cout << "Value of randomNum = " << randomNum << endl;
	cout << "Address of randomNum = " << &randomNum << endl;
	cout << "Value of randomNum stored in *randomNumPtr = " << *randomNumPtr << endl;
}