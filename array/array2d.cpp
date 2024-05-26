#include<iostream>
using namespace std;

void printmatrix(int arr[][3], int row, int col) {
    cout << "Enter the matrix:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {  
            cin >> arr[i][j];
        }
    }
}

bool ispresent(int arr[][3], int target, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] == target) {
                cout << "Target is present at position (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Target not present" << endl;
    return false;
}

void rowsum(int arr[][3], int row, int col) {
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of elements in row " << i << ": " << sum << endl;
    }
}

int largestrowsum(int arr[][3], int row, int col) {
    int maxSum = INT_MIN;
    int rowIndex = -1;
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        if(sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }
    cout << "Row with the largest sum: " << rowIndex << endl;
    return rowIndex;
}

int main() { 
    int arr[3][3];
    printmatrix(arr, 3, 3);
    ispresent(arr, 4, 3, 3);
    rowsum(arr, 3, 3);
    largestrowsum(arr, 3, 3);

    return 0;
}
