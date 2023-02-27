#include <stdio.h>
void compute(int n, int k, int arr[])
{
    // num of sumarays with k oddies
    int ans = 0;
    // left ptr
    int l = 0;
    // to see num of odd nums
    int oddies = 0;
    // dynamic sized sliding window
    for (int r = 0; r < n; r++)
    {
        // to increase oddies if odd num found
        if (arr[r] % 2 == 1)
        {
            oddies++;
        }
        // Shifting the left pointer if too many oddies

        while (oddies > k)
        {
            // If the lth elem is odd
            if (arr[l] % 2 == 1)
            {
                oddies--;
                l++;
            } // If elem not odd
            else
            {
                l++;
            }
        }
        // When oddies == k ans icnreased
        if (oddies == k)
        {
            ans++;
        }
    }
    printf("%d", ans);
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
