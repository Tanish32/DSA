#include <bits/stdc++.h>
using namespace std;
void compute(int n, int k, vector<pair<int, int>> &results)
{
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[results[i].first].first++;
        mp[results[i].second].second++;
    }
    for(auto it : mp){
        if(it.second.second <= 1){
            cout<<it.first<<" ";
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> results;
    pair<int, int> temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.first >> temp.second;
        results.push_back(temp);
    }
    compute(n, k, results);
    return 0;
}
