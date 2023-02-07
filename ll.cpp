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

class single_ll
{
public:
    node *head = NULL;

    void insertAtFront(int data)
    {
        node *new_node = new node(data); // Take input data in a new node using constructor
        new_node->next = head;
        head = new_node;
    }

    void insertAtBack(int data)
    {
        node *new_node = new node(data); // taking the data by constructor

        node *last = head;

        if (last == NULL)
        {
            head = new_node; // if no element exists in linked list, then insert the value in the first head and return
            return;
        }

        while (last->next != NULL)// break when the node after last is NULL
        {                      
            last = last->next; // traverse through the list till the last node comes
        }

        last->next = new_node; // assign the data in the next node of the last
    }

    void insertAtMiddle(int data, int position)// take the value and where to put it in
    {

        node *new_node = new node(data); 

        node *current = head;

        for (int i = 0; i < position - 1; i++) //traverse through the array till before the position to ensure that the position exists
        {
            current = current->next; 

            if (current == NULL)
            {
                return;
            }
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void deleteFromBegin()
    {
        if (head == NULL)
        {
            return;
        }
        node *i = head;
        head = i->next;
        free(i);
    }

    void deleteFromBack()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        node* current = head;
        node* prev = NULL;
        

        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;
        free(current);
    }

    void deleteFromMiddle(int position)
    {
        node *current = head;
        if (head == NULL)
        {
            return;
        }
        if (position == 0)
        {
            head = current->next;
            free(current);
            return;
        }

        for (int i = 0; i < position-1; i++)
        {
            current = current->next;
        }
        if(current == NULL || current->next == NULL){
            return;
        }
        node* temp = current->next->next;
        free(current->next);
        current->next = temp;
        return;
    }

    bool search(int x)
    {
        node *i = head;

        while (i != NULL)
        {
            if (i->data == x)
            {
                return true;
            }
            i = i->next;
        }

        return false;
    }

    void print()
    {
        node *i = head;

        if (i == NULL)
        {
            cout << "Empty" << endl;
            return;
        }

        while (i != NULL)
        {
            cout << i->data << " ";
            i = i->next;
        }
        cout << endl;
    }
};

int main()
{
    single_ll a;

    a.insertAtFront(5);
    a.print();
    a.insertAtFront(6);
    a.print();
    a.insertAtFront(7);
    a.print();
    a.insertAtFront(8);
    a.print();
    a.insertAtBack(11);
    a.print();
    a.insertAtBack(12);
    a.print();
    a.insertAtBack(13);

    a.print();

    a.insertAtMiddle(77, 3);
    a.insertAtMiddle(44, 6);

    a.print();

    a.deleteFromBegin();

    a.print();

    a.deleteFromBack();

    a.print();

    a.deleteFromMiddle(3);

    a.print();

    bool x = a.search(12);
    cout << x << endl;
}