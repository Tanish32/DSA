#include <stdbool.h>
#include <stdio.h>
bool check(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            return false;
        }
    }
    if (sum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int compute(int n, int arr[], int index)
{
    // show all possible permutaiton using bitsmasking
    if (index == n)
    {
        if (check(n, arr))
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    printf("(");
                }
                else
                {
                    printf(")");
                }
            }
            printf("\n");
        }
        return 0;
    }
    arr[index] = 1;
    compute(n, arr, index + 1);
    arr[index] = -1;
    compute(n, arr, index + 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    compute(n, arr, 0);
    return 0;
}
