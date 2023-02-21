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

class Stack
{
private:
    int size = 0;

public:
    node *top = NULL;
    void push(int value)
    {
        node *new_node = new node(value);
        new_node->next = top;
        top = new_node;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            printf("Empty Stack!!!");
            return;
        }

        node *temp = top;
        top = top->next;
        free(temp);
        size--;
    }

    auto peek()
    {
        return top->data;
    }

    bool empty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Size()
    {
        return size;
    }

    void clear()
    {
        node *temp = top;
        top = NULL;

        while (temp != NULL)
        {
            // pop();
            node *temp2 = temp;
            temp = temp2->next;
            free(temp2);
        }
        size = 0;
    }

    bool search(int value)
    {
        node *temp = top;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int Search(int value)
    {
        node *temp = top;
        int count = 0;
        int flag = 0;

        while (temp != NULL)
        {
            count++;
            if (temp->data == value)
            {
                flag = 1;
                return count;
            }
            temp = temp->next;
        }
        if (flag == 0)
        {
            return -1;
        }
    }

    void display()
    {
        node *temp = top;

        if (temp == NULL)
        {
            cout << "Empty Stack" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void paranthesis(string s)
{
    Stack a;
    int i=0;

    while(s[i] != '\n' && s[i] != '\0'){
        if (s[i] == ']' && a.peek() == '[')
			a.pop();
		else if (s[i] == '}' && a.peek() == '{')
			a.pop();
		else if (s[i] == ')' && a.peek() == '(')
			a.pop();
		else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			a.push(s[i]);

        i++;
    }

    if(a.empty()){
        cout << "Balanced" << endl;
        return;
    }
    else{
        cout << "Unbalanced" << endl;
        return;
    }
}

int main()
{
    string s;
    cin >> s;

    paranthesis(s);

    return 0;
}