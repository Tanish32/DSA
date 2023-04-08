#include <bits/stdc++.h>
using namespace std;
void compute(int n, int m, int k, vector<int> arr)
{
    int flag = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (i >= m)
        {
            mp[arr[i - m]]--;
        }
        if (i >= m - 1)
        {
            auto lastElement = --mp.end();
            while (lastElement->second != k)
            {
                lastElement--;
                if (lastElement == mp.begin() && (lastElement->second != k))
                {
                    flag++;
                    break;
                }
            }
            if (flag != 1)
            {
                cout << lastElement->first << endl;
            }
            else
            {
                cout << "-1" << endl;
                flag--;
            }
        }
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    compute(n, m, k, arr);
    return 0;
}
