#include <iostream>
#include <stack>
using namespace std;
void computeNextGreater(int n, int arr[], int nextGreater[])
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = n;
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st.push(i);
            continue;
        }
        if (!st.empty() && (arr[i] <= arr[st.top()]))
        {
            st.push(i);
        }
        if (!st.empty() && arr[i] > arr[st.top()])
        {
            while (!st.empty() && arr[i] > arr[st.top()])
            {
                temp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        nextGreater[i] = temp[n - i - 1];
        nextGreater[i] = n - nextGreater[i] - 1;
    }
}
void compute(int n, int arr[])
{
    int nextGreater[n];
    int rArr[n];
    for (int i = 0; i < n; i++)
    {
        rArr[i] = arr[n - i - 1];
    }
    computeNextGreater(n, rArr, nextGreater);

    for (int i = 0; i < n; i++)
    {
        cout << i - nextGreater[i] << " ";
    }
}
int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    compute(n, arr);
    return 0;
}
