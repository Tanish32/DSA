#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[100], B[100];
    scanf("%s", A);
    scanf("%s", B);
    // scanf("%[^\n]%*c", B);
    int length = strlen(A);
    int integerSeq[length];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (B[i] == A[j])
            {
                integerSeq[i] = j + 1;
            }
        }
        if (integerSeq[i] == 0)
        {
            printf("NOT POSSIBLE");
            return 0;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", integerSeq[i]);
    }
    return 0;
}
