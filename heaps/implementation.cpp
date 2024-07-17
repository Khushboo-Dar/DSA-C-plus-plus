#include <iostream>
using namespace std;

class heap
{
public:
    int size;
    int arr[100];
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void delete_from_heap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        // 1. Replace the first element with the last element
        arr[1] = arr[size];
        // 2. Remove the last element
        size--;
        // 3. Take root to its correct position
        int i = 1;
        while (i <= size)
        {
            int leftind = 2 * i;
            int rightind = 2 * i + 1;
            int largest = i;

            if (leftind <= size && arr[largest] < arr[leftind])
            {
                largest = leftind;
            }

            if (rightind <= size && arr[largest] < arr[rightind])
            {
                largest = rightind;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

    // heapify //max heap
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <=n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right])
        {
            largest = right;
        }
        if (largest != i) // largest has come to its right position
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest); // process remaining tree
        }
    }
   /* MIN HEAPIFY
    
    #include <bits/stdc++.h> 
void heapify(vector<int> &arr, int n, int i)
    {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[smallest] > arr[left])
        {
            smallest = left;
        }
        if (right < n && arr[smallest] > arr[right])
        {
            smallest = right;
        }
        if (smallest != i) // smallestt has come to its right position
        {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest); // process remaining tree
        }
    }
vector<int> buildMinHeap(vector<int> &arr)
{ int n=arr.size();
    for (int i = n/2 -1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}
*/


//heap sort

 void heapSort()
    {
        int n = size;
        while (n > 1)
        {
            //1. swap
            swap(arr[1], arr[n]);
            n--;
            //2. heapify
            heapify(arr,n,1);
        }
    }

};

int main()
{
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.delete_from_heap();
    // h.print();

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5;
    // //heap create
    // for (int i = n / 2; i > 0; i--)
    // {
    //     h.heapify(arr, n, i);
    // }

    // cout << "print after heapify" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // //heap sort
    // h.heapSort(arr,n);

    // cout << "print after heap sort" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
 heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.heapSort();
    h.print();

    return 0;
}
