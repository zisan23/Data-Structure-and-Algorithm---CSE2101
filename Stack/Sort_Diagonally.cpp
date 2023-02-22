#include <bits/stdc++.h>
using namespace std;

int main(){
    int row, column;
    cin >> row >> column;

    int array[row][column];

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin >> array[i][j];
        }
    }

    int st = row - 1;
    int ed = 0;

    while(st>=0 and ed < column){
        if(st == 0 and ed ==column -1){
            break;
        }
        else if(st<=row-1 and ed<column and st!=0){
            st--;
            ed = 0;
        }
        else if(st==0 and ed <column-1){
            ed++;
            st == 0;
        }

        int i = st, j = ed;

        vector <int> v;

        while(i<row and j<column){
            int x = array[i][j];
            v.push_back(x);
            i++;
            j++;
        }
        sort(v.begin(), v.end());

        int i = st, j = ed;

        int v_index = 0;

        while(i<row and j<column){
            array[i][j] = v[v_index++];
            i++;
            j++;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(j == 0){
                cout << array[i][j];
            }
            else{
                cout << " " << array[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}