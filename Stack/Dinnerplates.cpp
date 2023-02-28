#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top = -1;
    int size = 10;

public:
    int *ptr = (int *)calloc(size, sizeof(int));

    void push(int value)
    {
        if (top == size - 1)
        {
            ptr = (int *)realloc(ptr, size += 10);

            if (ptr == NULL)
            {
                cout << "Memory not allocated" << endl;
                return;
            }
        }

        ptr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Under Flow!!!" << endl;
            return;
        }

        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Empty Stack!!!" << endl;
            return -1;
        }

        return ptr[top];
    }

    bool empty()
    {
        return (top == -1) ? true : false;
    }

    int Size()
    {
        return top + 1;
    }

    // void clear(){

    //     while(top != -1){
    //         free(ptr + top*sizeof(int));
    //         top--;
    //     }
    //     cout<<"memory freed"<<endl;

    // }

    void clear()
    {

        while (top != -1)
        {
            free(ptr);
            top--;
        }
    }

    int search(int value)
    {
        int temp = 0;

        for (int i = top; i != -1; i--)
        {
            if (ptr[i] == value)
            {
                return temp;
            }
            temp++;
        }

        return -1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
            return;
        }

        for (int i = top; i != -1; i--)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

class DinnerPlate
{
public:

    int top  = 0;
    int track = 0;
    int capacity;

    DinnerPlate(int capacity){
        this->capacity = capacity;
    }

    Stack a[1000];


    void push(int value){
        while(a[top].Size() == capacity){
            top++;
            track++;
        }

        a[top].push(value);
    }

    int pop(){
        if(top == -1){
            return -1;
        }

        top = track;

        while(a[top].Size() == 0){
            top--;

            if(top == -1){
                return -1;
            }
        }

        int pop_value = a[top].peek();
        a[top].pop();
        return pop_value;
    }

    int popAtStack(int index){
        if(a[index].Size() == 0){
            return -1;
        }

       int pop_value = a[index].peek();
       a[index].pop();
       top = index;
       return pop_value;
    }

    void display(){
        int i=0;

        while(i!=track){

            if(a[i].Size()==0){
                i++;
                cout<<endl;
            }

            if(i==-1)return;

            cout<<a[i].peek()<<" ";
            a[i].pop();
        }
    }
};

int main()
{
    DinnerPlate D = DinnerPlate(2);

    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);

    // D.display();

    cout << D.popAtStack(0) << endl;
    // D.display();

    D.push(20);
    D.push(21);

    // D.display();

    cout << D.popAtStack(0) << endl;
    // D.display();
    cout << D.popAtStack(2) << endl;
    //    D.display();
    cout << D.pop() << endl;
    cout << D.pop() << endl;
    cout << D.pop() << endl;
    cout << D.pop() << endl;
    cout << D.pop() << endl;
    return 0;
}