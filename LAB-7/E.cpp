#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp, m;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    cin >> m;
    for (int i = 1; i < m; i++)
    {
        pq.pop();
    }
    cout << pq.top();
    return 0;
}
