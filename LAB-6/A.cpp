#include <iostream>
using namespace std;
class Stack
{
    int stack[1000];
    int topOfStack;
    int val;

public:
    Stack()
    {
        topOfStack = -1;
    }
    void push(int val)
    {
        topOfStack++;
        stack[topOfStack] = val;
    }
    void pop()
    {
        if (topOfStack >= 0)
        {
            topOfStack--;
        }
    }
    int top()
    {
        if (topOfStack >= 0)
        {
            return stack[topOfStack];
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i <= topOfStack; i++)
        {
            cout << stack[i] << endl;
        }
        // cout << stack[topOfStack];
    }
};
class MinStack
{
    int stack[1000];
    int topOfStack = -1;
    int min = __INT32_MAX__;
    int initialSize, val, num_commands, command, secondary_val;
    // Why does below work as it is?
    Stack mStack;

public:
    MinStack()
    {
        cin >> initialSize;
        for (int i = 0; i < initialSize; i++)
        {
            cin >> val;
            push(val);
        }
        cin >> num_commands;
        for (int i = 0; i < num_commands; i++)
        {
            cin >> command;
            if (command == 1)
            {
                cin >> secondary_val;
            }
            switch (command)
            {
            case 1:
                if (secondary_val < mStack.top())
                    mStack.push(secondary_val);
                push(secondary_val);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << top() << ": Output"<<endl;
                break;
            case 4:
                cout << getMin() << ": Output"<<endl;
                break;

            default:
                cout << "Wrong command";
                break;
            }
        }
    }
    void push(int val)
    {
        topOfStack++;
        stack[topOfStack] = val;
        if (val < min)
        {
            min = val;
            mStack.push(val);
        }
    }
    void pop()
    {
        if (topOfStack >= 0)
        {
            if (stack[topOfStack] == mStack.top())
            {
                mStack.pop();
            }
            topOfStack--;
        }
    }
    int top()
    {
        if (topOfStack >= 0)
        {
            return stack[topOfStack];
        }
        return -1;
    }
    int getMin()
    {
        return mStack.top();
    }
};
int main()
{
    MinStack ans;
    return 0;
}
