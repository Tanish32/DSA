#include <bits/stdc++.h>
using namespace std;
int compute(int n, vector<pair<int, int>> &v)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > v[i + 1].first)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0, temp1, temp2; i < n; i++)
    {
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    sort(v.begin(), v.end());
    cout << compute(n, v);
    return 0;
}
