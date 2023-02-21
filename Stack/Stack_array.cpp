#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    int top = -1;
    int size = 10;
public:
    int *ptr = (int*)calloc(size, sizeof(int));

    void push(int value){
        if(top == size - 1){
            ptr = (int*) realloc(ptr, size+=10);

            if(ptr == NULL){
                cout << "Memory not allocated" << endl;
                return;
            }
        }
        
        ptr[++top] = value;
    }

    void pop(){
        if(top == -1){
            cout << "Under Flow!!!" << endl;
            return;
        }

        top--;
    }

    void peek(){
        if(top == -1){
            cout << "Empty Stack!!!" << endl;
            return ;
        }

        cout << ptr[top] << endl;
    }

    bool empty(){
        return (top == -1) ? true : false;
    }

    int Size(){
        return top+1;
    }

    // void clear(){

        
    //     while(top != -1){
    //         free(ptr + top*sizeof(int));
    //         top--;
    //     }
    //     cout<<"memory freed"<<endl;

    // }

    void clear(){

        while(top != -1){
            free(ptr);
            top--;
        }
    }

    int search(int value){
        int temp = 0;

        for(int i=top; i!=-1; i--){
            if(ptr[i] == value){
                return temp;
            }
            temp++;
        }

        return -1;
    }

    void display(){
        if(top == -1){
            cout << "Empty Stack"  << endl;
            return;
        }

        for(int i=top; i!=-1; i--){
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack a;

    a.push(11);
    a.push(12);
    a.push(78);
    a.push(23);
    a.push(35);

    a.display();

    a.pop();
    a.display();

    a.peek();

    cout << a.empty() << endl;

    cout << a.Size() << endl;

    a.clear();
    a.display();

    return 0;
}