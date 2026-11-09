#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name = "Prosper.dev";
	string *namePtr = &name;
	cout << "*namePtr = " << namePtr << endl;
	cout << "namePtr references name to obtain: " << *namePtr << endl;
}