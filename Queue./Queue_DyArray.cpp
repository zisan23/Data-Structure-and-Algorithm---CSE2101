#include <bits/stdc++.h>
using namespace std;

class Dyn_Queue{
    private:
        int root, last, size;
        int capacity = 5;
        int* array;

    public:
        Dyn_Queue(){
            this->root = 0;
            this->last = -1;
            this->size = 0;
            this->array = new int[this->capacity];
        }

        void enque(int data){
            if(size == capacity){
                int* temp = array;

                array = new int[capacity+5];

                for(int i=0; i<capacity; i++){
                    array[i] = temp[i];
                }

                capacity += 5;
            }

            last = (last+1)%capacity;
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

        int peek_front(){
            return array[root];
        }

        int peek_last(){
            return array[last];
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
            if(size == 0) return;
            for(int i=root; i<=last; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Dyn_Queue q = Dyn_Queue();

    q.enque(11);
    q.enque(18);
    q.enque(10);
    q.enque(12);
    q.enque(15);
    q.enque(17);

    q.display();

    q.deque(); q.display();
    q.deque(); q.display();
    q.deque(); q.display();
    q.deque(); q.display();

    cout << q.peek_front() << " " << q.peek_last() << endl;

    return 0;
}