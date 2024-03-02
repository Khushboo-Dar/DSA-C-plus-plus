#include<iostream>
using namespace std;

int first(int arr[], int s, int e, int k) {
    if (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == k && (mid == 0 || arr[mid - 1] != k)) {
            return mid;  // Found the first occurrence
        } else if (arr[mid] < k) {
            return first(arr, mid + 1, e, k);
        } else {
            return first(arr, s, mid - 1, k);
        }
    }

    return -1;  // Element not found
}

int last(int arr[], int s, int e, int k, int n) {
    if (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == k && (mid == n - 1 || arr[mid + 1] != k)) {
            return mid;  // Found the last occurrence
        } else if (arr[mid] > k) {
            return last(arr, s, mid - 1, k, n);
        } else {
            return last(arr, mid + 1, e, k, n);
        }
    }

    return -1;  // Element not found
}

int main() {
    int arr[6] = {1, 2, 3, 4, 3, 5};
    int n = 6;
    int k = 3;

    int firstOccurrence = first(arr, 0, n - 1, k);
    int lastOccurrence = last(arr, 0, n - 1, k, n);

    if (firstOccurrence != -1 && lastOccurrence != -1) {
        cout << "First occurrence: " << firstOccurrence << endl;
        cout << "Last occurrence: " << lastOccurrence << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
