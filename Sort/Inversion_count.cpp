/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
If the array is already sorted, then the inversion count is 0,but if the array
is sorted in reverse order, the inversion count is the maximum. 
{
    Total inversion count = The number of inversions in the left half and right half of the array 
                            + The inversions that need to be counted during the merge step

}

geeksforgeeks concept = https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/
leetcode tutorial :
1) https://leetcode.com/problems/global-and-local-inversions/solutions/242101/Count-inversions/
2) https://leetcode.com/problems/count-of-smaller-numbers-after-self/solutions/609137/merge-sort-with-counting-inversions-simple-c-solution/

*/

#include <bits/stdc++.h>
using namespace std;

int inversion_count_in_merge(int a[], int start, int end, int mid){

    int left_array_size = mid - start + 1;
    int right_array_size = end - mid;

    int left_array[left_array_size], right_array[right_array_size];

    for(int i=0; i<left_array_size; i++){
        left_array[i] = a[start + i];
    }

    for(int i=0; i<right_array_size; i++){
        right_array[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    int inversion_count_for_merge = 0;

    while(i < left_array_size && j < right_array_size){
        if(left_array[i] < right_array[j]){
            a[k] = left_array[i];
            i++;
            k++;
        }
        else{
            a[k] = right_array[j];
            j++;
            k++;

            inversion_count_for_merge += left_array_size - i;
        }
    }

    while(i<left_array_size){
        a[k] = left_array[i];
        i++;
        k++;
    }

    while(j<right_array_size){
        a[k] = right_array[j];
        j++;
        k++;
    }

    return inversion_count_for_merge;
}

int merge_sort(int a[], int start, int end){
    
    int inversion_count = 0;

    if(start < end){

        int mid = start + (end - start) / 2;

        inversion_count += merge_sort(a, start, mid);
        inversion_count += merge_sort(a, mid+1, end);
        
        inversion_count += inversion_count_in_merge(a, start, end, mid);
    }

    return inversion_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    cin >> length;

    int a[length];

    for(int i=0; i<length; i++){
        cin >> a[i];
    }

    int inversion_count = merge_sort(a, 0, length - 1);

    for(int i=0; i<length; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Inversion Count: " << inversion_count << endl;

    return 0;
}