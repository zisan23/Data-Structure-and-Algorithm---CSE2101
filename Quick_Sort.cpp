/*
The key process in quickSort is a partition(). The target of partitions is, given an array and an
element x of an array as the pivot, put x at its correct position in a sorted array and put all smaller
elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this
should be done in linear time.

Time Complexity: O(nlogn)(on average)
Space Complexity:O(log(n))

Quick Sort Algorithm: https://www.geeksforgeeks.org/quick-sort/

comparison between hoares & lomuto:  https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/

*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high){
    int pivot = a[high];

    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i+1], &a[high]);
    return i+1;
}

void quick_sort(int a[], int low, int high){
    if(low < high){
        int partition_index = partition(a, low, high);

        quick_sort(a, low, partition_index - 1);
        quick_sort(a, partition_index + 1, high);
    }
}

int main(){
    int len;
    cin >> len;

    int array[len];

    for(int i=0; i<len; i++){
        cin >> array[i];
    }

    quick_sort(array, 0, len-1);

    for(int i=0; i<len; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}