#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class Stack{
private:
    int size = 0;
public:
    node *top = NULL;
    void push(int value){
        node *new_node = new node(value);
        new_node->next = top;
        top = new_node;
        size++;
    }

    void pop(){
        if(top == NULL){
            printf("Empty Stack!!!");
            return;
        }

        node *temp = top;
        top = top->next;
        free(temp);
        size--;
    }

    int peek(){
        return top->data;
    }

    bool empty(){
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int Size(){
        return size;
    }

    void clear(){
        node *temp = top;
        top = NULL;

        while(temp != NULL){
            //pop();
            node *temp2 = temp;
            temp = temp2->next;
            free(temp2);
        }
        size = 0;
    }

    bool search(int value){
        node *temp = top;

        while(temp != NULL){
            if(temp->data == value){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int Search(int value){
        node *temp = top;
        int count = 0;
        int flag = 0;

        while(temp != NULL){
            count++;
            if(temp->data == value){
                flag = 1;
                return count;
            }
            temp = temp->next;
        }
        if(flag == 0){
            return -1;
        }
    }

    void display(){
        node *temp = top;

        if(temp == NULL){
            cout << "Empty Stack" << endl;
            return;
        }

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack a;
    int top_element;


    a.push(5);
    a.push(6);
    a.push(100);
    a.push(32);
    a.push(11);

    a.pop();

    top_element = a.peek();

    cout <<  top_element << endl;

    a.display();

    bool x = a.empty();
    cout << x << endl;

    int d = a.Size();
    cout << d << endl;

    bool q = a.search(7);
    bool p = a.search(32);

    cout << q << " " << p << endl;

    int qw = a.Search(32);
    int er = a.Search(12);
    int ty = a.Search(6);

    cout << qw << " " << er << " " << ty << endl;

    a.clear();
    a.display();

    return 0;
}