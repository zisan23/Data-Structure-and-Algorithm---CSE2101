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

int postfix(char* s, int size){
    Stack a;

    int i;

    if(!a.empty()){
        return -1;
    }

    for(i=0; i<size; ++i){
        if(s[i] == ' ') continue;

        else if(isdigit(s[i])){
            int num = 0;

            while(isdigit(s[i])){
                num = num*10 + (int) (s[i] - '0');
                i++;
            }
            i--;

            a.push(num);
        }

        else{
            int val1 = a.peek();
            a.pop();
            int val2 = a.peek();
            a.pop();


            if(s[i] == '+'){
                a.push(val1+val2);
            }
            else if(s[i] == '-'){
                a.push(val2-val1);
            }
            else if(s[i] == '*'){
                a.push(val2*val1);
            }
            else if(s[i] == '/'){
                a.push(val2/val1);
            }

            int x = a.peek();
        }
    }
    return a.peek();
}

int main(){
   
    char s[100];
    char c;
    int size = 0;

    for(int i=0; ; i++){
        c = getchar();

        if(c == '\n') break;
        else{
            s[i] = c;
            size++;
        }
    }
    

    int res = postfix(s, size);
    cout << res << endl;
    
    return 0;
}