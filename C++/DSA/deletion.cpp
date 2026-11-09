//
// Created by Prosper.dev on 20/07/2026.
//
#include <iostream>
using namespace std;

void deletion(float arr[], const int n, const int pos) {
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
}

void display(float arr[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    float arr[10] = {12, 23, 34, 56, 24, 45, 67, 34, 65};
    cout << "Welcome to the Deletion Algorithm!" << endl;
    cout << "Here is an arbitrary array..." << endl;
    display(arr, 10);

    int index;
    cout << endl;
    cout << "\nWhat index do you want to delete from (0-9)? ";
    cin >> index;

    if (index >= 0 && index < 10) {
        deletion(arr, 10, index);
        cout << "Here is your array after deletion:" << endl;
        display(arr, 10);
    } else {
        cout << "Index is out of bounds." << endl;
    }
    return 0;
}