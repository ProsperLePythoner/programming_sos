//
// Created by Prosper.dev on 20/07/2026.
//
#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void insert(int arr[], int n, int index, int val) {
    for (int i = n;  i > index; i--) {
        arr[i] = arr[i - 1]; // each item gets value 1 index behind itself
    }
    arr[index] = val;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = size(arr); // number of elements
    cout << "Welcome to the Insertion Algorithm!" << endl;
    cout << "Here is the original array:" << endl;
    display(arr, n);

    int index;
    int value;
    cout << endl;
    cout << "\nWhat index do you want to insert at (0-" << n << ")? ";
    cin >> index;

    cout << "Value for insertion at index " << index << "? ";
    cin >> value;
    cout << endl;

    if (index >= 0 && index < n) {
        insert(arr, n, index, value);
        cout << "Here is your array after insertion:" << endl;
        display(arr, n);
    } else {
        cout << "Index is out of bounds." << endl;
    }
    return 0;
}