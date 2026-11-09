#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int num1 = 100;
	int num2 = 34;
	cout << "num1, num2 = " << num1 << ", " << num2 << endl;
	swap(&num1, &num2); // addresses, i.e. pointers
	cout << "num1, num2 = " << num1 << ", " << num2 << endl;
}