#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum, nums=0;
    cin >> n;
    cin >> sum;
    int arr[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(i>1){
            arr[i]+=arr[i/2];
        }
        if(arr[i]==sum){
            nums++;
        }
    }
    cout<<nums;
    return 0;
}
