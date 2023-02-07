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

class circle_ll
{
public:
    node *head = NULL;

    void insert_front(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
            head->next = head;
            return;
        }

        node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void insert_back(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        node *current = head;

        while (current->next != head)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = head;
    }

    void insert_middle(int data, int position)
    {
        node *new_node = new node(data);

        node *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;

            if (current->next == head)
            {
                return;
            }
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void remove_front()
    {
        node *current = head;

        while (current->next != head)
        {
            current = current->next;
        }

        current->next = head->next;

        current = head;
        head = current->next;
        free(current);
    }

    void remove_back()
    {
        node *current = head;

        while (current->next->next != head)
        {
            current = current->next;
        }

        node *last = current->next;
        current->next = head;
        free(last);
    }

    void remove_middle(int position)
    {
        node *current = head;

        if (head == NULL)
        {
            return;
        }

        if (position == 0)
        {
            if (head->next == head)
            {
                free(head);
                return;
            }

            while (current->next != head)
            {
                current = current->next;
            }
            current->next = head->next;
            free(head);
            head = current->next;
            return;
        }

        int i = 0;

        while (current->next != head && i < position - 1)
        {
            current = current->next;
            i++;
        }
        if (current->next == head)
        {
            return;
        }

        node *temp = current->next;
        current->next = temp->next;
        free(temp);
        return;
    }

    bool search(int x)
    {
        node *i = head;

        while (i->next != head)
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
        node *current = head;

        if (head == NULL)
        {
            return;
        }

        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main()
{
    circle_ll a;

    a.insert_front(1);
    a.print();
    a.insert_front(2);
    a.print();
    a.insert_front(3);
    a.print();
    a.insert_front(12);
    a.print();

    a.insert_back(100);
    a.print();

    a.insert_middle(23, 2);
    a.print();

    a.remove_front();
    a.print();

    a.remove_back();
    a.print();

    a.remove_middle(2);
    a.print();

    bool x = a.search(3);
    cout << x << endl;

    return 0;
}
