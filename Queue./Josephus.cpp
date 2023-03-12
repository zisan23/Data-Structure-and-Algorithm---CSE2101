#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
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
            root->prev = NULL;
            last = root;
            size++;
            return;
        }

        last->next = new_node;
        new_node->prev = last;
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
            last->prev = NULL;
            last = NULL;
            root = NULL;
        }

        if(root != NULL){
            root->prev = NULL;
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
        if(root == NULL){
            return 0;
        }
        node* cur = root;
        int s = 0;

        while(cur != NULL){
            s++;
            cur = cur->next;
        }

        return s;

    }

    int size_2(){
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

    void remove(int k){
        if(k > size - 1){
            return;
        }

        if(size == 0 || root == NULL){
            return;
        }

        if(k == 0){
            node* temp = root;
            root = root->next;
            free(temp);

            if(root != NULL){
                root->prev = NULL;
            }
            size--;

            if(size == 0){
                root = last = 0;
            }
            return;
        }

        if(k == size-1){
            node* temp = last;
            last = last->prev;

            free(temp);

            if(last != NULL){
                last->next = NULL;
            }
            size--;

            if(size == 0){
                root = last = NULL;
            }

            return;
        }

        int i=1; 
        node* current = root->next;

        while(current != last){
            if(i==k){
                node* prev_node = current->prev;
                node* next_node = current->next;

                prev_node->next = next_node;
                next_node->prev = prev_node;

                free(current);

                size--;

                if(size == 0){
                    root = last = 0;
                }

                return;
            }

            current = current->next;
            i++;
        }
    }

    int josephus_problem(Queue_ll q, int k){
        int i=0;
        while(q.size_2() != 1){
            i = (i+k) % q.size_2();
            q.remove(i);
        }

        return q.peek_front();
    }
};

int main(){
    int total, k;

    cin >> total >> k;

    Queue_ll q;

    for(int i=1; i<=total; i++){
        q.enque(i);
    }

    k--; //index start from 0

    cout << q.josephus_problem(q, k) << endl;

    return 0;
}
