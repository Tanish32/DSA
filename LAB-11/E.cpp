#include <vector>
#include <iostream>
#include <map>
using namespace std;
int compute(int n, vector<int> &v, int current, map<int, int> &memo)
{

    // Check if the result is already memoized
    if (memo.find(n) != memo.end())
        return memo[n];

    // Base case
    if (v.size() == 2)
    {
        return current;
    }

    // Recursive step
    vector<int> vals;
    for (int i = 0; i < v.size() - 2; i++)
    {
        vector<int> temp = v;
        int newCurrent = current + (v[i] * v[i + 1] * v[i + 2]);
        temp.erase(temp.begin() + i + 1);
        vals.push_back(compute(n - 1, temp, newCurrent, memo));
    }

    // Memoize the result
    int best = 100000000;
    for (auto it : vals)
    {
        if (it < best)
        {
            best = it;
        }
    }
    memo[n] = best;
    return best;
}

int main()
{
    int n, current = 0;
    cin >> n;
    vector<int> v(n + 1), temp;
    map<int, int> memo;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> v[i];
    }
    cout << compute(n, v, current, memo);
    return 0;
}
