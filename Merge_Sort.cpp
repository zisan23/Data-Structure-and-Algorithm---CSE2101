#include <bits/stdc++.h>
using namespace std;

int array_length(int a[]){
    int i=0;
    while(a[i]){
        i++;
    }
    return i;
}

void merge(int a[], int start, int end, int mid){

    int left_array_size = mid - start + 1;
    int right_array_size = end - mid;

    int left_array[left_array_size], right_array[right_array_size];

    for(int k=0; k<left_array_size; k++){
        left_array[k] = a[start + k];
    }

    for(int k=0; k<right_array_size; k++){
        right_array[k] = a[mid + 1 + k];
    }

    int i = 0, j = 0, count = start;

    while(i<left_array_size && j <right_array_size){
        if(left_array[i] <= right_array[j]){
            a[count] = left_array[i];
            i++;
            count++;
        }
        else{
            a[count] = right_array[j];
            j++;
            count++;
        }
    }

    while(i<left_array_size){
        a[count] = left_array[i];
        i++;
        count++;
    }

    while(j<right_array_size){
        a[count] = right_array[j];
        j++;
        count++;
    }
}

void merge_sort(int a[], int start, int end){
    
    if(start < end){
        int mid = start + (end - start) / 2;

        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        merge(a, start, end, mid);
    }
}

int main(){
    int len;
    cin >> len;

    int array[len];

    for(int i=0; i<len; i++){
        cin >> array[i];
    }

    merge_sort(array, 0, len-1);

    for(int i=0; i<len; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}