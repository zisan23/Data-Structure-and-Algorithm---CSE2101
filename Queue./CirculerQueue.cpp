#include <bits/stdc++.h>
using namespace std;

class CirculerQueue
{
private:
    int capacity;
    int size = 0;
    int *arr = NULL;
    int front, last;

public:
    CirculerQueue(int capacity)
    {

        last = -1;
        front = -1;

        this->capacity = capacity;
        arr = new int[this->capacity];
    }

    int getSize()
    {
        return size;
    }

    void enque(int data)
    {
        if ((front == 0 && last == capacity - 1) || (last == (front - 1) % (capacity - 1)))
        {
            return;
        }
        else if (front == -1)
        {
            front = last = 0;
            arr[last] = data;
        }
        else if (last == capacity - 1 && front != 0)
        {
            last = 0;
            arr[last] = data;
        }
        else
        {
            last++;
            arr[last] = data;
        }

        size++;
    }

    void deque()
    {
        if (front == -1)
        {
            return;
        }
        else if (front == last)
        {
            front = -1;
            last = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        size--;
    }
    int peek()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (front == -1)
        {
            return;
        }

        if (last >= front)
        {
            for (int i = front; i <= last; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else
        {
            for (int i = front; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= last; i++)
            {
                cout << arr[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    CirculerQueue q = CirculerQueue(5);

    q.enque(11);
    q.enque(12);
    q.enque(13);
    q.enque(14);
    q.enque(15);

    q.display();

    q.deque();
    q.deque();

    q.display();

    q.enque(99);
    q.enque(100);
    q.enque(101);

    q.display();

    q.deque();
    q.display();

    return 0;
}