#include <bits/stdc++.h>
using namespace std;
void compute(int n, vector<int> v3)
{
    int total = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        total += v3[i];
    }
    if (total <= 0)
    {
        cout << "-1";
        return;
    }
    total = 0;
    for (int i = 0; i < n; i++)
    {
        total += v3[i];
        if (total <= 0)
        {
            start=i+1;
            total=0;
        }
    }
    cout<<start;
}
int main()
{
    int n;
    vector<int> v1, v2, v3;
    cin >> n;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        v2.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        v3.push_back(v1[i] - v2[i]);
    }

    compute(n, v3);
    return 0;
}
