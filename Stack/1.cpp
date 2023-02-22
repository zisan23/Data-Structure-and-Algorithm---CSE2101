#include <bits/stdc++.h>
using namespace std;

class DinnerPlates
{
    const int column = 10;
    int top, capacity;

    vector<vector<int>> stack;
    vector<int> index;

public:
    DinnerPlates(int capacity)
    {
        this->top = 0;
        this->capacity = capacity;

        this->stack.resize(column);
        this->index.resize(column);

        for (int i = 0; i < column; i++)
        {
            this->stack[i].resize(capacity);
        }

        for (int i = 0; i < column; i++)
        {
            this->index[i] = 0;
        }
    }

    void push(int value)
    {
        for (int i = 0; i < column; i++)
        {
            if (this->index[i] < this->capacity)
            {
                this->stack[i][index[i]] = value;
                this->index[i] += 1;
                this->top = max(this->top, i);
                return;
            }
        }
    }

    int pop()
    {
        // if (this->top == 0 and this->index[0] == 0)
        // {
        //     return -1;
        // }
        // if (this->index[this->top] == 0)
        // {
        //     return -1;
        // }

        if(stack.empty()){
            cout << "x" << endl;
            return -1;
        }

        int res = this->stack[this->top][this->index[this->top] - 1];
        this->index[this->top] -= 1;

        if (this->index[this->top] <= 0)
        {
            this->index[this->top] = 0;
            this->top -= 1;
        }
        return res;
    }

    int popAtStack(int index)
    {
        if (this->index[index] == 0)
        {
            return -1;
        }

        int res = this->stack[index][this->index[index] - 1];
        this->index[index] -= 1;

        if (this->index[index] <= 0)
        {
            this->index[index] = 0;
            this->top -= 1;
        }
        return res;
    }

    void display()
    {
        for (int i = 0; i <= this->top; i++)
        {
            for (int j = 0; j < this->index[i]; j++)
            {
                cout << this->stack[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
};

int main()
{
    DinnerPlates D = DinnerPlates(2);

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

/*void print(void)
	{
		for (int i = cap - 1; i >= 0; i--)
		{
			for (int j = 0; j < maxsize; j++)
			{
				if (a[j][i] != 0)
				{
					cout << a[j][i] << " ";
				}
				else
				{
					cout << "  ";
				}

				// cout << a[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/