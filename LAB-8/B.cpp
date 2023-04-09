#include <bits/stdc++.h>
using namespace std;
void palindromise(int n, string &A)
{
    if (A[(n / 2) + 1] > A[(n / 2) - 1])
    {
        A[n / 2]++;
    }
    for (int i = (n / 2) + 1; i < n; i++)
    {
        A[i] = A[n - i - 1];
    }
}
string compute(int n, string A)
{
    if (n % 2 == 1)
    {
        palindromise(n, A);
        return A;
    }
    else
    {
        A.erase(n / 2, 1);
        n--;
        palindromise(n, A);
        A.insert(n / 2, 1, A[n / 2]);
        return A;
    }
}
int main()
{
    int n;
    cin >> n;
    string A;
    cin >> A;
    cout << compute(n, A);
    return 0;
}
