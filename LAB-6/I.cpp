#include <iostream>
#include <stack>
#include <string>
using namespace std;
void compute(string input)
{
    stack<char> st1;
    stack<char> st2;
    for (int i = 0; i < input.length(); i++)
    {
        if (!st1.empty() && st1.top() == '/' && input[i] == '/')
        {
            continue;
        }
        if (!st1.empty() && input[i] == '.' && input[i + 1] != '.' && input[i - 1] != '.')
        {
            continue;
        }
        if (!st1.empty() && input[i] == '.' && input[i + 1] == '.' )
        {
            //to pop the /
            st1.pop();
            while (!st1.empty() && st1.top()!='/')
            {
                st1.pop();
            }
            i++;
            continue;
        }
        st1.push(input[i]);
    }
    if (!st1.empty() && st1.top() == '/')
    {
        st1.pop();
        if (st1.empty())
        {
            st1.push('/');
        }
    }
    for (int i = 0; i < input.length() && !st1.empty(); i++)
    {
        st2.push(st1.top());
        st1.pop();
    }
    if (st2.top() != '/')
    {
        st2.push('/');
    }
    for (int i = 0; i < input.length() && !st2.empty(); i++)
    {
        cout << st2.top();
        st2.pop();
    }
    cout << endl;
    cout << endl;
}
int main()
{
    string input;
    cin >> input;
    cout << endl;
    compute(input);
    return 0;
}
