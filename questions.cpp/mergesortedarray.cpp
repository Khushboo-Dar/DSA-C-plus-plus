#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &ans, int k) {
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
}

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n) {
   // vector<int> ans;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            arr1.push_back(arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            arr1.push_back(arr2[j]);
            j++;
        } else {
            // Handle the case when arr1[i] is equal to arr2[j]
            arr1.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Append the remaining elements from arr1 (if any)
    while (i < m) {
        arr1.push_back(arr1[i]);
        i++;
    }

    // Append the remaining elements from arr2 (if any)
    while (j < n) {
        arr1.push_back(arr2[j]);
        j++;
    }

    // Copy the merged result back to arr1
    //arr1 = ans;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6};
    merge(arr1, 5, arr2, 3);

    // The second argument to the print function should be the size of arr1
    print(arr1, arr1.size());

    return 0;
}
