#include <stdio.h>
int computeAllies(int arr[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += (arr[i] * (arr[i] - 1)) / 2;
    }
    return sum;
}
int getMin(int n, int m)
{
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; n != 0; i++, n--)
    {
        if (i == m)
        {
            i = 0;
        }
        arr[i]++;
    }
    return computeAllies(arr, m);
}
int getMax(int n, int m)
{
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            arr[m - 1] = n - m + 1;
            break;
        }
        arr[i] = 1;
    }
    return computeAllies(arr, m);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d %d", getMin(n, m), getMax(n, m));
    return 0;
}
