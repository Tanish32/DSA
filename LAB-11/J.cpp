#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool compute(int n, int k, int index, vector<int> v, map<pair<int, int>, bool> &mp)
{
    // memoization
    if (mp.find({index, k}) != mp.end())
    {
        return mp[{index, k}];
    }
    //  Base Case
    if (k == 0)
    {
        return true;
    }
    else if (k < 0)
    {
        return false;
    }
    // Recursive procedure
    vector<bool> temp;
    for (int i = index; i < n; i++)
    {
        temp.push_back(compute(n, k - v[i], i + 1, v, mp));
    }
    for (auto it : temp)
    {
        if (it == true)
        {
            mp[{index, k}] = true;
            return true;
        }
    }
    temp.clear();
    mp[{index, k}] = false;
    return false;
}
int main()
{
    int n, k, index = 0;
    cin >> n >> k;
    map<pair<int, int>, bool> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << compute(n, k, index, v, mp);
    return 0;
}
