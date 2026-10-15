#include <iostream>
#include <vector>
using namespace std;
// joins two sorted halves [left TO mid] and [mid+1 TO right]
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);  // <= keeps it stable
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);    // leftovers from left half
    while (j <= right) temp.push_back(arr[j++]);  // leftovers from right half
    for (int k = 0; k < (int)temp.size(); k++)
        arr[left + k] = temp[k];                  // copy back
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;          // 0 or 1 element, already sorted
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void displayArray(const vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "n: "; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Before sorting "; displayArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "After sorting  "; displayArray(arr, n);
    return 0;
}