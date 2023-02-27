#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, inputOld, inputNew;
    scanf("%d", &n);
    scanf("%d", &inputOld);
    printf("%d\n", inputOld);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &inputNew);
        // mauplate the input
        int randomNum = rand() % 2;
        printf("#%d# ", rand());
        if (randomNum)
        {
            printf("%d\n", inputNew);
        }
        else
        {
            printf("%d\n", inputOld);
        }

        inputOld = inputNew;
    }
    return 0;
}
