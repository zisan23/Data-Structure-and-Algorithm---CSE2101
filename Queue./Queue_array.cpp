#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int capacity;
        int size;
        int* array;
        int root, last;
    
    public:

    Queue(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->root = 0;
        this->last = -1;
        this->array = new int[this->capacity];
    }

    void enque(int data){
        if(size == capacity){
            return;
        }

        last = (last+1)%capacity; // This is done to increment the starting position -1 to 0 and check for capacity
        array[last] = data;
        size++;
    }

    void deque(){
        if(size == 0){
            return;
        }

        root = (root+1)%capacity;
        size--;
        if(size == 0){
            root = 0;
            last = -1;
        }
    }

    void deque2(){
        if(root == last){
            return;
        }

        for(int i=0; i<last; i++){
            array[i] = array[i+1];
        }

        last--;
        size--;
    }

    int peek_last(){
        if(size == 0){
            return -1;
        }

        return array[last];
    }
    int peek_front(){
        if(size == 0){
            return -1;
        }

        return array[root];
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(size == capacity){
            return true;
        }
        else{
            return false;
        }
    }

    void display(){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }

        for(int i=root; i<=last; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    
};

int main(){
    Queue q = Queue(10);

    q.enque(11);
    q.enque(12);
    q.enque(10);
    q.enque(12);
    q.enque(15);
    q.enque(17);

    q.display();

    q.deque2();
    q.display();

    q.deque2();
    q.display();
    q.deque2();
    q.display();

    bool x = q.isEmpty();
    cout << x << endl;
    
    x = q.isFull();
    cout << x << endl;

    cout << q.peek_front() << endl;
    cout << q.peek_last() << endl;

    return 0;


}