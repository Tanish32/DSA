#include <bits/stdc++.h>
using namespace std;
void compute(int n, vector<int> a, int m, vector<int> b)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    auto mid = (m + n) / 2;
    auto it = s.begin();
    // moves iterator by mid ammt
    advance(it, mid);
    if (mid % 2 != 0)
    {
        cout << *it << endl;
    }
    else
    {
        cout << (((*it) + (*(--it))) / 2.0) << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    compute(n, a, m, b);
    return 0;
}
