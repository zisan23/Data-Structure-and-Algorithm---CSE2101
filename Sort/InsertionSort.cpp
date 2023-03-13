#include<bits/stdc++.h>
using namespace std;

void Insertion_Sort(int a[], int n){
    for(int i=1; i<n; i++){
        int temp = a[i];

        int j = i;
        bool flag = false;

        while(j > 0 && a[j-1] > temp){
            a[j] = a[j-1];
            j--;
            flag = true;
        }
        if(flag){
            a[j] = temp;
        }
    }
    return;
}