#include <bits/stdc++.h>
using namespace std;
void compute(int n, int m, map<string, int> &mp)
{
    int count = 0;
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            count += ((it.second) * (it.second - 1)) / 2;
        }
    }
    cout << count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string temp;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sort(temp.begin(), temp.end());
        mp[temp]++;
    }
    compute(n, m, mp);
    return 0;
}
