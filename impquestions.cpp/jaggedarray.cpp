#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    vector<int> ans;
    cout << "Enter n: ";
    cin >> n;

    // Loop to take input for each row
    for (int i = 0; i < n; i++) {
        int col;
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> col;

        // Create a dynamic array for each row
        int *arr = new int[col];

        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < col; j++) {
            if(j>0)
            {
                cout<<endl;
            }
            cin >> arr[j];

            // Store the elements in the vector
            ans.push_back(arr[j]);


        }

        // Free the memory allocated for the dynamic array
        delete[] arr;
    }

    cout << "Elements stored in the vector: ";
    for (int i : ans) {
        cout << i << " ";
    }

    // Ensure to free the memory allocated for the dynamic array
    // This is important to prevent memory leaks
    ans.clear();

    return 0;
}
