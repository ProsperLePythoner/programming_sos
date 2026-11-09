#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printPascalTriangle(int rows) {
    for(int i = 0; i < rows; i++) {
        // Print leading spaces for centering
        cout << string((rows - i - 1) * 4, ' ');
        
        long long current = 1;
        
        for(int j = 0; j <= i; j++) {
            cout << setw(6) << current;
            
            // Multiplicative formula (easiest logic)
            current = current * (i - j) / (j + 1);
        }
        
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    
    cout << "\nPascal's Triangle:\n\n";
    printPascalTriangle(rows);
    
    return 0;
}