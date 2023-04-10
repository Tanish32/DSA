#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x,y;
    cin>>x>>y;
    int c=0;
    multiset<int> s;
for(int i=0;i<n;i++)
{
int num=a[i]-y*i;
if(s.find(num)!=s.end())
{
c+=s.count(num);
}
s.insert(a[i]-x*i);
}
cout<<c;    
}
