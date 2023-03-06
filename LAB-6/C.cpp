#include <iostream>
#include <stack>
using namespace std;
void computeNextLowest(int n, int arr[], int reverse, int result[])
{
    stack<int> st;
    int NL[n];
    for (int i = 0; i < n; i++)
    {
        NL[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st.push(i);
            continue;
        }
        if (arr[i] >= arr[st.top()])
        {
            st.push(i);
            continue;
        }
        if (arr[i] < arr[st.top()])
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                NL[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    int arrNew[n];
    for (int i = 0, j; i < n; i++)
    {
        if (reverse)
        {
            j = n - i - 1;
            arrNew[i] = NL[j];
        }
        else
        {
            result[i] = NL[i];
        }
    }
    if (reverse)
    {
        for (int i = 0; i < n; i++)
        {
            arrNew[i] = n - 1 - arrNew[i];
            result[i] = arrNew[i];
        }
    }
}

void computePrevLowest(int n, int arr[], int reverse, int prevLowest[])
{
    int reverseArr[n];
    for (int i = 0; i < n; i++)
    {
        reverseArr[i] = arr[n - i - 1];
    }
    computeNextLowest(n, reverseArr, 1, prevLowest);
}

void compute(int n, int arr[])
{
    int nxtLowest[n], prevLowest[n], greatest = -10000;
    computeNextLowest(n, arr, 0, nxtLowest);
    cout << endl;
    computePrevLowest(n, arr, 1, prevLowest);
    for (int i = 0; i < n; i++)
    {
        if (((nxtLowest[i] - prevLowest[i] - 1) * arr[i]) > greatest)
        {
            greatest = ((nxtLowest[i] - prevLowest[i] - 1) * arr[i]);
        }
    }
    cout << greatest << endl;
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
