#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, q, nextCandle = -1, left, right;
  cin >> n >> q;
  int prefixStars[n], leftCan[n], rightCan[n];
  string inp;
  cin >> inp;
  for (int i = 0; i < n; i++)
  {
    if (inp[i] == '*')
    {
      prefixStars[i] = (i > 0) ? prefixStars[i - 1] + 1 : 1;
    }
    else
    {
      prefixStars[i] = (i > 0) ? prefixStars[i - 1] : 0;
      nextCandle = i;
    }
    leftCan[i] = nextCandle;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    if (inp[i] == '|')
      nextCandle = i;
    rightCan[i] = nextCandle;
  }
  for (; q > 0; q--)
  {
    cin >> left >> right;
    if ((leftCan[right] < left) || (rightCan[left] > right))
      cout << 0 << endl;
    else
      cout << abs(prefixStars[rightCan[left]] - prefixStars[leftCan[right]])<<endl;
}
}
