#include<bits/stdc++.h>
using namespace std;

void BubbleSort_sir(int a[], int n){
    while(true){
        bool flag = false;

        for(int i=0; i<n; i++){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                flag = true;
            }
        }

        if(!flag){
            break;
        }
    }
}

void BubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }

        if(!swapped)
        {
            return;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int a[n], b[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    
    BubbleSort_sir(a, n);
    BubbleSort(b, n);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}