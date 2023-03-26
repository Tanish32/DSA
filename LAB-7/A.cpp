#include <bits/stdc++.h>
using namespace std;
void compute(int n, int m, priority_queue<int> *pq)
{
    int temp;
    while (m != 0 && !(pq)->empty())
    {
        temp = (*pq).top()/2;
        (*pq).pop();
        (*pq).push(temp);
        m--;
    }
}

int main()
{
    priority_queue<int> pq;
    int n, m, temp;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        (pq).push(temp);
    }
    compute(n, m, &pq);
    int sum=0;
    while (!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
    return 0;
}
