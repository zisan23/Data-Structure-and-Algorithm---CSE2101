#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MaxHeap{
public:
    int *arr;
    int size;
    int capacity;
    

    MaxHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }

    int parent(int index){
        return (index - 1) / 2;
    }
    int left_child(int index){
        return (2*index + 1);
    }
    int right_child(int index){
        return (2*index+2);
    }

    void insert(int value){
        if(size == capacity){
            return;
        }

        size++;
        int index = size - 1;
        arr[index] = value;

        while(index != 0 and arr[index] > arr[parent(index)]){
            swap(&arr[index], &arr[parent(index)]);
            index = parent(index);
        }
    }

    void Heapify(int index){
        int l = left_child(index);
        int r = right_child(index);

        int largest = index;

        if(l < size and arr[l] > arr[index]){
            largest = l;
        }
        if(r < size and arr[r] > arr[index]){
            largest = r;
        }

        if(largest != index){
            swap(arr[largest], arr[index]);
            Heapify(largest);
        }
    }

    void increaseKey(int index, int value){
        arr[index] = value;

        int i = index;

        while(i != 0 and arr[parent(i)] < arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    int extractMax(){
        if(size <= 0){
            return INT_MIN;
        }
        if(size == 1){
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size-1];
        size--;

        Heapify(0);
        return root;
    }

    void Delete(int index){
        increaseKey(index, INT_MAX);
        extractMax();
    }
    
    void buildHeap(int a[]){
        for(int i=0; i<capacity; i++){
            arr[i] = a[i];
        }
        for(int i=capacity/2; i>=0; i--){
            Heapify(i);
        }
    }
};

