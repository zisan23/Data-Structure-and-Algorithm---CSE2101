#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class PriorityQueue{
public:
    int *arr;
    int size;
    int capacity;
    
    int parent(int index){
        return (index - 1) / 2;
    }
    int left_child(int index){
        return (2*index + 1);
    }
    int right_child(int index){
        return (2*index+2);
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

    PriorityQueue(int capacity){
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }
    
    void push(int value){
        if(size == capacity){
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = value;
        
        while(i != 0 and arr[parent(i)] < arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    int pop(){
        if(size == 0){
            return INT_MIN;
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
    
};

