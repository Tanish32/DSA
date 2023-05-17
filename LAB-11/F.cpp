#include <bits/stdc++.h>
using namespace std;
int couponChange(vector<int> v, int k, unordered_map<int, int> mp)
{
    if(mp[k]!=0){
        return mp[k];
    }
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
        returns[i] = couponChange(v, k - v[i], mp);
        if (returns[i] < min)
            min = returns[i];
    }
    
    if (min == INT_MAX)
    {
        return INT_MAX;
    }
    else
    {
        mp[k] = min+1;
        return mp[k];
    }
}
int main()
{
    int n, k, min = INT_MAX;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < min)
            min == v[i];
    }
    int val = couponChange(v, k, mp);
    if (val == INT_MAX)
    {
        cout << -1;
    }
    else
        cout << val;
    return 0;
}
