#include <bits/stdc++.h>
using namespace std;
int greatest = 0;
bool sorter(string s1, string s2)
{
    for (int i = 0; i < greatest; i++)
    {
        if (s1[i] > s2[i])
        {
            return true;
        }
        if (s1[i] < s2[i])
        {
            return false;
        }
        if (s1[i] == s2[i])
        {
            if (s1.length() == s2.length())
            {
                return true;
            }
            if (i == s1.length() - 1)
            {
                if (s2[i + 1] > s1[i])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            if (i == s2.length() - 1)
            {
                if (s1[i + 1] > s2[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp.length() > greatest)
        {
            greatest = temp.length();
        }
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), sorter);
    string result = v[0];
    for (int i = 1; i < n; i++)
    {
        result+=v[i];
    }
    cout<<result;
    return 0;
}
