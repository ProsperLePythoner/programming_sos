#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool isEven(int);
bool isPrime(int);

int main()
{
    int range;
    string parityType;
    int n = 1;
    int count = 0;

    cout << "Enter a range of numbers to output for a parity check (even, odd, or prime).\n"
         << "Range: ";
    cin >> range;

    cout << "\nParity type (even/odd/prime): ";
    cin >> parityType;

    // Simple manual conversion to lowercase (exam-friendly)
    for(size_t i = 0; i < parityType.length(); i++) {
        if(parityType[i] >= 'A' && parityType[i] <= 'Z') {
            parityType[i] = parityType[i] + 32;
        }
    }

    cout << endl;

    if(parityType == "even") {
        cout << "Output of " << range << " even numbers....." << endl;
        while(count < range) {
            if(isEven(n)) {
                cout << n << " ";
                count++;
            }
            n++;
        }
    }
    else if(parityType == "odd") {
        cout << "Output of " << range << " odd numbers....." << endl;
        while(count < range) {
            if(!isEven(n)) {
                cout << n << " ";
                count++;
            }
            n++;
        }
    }
    else if(parityType == "prime") {
        cout << "Output of " << range << " prime numbers....." << endl;
        while(count < range) {
            if(isPrime(n)) {
                cout << n << " ";
                count++;
            }
            n++;
        }
    }
    else {
        cout << "Invalid parity type entered! Please use even, odd or prime." << endl;
    }

    cout << endl;
    return 0;
}

// Function definitions
bool isEven(int n)
{
    return (n % 2 == 0);
}

bool isPrime(int n)
{
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}