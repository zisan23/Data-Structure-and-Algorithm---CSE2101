#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue_ll{
    node* root = NULL;
    node* last = NULL;
    int size = 0;

public:

    void enque(int data){

        node *new_node = new node(data);

        if(root == NULL){
            root = new_node;
            root->next = NULL;
            last = root;
            size++;
            return;
        }

        last->next = new_node;
        new_node->next = NULL;
        last = new_node;
        size++;
        return;
    }   

    void deque(){
        if(root == NULL){
            return;
        }

        node *temp = root;
        root = root->next;

        if(root == NULL){
            last->next = NULL;
            last = NULL;
            root = NULL;
        }

        free(temp);
        size--;
    }

    int peek_front(){
        if(last == NULL){
            return -1;
        }

        return root->data;
    }

    int peek_last(){
        if(last == NULL){
            return -1;
        }

        return last->data;
    }

    bool isEmpty(){
        return !root;
    }

    int Size(){
        return size;

    }

    void display(){
        if(root == NULL){
            return;
        }

        node* temp = root;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

class Stack{
    Queue_ll q1, q2;

public:
    void push(int value){
        q2.enque(value);

        while(!q1.isEmpty()){
            q2.enque(q1.peek_front());
            q1.deque();
        }

        Queue_ll q3 = q1;
        q1 = q2;
        q2 = q3;
    }

    void pop(){
        if(q1.isEmpty()){
            return;
        }
        q1.deque();
    }

    int peek(){
        if(q1.isEmpty()){
            return -1;
        }
        return q1.peek_front();
    }

    int SIZE(){
        return q1.Size();
    }

    void display(){
        q1.display();
    }
};

int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(4);
    s.push(3);

    cout << s.peek() << endl;

    s.display();

    cout << s.SIZE() << endl;

    s.pop();
    s.display();
    s.pop();
    s.display();
    return 0;
}