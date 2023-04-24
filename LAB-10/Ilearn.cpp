#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sumA += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        sumB += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if ((sumA - sumB) % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    long long diff = abs(sumA - sumB) / 2;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) == diff)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << "No" << endl;
}
