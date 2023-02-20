#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void compute(int n, int q, int arr[])
{
    bool prime[n + 1];
    // SieveOfEratosthenes
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    //
    int count = 0;
    for (int i = 0; i < q; i++)
    {
        for (int p = 2; p <= n; p++)
        {
            if (prime[p] && p <= arr[i])
            {
                count++;
            }
        }
        printf("%d ", count);
        count = 0;
    }
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &arr[i]);
    }
    compute(n, q, arr);
    return 0;
}
