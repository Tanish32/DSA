#include <stdio.h>
#include <math.h>
#include <string.h>
int checker(int turns, int primes[], char num);
void main()
{
    int a, b, numberOfSevens = 0;
    scanf("%d %d", &a, &b);
    int primes[100000], numberOfPrimes = 0, repitions[10];
    // to find primes and add them to primes array
    for (int i = a; i <= b; i++)
    {
        int counter = 0;
        for (int j = 2; j < (int *)(i / 2); j++)
        {
            if (i % j == 0)
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            primes[numberOfPrimes] = i;
            numberOfPrimes++;
            // printf("%d ", i);
        }
    }
    // to check number of 7s in the primes
    int k = 0, turns = 0;
    for (char i = '0'; i <= '9'; i++, k++)
    {
        turns = 0;
        repitions[k] = checker(turns, primes, i);
    }

    // to print result
    int heighest = repitions[0], number;
    for (int i = 0; i < 9; i++)
    {
        if (repitions[i] > heighest)
        {
            heighest = repitions[i];
            number = i;
        }
    }
    printf("%d %d", number, heighest);
}
// To return number of times a num was in all the primes combined
int checker(int turns, int primes[], char num)
{
    char str[(int)1000];
    for (int i = 0; primes[i] != '\0'; i++)
    {
        sprintf(str, "%d", primes[i]);
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == num)
            {
                turns++;
            }
        }
    }
    return turns;
}
