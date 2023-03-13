#include <bits/stdc++.h>

using namespace std;

int MinElement(int a[], int N){

    if(a[0] < a[N-1]){
        return a[0];
    }

    int low = 0, high = N-1;
    int mid;

    while(high-low > 1){
        mid = low + (high - low) / 2;

        if(a[low] < a[mid]){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    return min(a[low], a[high]);
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << MinElement(a, n) << endl;

    return 0;
}