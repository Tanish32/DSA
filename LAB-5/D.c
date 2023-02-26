#include <stdio.h>
void compute(int n, int k, float t, float arr[])
{
    float running_avg = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        running_avg += arr[i] / k;
        if (i > k - 1)
        {
            running_avg -= arr[i - k] / k;
        }

        if (i > k - 3)
        {
            if (running_avg + 0.00001 >= t)
            {
                count++;
            }
        }

    }
    printf("%d\n ", (int)count);
}
int main()
{
    int n, k;
    float t;
    scanf("%d %d %f", &n, &k, &t);
    float arr[n];
    for (int i = 0; i < 8; i++)
    {
        scanf("%f", &arr[i]);
    }
    compute(n, k, t, arr);
    return 0;
}
