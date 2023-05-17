#include <bits/stdc++.h>
using namespace std;
bool checkSum(int k, vector<int> v, unordered_map<int, bool> mp)
{
    if (mp[k] == true)
    {
        return true;
    }
    if (k == 0)
        return true;
    else if (k < 0)
        return false;
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> temp;
        for (auto it : v)
        {
            if (it != v[i])
            {
                temp.push_back(it);
            }
        }
        if (checkSum(k - v[i], temp, mp) == true)
        {
            mp[k] = true;
            return mp[k];
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << checkSum(k, v, mp);
    return 0;
}
