#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a  =*b;
    *b = temp;
}

//array start from 0 index

class MinHeap{

public:
    int* arr;
    int capacity;
    int size;

    MinHeap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int left(int index){
        return (2*index+1);
    }
    int right(int index){
        return (2*index+2);
    }
    int parent(int index){
        return (index-1)/2;
    }

    void insert(int value){

        if(size == capacity){
            return;
        }

        size++;
        int index = size - 1;

        arr[index] = value;

        while(index != 0 and arr[index] < arr[parent(index)]){
            swap(&arr[index], & arr[parent(index)]);
            index = parent(index);
        }
    }

    void Heapify(int index){
        int l = left(index);
        int r = right(index);

        int smallest = index;

        if(l < size and arr[l] < arr[index]){
            smallest = l;
        }
        if(r < size and arr[r] < arr[index]){
            smallest = r;
        }

        if(smallest != index){
            swap(&arr[index], &arr[smallest]);
            Heapify(smallest);
        }
    }

    void decreaseKey(int index, int value){
        arr[index] = value;
        int i = index;
        while(i != 0 and arr[i] < arr[parent(i)]){
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin(){
        if(size <= 0){
            return INT_MAX;
        }
        if(size == 1){
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);

        return root;
    }

    void Delete(int index){
        decreaseKey(index, INT_MIN);
        extractMin();
    }
};