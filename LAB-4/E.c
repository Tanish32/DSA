#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void coprime(int p, int b)
{
    int prime = p;
    while (p != b)
    {
        if (p > b)
        {
            p = p - b;
        }
        else
        {
            b = b - p;
        }
    }
    if (b == 1)
    {
        printf("%d", prime);
        exit(0);
    }
}
void sieve(int a, int b)
{
    bool *nums = (bool *)malloc(sizeof(bool) * (a + 1));
    memset(nums, true, sizeof(bool) * (a + 1));
    for (int p = 2; p * p <= a; p++)
    {
        if (nums[p] == true)
        {
            for (int i = p * p; i <= a; i += p)
            {

                nums[i] = false;
            }
        }
    }
    for (int i = 2; i < a; i++)
    {
        if (a % i != 0)
        {
            nums[i] = false;
        }
    }

    for (int i = a; i >= 2; i--)
    {
        if (nums[i] == true)
        {
            coprime(i, b);
        }
    }
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    sieve(a, b);
    return 0;
}
