#include <iostream>
using namespace std;

// makes the array on the heap,  must delete it AFTER USE
int* inputIDs(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    return arr;
}

// goes from left to right and stops at the first match
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;   // first occurrence is enough
    return -1;                            // also covers the empty array
}

void displayResult(int index) {
    if (index == -1) cout << "ID  not registered\n";
    else cout << "Found at index " << index << "\n";
}

int main() {
    int n, target;
    cout << "n: "; cin >> n;
    if (n < 0) { cout << "Invalid size\n";
        return 0; }

    int* arr = inputIDs(n);
    cout << "target: "; cin >> target;
    displayResult(linearSearch(arr, n, target));

    delete[] arr;   // free the memory so there is no leak
    arr = nullptr;
    return 0;
}