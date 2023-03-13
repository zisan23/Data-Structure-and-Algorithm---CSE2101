#include <bits/stdc++.h>
using namespace std;

void counting_sort_for_radix(int a[], int length, int exponential){
    int temp[length];
    int frequency[10] = {0}; // as total 9 digits are possible

    for(int i=0; i<length; i++){
        frequency[(a[i] / exponential) % 10]++;
    }

    for(int i=1; i<10; i++){
        frequency[i] += frequency[i-1];
    }

    for(int i=length-1; i>=0; i--){
        temp[frequency[(a[i] / exponential) % 10] - 1] = a[i];
        frequency[(a[i] / exponential) % 10]--;
    }

    for(int i=0; i<length; i++){
        a[i] = temp[i];
    }
}

void radix_sort(int a[], int length){
    int max = a[0];

    for(int i=0; i<length; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    //cout << max << endl;

    for(int i=1; max/i > 0; i *= 10){
        counting_sort_for_radix(a, length, i);
    }
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

    radix_sort(a, length);

    for(int i=0; i<length; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}