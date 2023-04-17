// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count subarray having average
// exactly equal to K
int countKAverageSubarrays(int arr[], int n, int k)
{
	int result = 0, curSum = 0;

	// Store the frequency of prefix
	// sum of the array arr[]
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		// Subtract k from each element,
		// then add it to curSum
		curSum += (arr[i] - k);

		// If curSum is 0 that means
		// sum[0...i] is 0 so increment
		// res
		if (curSum == 0)
			result++;

		// Check if curSum has occurred
		// before and if it has occurred
		// before, add it's frequency to
		// res
		if (mp.find(curSum) != mp.end())
			result += mp[curSum];

		// Increment the frequency
		// of curSum
		mp[curSum]++;
	}

	// Return result
	return result;
}

// Driver code
int main()
{
	// Given Input
	int K = 2;
	int arr[] = { 2, 1 ,3};
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << countKAverageSubarrays(arr, N, K);
}
