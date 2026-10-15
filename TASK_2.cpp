#include <iostream>
using namespace std;

// makes the array on the heap,  must delete it AT END
int* inputSortedIDs(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    return arr;
}

// binary search only works if the data is already sorted
bool isSorted(int* arr, int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1]) return false;   // found something out of order
    return true;
}

int binarySearch(int* arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;       // middle without overflow
        if (arr[mid] == target) return mid;     // got it
        if (target < arr[mid]) high = mid - 1;  // target is smaller, drop the right half
        else low = mid + 1;                     // target is bigger, drop the left half
    }
    return -1;                                  // range is empty, not found
}

int main() {
    int n, target;
    cout << "n: "; cin >> n;
    if (n < 0) { cout << "Invalid size\n"; return 0; }

    int* arr = inputSortedIDs(n);

    if (!isSorted(arr, n)) {
        cout << "Array is not sorted\n";
        delete[] arr;                           // free before leaving early
        return 0;
    }

    cout << "target: "; cin >> target;
    int idx = binarySearch(arr, 0, n - 1, target);
    if (idx == -1) cout << "Not found\n";
    else cout << "Found at index " << idx << "\n";

    delete[] arr;                               // give the memory back
    arr = nullptr;
    return 0;
}