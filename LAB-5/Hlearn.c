#include <stdio.h>

int main()
{
    int n, k, i, rem;
    long long ans = 0;
    scanf("%d %d", &n, &k);
    int a[n + 1], prefix[n + 1], freq[k];
    for (i = 0; i < k; i++)
        freq[i] = 0;
    prefix[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        prefix[i] = (prefix[i - 1] + a[i]) % k;
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
        if (prefix[i] == 0)
            ans++; // add 1 for subarrays whose sum is a multiple of k and whose
                   // starting index is 1
    }
    printf("%lld\n", ans);
    return 0;
}
