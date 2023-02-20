#include <math.h>
#include <stdio.h>
int min(int a, int b)
{
    if (a >= b)
        return b;
    else
        return a;
}
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void compute(int n, int start[], int end[])
{
    int count = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (end[i] >= start[j] && start[i] <= end[j] && i != j)
            {
                start[i] = min(start[i], start[j]);
                end[i] = max(end[i], end[j]);
                start[j] = 0;
                end[j] = 0;
                count--;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++)
    {
        if (start[i] != 0 || end[i] != 0)
        {
            printf("%d %d", start[i], end[i]);
            printf("\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int start[n], end[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &start[i], &end[i]);
    }
    compute(n, start, end);
    return 0;
}
