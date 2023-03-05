#include <iostream>
#include <deque>
using namespace std;
void printMax(int arr[], int n, int k)
{
    deque<int> dq;

    // Process the first k elements
    for (int i = 0; i < k; i++) {
        // Remove elements smaller than current element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        // Add current element to deque
        dq.push_back(i);
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        // Print the maximum element of previous window
        cout << arr[dq.front()] << " ";

        // Remove elements outside of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove elements smaller than current element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        // Add current element to deque
        dq.push_back(i);
    }

    // Print the maximum element of the last window
    cout << arr[dq.front()] << endl;
}


int main()
{
    int n, k;
    cin>>n;
    cin>>k;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    printMax(arr, n, k);
    return 0;
}


//

