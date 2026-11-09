//
// Created by Prosper.dev on 20/07/2026.
//
#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 23, 34, 546, 678};
    int *arrPtr = arr;
    cout << "Base address of arr[]: " << arrPtr << endl << endl;

    // Loop thru array and output address values
    for (int i = 0; i < size(arr); ++i) {
        cout << "Address: " << arrPtr + i
        << ", Value: " << arr[i] << endl;
    }
}