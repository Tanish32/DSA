#include <bits/stdc++.h>
using namespace std;
void compute(string &s)
{
    string str;
    int count = 0;
    map<string, int> mp;
    for (int i = 0; i < s.length() - 10 + 1; i++)
    {
        // substr (index, length)
        str = s.substr(i, 10);
        mp[str]++;
        
    }
    for(auto it: mp){
        if(it.second>1){
            count++;
        }
    }
    cout<<count<<endl;
    for(auto it: mp){
        if(it.second>1){
            cout<<it.first<<endl;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    compute(s);
    return 0;
}
