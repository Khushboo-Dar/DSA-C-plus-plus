#include <iostream>
#include <vector>

using namespace std;

int totalOccurrences(vector<int>& arr, int target) {
    int count = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3, 3, 3, 4};
    int target = 3;

    int totalOccurrence = totalOccurrences(arr, target);

    cout << "Total occurrences of " << target << " in the array: " << totalOccurrence << endl;

    return 0;
}
