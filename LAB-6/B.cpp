#include <iostream>
#include <stack>
using namespace std;
void computeNextGreatest(int n, int arr[], int nextGreatest[], int ans[])
{
    stack<int> st;
    int bottom;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i == 0)
        {
            bottom = arr[i];
            st.push(i);
            continue;
        }
        if (arr[i] <= arr[st.top()])
        {
            if (i < n)
            {
                st.push(i);
            }
            continue;
        }
        // make a function for equal case
        if (arr[i] <= bottom && arr[i] > arr[st.top()])
        {
            while (arr[i] > arr[st.top()])
            {
                nextGreatest[st.top()] = i;
                st.pop();
            }
        }
        if (arr[i] > bottom)
        {
            while (!st.empty())
            {
                nextGreatest[st.top()] = i;
                st.pop();
            }
            bottom = arr[i];
            st.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nextGreatest[i] != -1)
        {
            ans[i] = nextGreatest[i] - i;
        }
        else
        {
            ans[i] = nextGreatest[i];
        }
        cout << ans[i] << " ";
    }
}
void compute(int n, int arr[])
{
    int nextGreatest[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        nextGreatest[i] = -1;
    }
    int ans[n];
    computeNextGreatest(n, arr, nextGreatest, ans);
}
int main()
{
    int n;
    cin >> n;
    int arr[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i < n)
        {
            cin >> arr[i];
        }
        else
        {
            arr[i] = arr[(i - n)];
        }
    }
    compute(n, arr);
    return 0;
}
