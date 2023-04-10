#include <bits/stdc++.h>
using namespace std;
void fun1(int val, vector<int> &v, map<int, int> &mp)
{
    mp[val] ^= 1;
}
void fun2(int val, vector<int> &v, map<int, int> &mp)
{
    for (auto it : mp)
    {
        if (it.first >= val && it.second == 1)
        {
            cout << it.first << endl;
            return;
        }
    }
    cout << "-1" << endl;
}
void fun3(int val, vector<int> &v, map<int, int> &mp)
{
    auto last = --mp.end();
    while (last != mp.begin())
    {
        if (last->first <= val && last->second == 1)
        {
            cout << last->first;
            return;
        }
        last--;
    }
    if (mp.begin()->second != 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << mp.begin()->first << endl;
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n, 0);
    map<int, int> mp;
    for (int i = 0, choice, val; i < q; i++)
    {
        cin >> choice >> val;
        if (choice == 1)
        {
            fun1(val, v, mp);
        }
        else if (choice == 2)
        {
            fun2(val, v, mp);
        }
        else if (choice == 3)
        {
            fun3(val, v, mp);
        }
    }
    return 0;
}
