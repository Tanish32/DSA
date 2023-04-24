#include <bits/stdc++.h>
using namespace std;
void compute(int n, int m, map<int, int> mp, vector<int> v)
{
    int num = 0;
    for (auto it : v)
    {
        num = mp[it];
        for (int i = 0; i < num; i++)
        {
            cout << it << " ";
            mp[it]--;
        }
    }
    for (auto it : mp)
    {
        for (int i = 0; i < it.second; i++)
        {
            cout << it.first << " ";
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        mp[temp]++;
    }
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    compute(n, m, mp, v);
    return 0;
}
