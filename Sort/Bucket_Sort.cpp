#include <bits/stdc++.h>
using namespace std;

// void insertion_sort(vector<double> &a, int length){
//     for(int i=1; i<length; i++){
//         double temp = a[i];
//         int j = i-1;
//         int check = 0;
//         while(j>=0 && a[j-1] > temp){
//             a[j] = a[j-1];
//             j--;
//             check = 1;
//         }
//         if(check == 1)a[j] = temp;
//     }
// }

// void insertion_sort(vector<double>& vec)
// {
//     for(size_t j = 1; j < vec.size(); j++)
//     {
//       double key = vec[j];
//       int i = j-1;

//       while(i >= 0 && vec[i] > key)
//       {
//         vec[i+1] = vec[i];
//         i--;
//       }
//       vec[i+1] = key;
//     }
// }

void bucket_sort(double arr[], int n)
{
    vector<double> b[n];

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    cin >> length;

    double a[length];

    double max = a[0];
    double min = a[0];

    for(int i=0; i<length; i++){
        cin >> a[i];

        if(a[i] > max) max = a[i];
        
        if(a[i] < min) min = a[i];
    }

    int bucket_number = 10;

    bucket_sort(a, length);

    for(int i=0; i<length; i++){
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}