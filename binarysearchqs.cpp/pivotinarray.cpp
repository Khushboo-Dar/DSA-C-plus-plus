/*pivot element*/
#include<iostream>
using namespace std;

void pivot(int arr[], int n) {
    int i = 0;
    int sum = 0;

    // Calculate the sum of the elements on the left side
    while (arr[i] < arr[i + 1]) {
        sum = sum + arr[i];
        i++;
    }

    //cout << "sum=" << sum << endl;

    int dummypivot = arr[i];
    
    //cout << "dummy pivot=" << dummypivot << endl;

    cout << "i=" << i << endl;
    i++;

    int sum2 = 0;
    //cout << "i=" << i << endl;
    
    // Calculate the sum of the elements on the right side
    while (i < n) {
        sum2 = sum2 + arr[i];
        if(i+1==n)
        {
            break;
        }
        else{
            i++;
        }
    }

   // cout << "arr[i]=" << arr[i-1] << endl; // Use i-1 instead of i to avoid accessing out of bounds
    //cout << "sum2=" << sum2 << endl;
    //cout << "sum=" << sum << endl;

    // Compare the sums and determine if there is a pivot
    if (sum2 == sum) {
        int pivot= dummypivot;
            //cout << "dummy pivot" << dummypivot << endl;
   // cout << "pivot= " << pivot;
     // Indicate no pivot found
        }  
}

int main() {
    int arr[7] = {1, 2, 3, 7, 3 , 2 ,1};
    pivot(arr, 7);
    return 0;
}
