//
// Created by Prosper.dev on 20/07/2026.
//
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    cout << "<<<< Welcome to Swapping Madness!!!! >>>>" << endl;
    while (true) {
        int choice;
        cout << "\n\nChoose an option:\n\t1.Swap two numbers\n\t2.Exit\n\t"
                "Your choice? ";
        cin >> choice;

        if (choice == 1) {
            int num1, num2;
            cout << "Enter ur first number: ";
            cin >> num1;
            cout << "Enter ur second number: ";
            cin >> num2;

            cout << "Original: " << num1 << " -> " << num2 << endl;
            swap(&num1, &num2);
            cout << "After swapping!: " << num1 << " -> " << num2 << endl;

        } else if (choice == 2) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
}