#include <bits/stdc++.h>
using namespace std;
void compute(map<pair<int, int>, int> mp1, map<pair<int, int>, int> mp2)
{
    cout<<endl;
    int count=0;
    for (auto it1 : mp1)
    {
        for (auto it2 : mp2)
        {
            if (it1.first.second == it2.first.first)
            {
                count++;
                cout << it1.first.first << " " << it2.first.second << " " << it1.second * it2.second << endl;
            }
        }
    }
    cout<<count;
}

int main()
{
    int m, k, n, p, q, x;
    cin >> m >> k >> n >> p;
    pair<int, int> temp;
    map<pair<int, int>, int> mp1;
    map<pair<int, int>, int> mp2;
    for (int i = 0; i < p; i++)
    {
        cin >> temp.first >> temp.second >> x;
        mp1[temp] = x;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> temp.first >> temp.second >> x;
        mp2[temp] = x;
    }
    compute(mp1, mp2);
    return 0;
}
