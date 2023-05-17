#include <bits/stdc++.h>
using namespace std;
int couponChange(vector<int> v, int k)
{
    if (k < 0)
    {
        return INT_MAX;
    }
    else if (k == 0)
    {
        return 0;
    }
    vector<int> returns(v.size());
    int min = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        returns[i] = couponChange(v, k - v[i]);
        if (returns[i] < min)
            min = returns[i];
    }
    if (min == INT_MAX)
    {
        return INT_MAX;
    }
    else
    {
        return min + 1;
    }
}
int main()
{
    int n, k, min = INT_MAX;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < min)
            min == v[i];
    }
    int val = couponChange(v, k);
    if (val == INT_MAX)
    {
        cout << -1;
    }
    else
        cout << val;
    return 0;
}
