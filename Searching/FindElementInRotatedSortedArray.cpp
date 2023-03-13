#include <bits/stdc++.h>

using namespace std;


int FindElement(int a[], int N, int target){
    int low = 0;
    int high = N - 1;
    int mid;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(a[mid] == target){
            return mid;
        }

        if(a[low] <= a[mid]){
            if(target <= a[mid] && target >= a[low]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target >= a[mid] && target <= a[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n, t;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> t;
    

    cout << FindElement(a, n, t);
    cout << endl;
    return 0;
}