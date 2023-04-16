#include <bits/stdc++.h>
using namespace std;
int compute(int n, int k, vector<int> v)
{
    sort(v.begin(), v.end());
    vector<int> v2;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        v2.push_back(v[i] + k);
    }
    // lower_bound(start,end,value)
    int i = lower_bound(v.begin(), v.end(), v2[0]) - v.begin(), j = 0;
    while (i < n)
    {
        if (v[i] >= v2[j])
        {
            count++;
            j++;
            i++;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    cout << compute(n, k, v);
    return 0;
}
