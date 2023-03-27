#include <bits/stdc++.h>
using namespace std;
void compute(int k, int nums, vector<priority_queue<int,vector<int>,greater<int>>> v)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < nums; i++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if(!v[i].empty()){
                pq.push(v[i].top());
                v[i].pop();
            }else{
                v.erase(v.begin()+i);
            }
        }
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main()
{
    int n, numElem = 0;
    cin >> n;
    vector<priority_queue<int,vector<int>,greater<int>>> v;
    for (int i = 0, len, temp2; i < n; i++)
    {
        cin >> len;
        numElem += len;
        priority_queue<int,vector<int>,greater<int>> temp;
        for (int i = 0; i < len; i++)
        {
            cin >> temp2;
            temp.push(temp2);
        }
        v.push_back(temp);
    }
    compute(n, numElem, v);
    return 0;
}
