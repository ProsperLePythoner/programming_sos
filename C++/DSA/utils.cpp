//
// Created by Prosper.dev on 20/07/2026.
//
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