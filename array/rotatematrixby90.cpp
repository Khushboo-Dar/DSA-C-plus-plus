#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i + 1; j < matrix.size(); j++) {  // Transpose only the upper triangle
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseRows(vector<vector<int>> &matrix) {
    for (auto& row : matrix) {
        reverse(row.begin(), row.end());
    }
}

int main() {
    vector<vector<int>> arr(3, vector<int>(3));  // Example 3x3 matrix

    // Input elements into the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Original matrix: " << endl;
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Perform rotation
    rotate(arr);
    reverseRows(arr);

    cout << "Rotated matrix: " << endl;
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
