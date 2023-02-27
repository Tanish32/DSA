#include <stdio.h>
void compute(int n, int k, int arr[])
{
    // max current length
    int ans = 0;
    // start of window
    int l = 0;
    // current streak of 1's ,and 0's that can be turned into 1's
    int streak = 0;
    // current no of 0s
    int zeros = 0;
    // r is the end of window
    // Dynamic window implementation
    for (int r = 0; r < n; r++)
    {
        streak++;
        if (arr[r] == 0)
        {
            zeros++;
        }
        // reduce the number of zeros to one less than k if the next elem
        // is 0
        if (arr[r + 1] == 0 && zeros == k)
        {
            // current longest streak
            if (streak > ans)
            {
                ans = streak;
            }

            // loop to reduce the number of zeroes to k-1
            while (zeros == k)
            {
                // remove the last elemet of window
                if (arr[l] == 0)
                {
                    zeros--;
                    streak--;
                    l++;
                }
                else
                {
                    l++;
                    streak--;
                }
            }
        }
    }
    printf("%d ", ans);
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    compute(n, k, arr);
    return 0;
}
