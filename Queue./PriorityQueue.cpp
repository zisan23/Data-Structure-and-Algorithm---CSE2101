#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int priority;
    node *next;

    node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        next = NULL;
    }
};

class Priority_Queue
{
private:

    node* front;
    int size;

public:

    Priority_Queue(){
        front  = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    void enque(int data, int priority){
        node* new_node = new node(data, priority);

        if(front = NULL){
            front = new_node;
        }
        else if(front->priority < priority){
            new_node->next = front;
            front = new_node;
        }
        else{
            node* temp = front;

            while(temp->next != NULL && temp->next->priority >= priority){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }

        size++;
    }

    void deque(){
        if(size == 0){
            return;
        }
        node* temp = front;
        front = temp->next;
        free(temp);
        size--;
    }

    int peek(){
        return front->data;
    }

    void display(){
        node* temp = front;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
