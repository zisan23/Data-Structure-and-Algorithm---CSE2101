#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[], int length){
    
    int max = a[0];
    int min = a[0];

    for(int i=0; i<length; i++){
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }

    if(min > 0){
        
        int frequency[max+1] = {0};

        for(int i=0; i<length; i++){
            frequency[a[i]]++;
        }

        for(int i=1; i<=max; i++){
            frequency[i] += frequency[i-1];
        }

        int temp[length] = {0};

        for(int i=length-1; i>=0; i--){
            temp[--frequency[a[i]]] = a[i];
        }

        for(int i=0; i<length; i++){
            a[i] = temp[i];
        }
    }
    else if(min<=0){
        int frequency[max-min+1] = {0};
        for (int i = 0; i < length; i++)
        {
            frequency[a[i] - min]++;
        }
        int k = 0;
        for (int i = 0; i <= max - (min); ++i)
        {
            for (int j = 1; j <= frequency[i]; ++j)
            {
                a[k++] = i + (min);
            }
        }
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

    counting_sort(a, length);

    for(int i=0; i<length; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}