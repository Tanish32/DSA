#include <iostream>
#include <vector>
using namespace std;
// Kadane's Algorithm
int maxSubarraySum(vector<int> &arr)
{
    int ans = INT8_MIN, cursum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        cursum += arr[i];
        if (cursum > ans)
            ans = cursum;
        if (cursum < 0)
            cursum = 0;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubarraySum(arr) << endl;
}
