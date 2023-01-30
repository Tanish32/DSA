#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100], *strNew, tokenizer[100][100];
    int spaceCounter = 0;
    scanf("%[^\n]%*c", str);
    // to get input in strNew
    strNew = (char *)malloc(sizeof(char) * strlen(str));
    // To reverse individual words and insert into tokenizer
    // number of words = spaceCounter+1
    int wordNumber = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        strNew[i] = str[i];
        // when a space is reached
        if (strNew[i] == ' ')
        {
            int k = i - 1;
            for (int j = 0; j < 10; j++, k--)
            {
                if (k == -1 || strNew[k] == ' ')
                {
                    break;
                }
                // printf("%d", wordNumber);
                tokenizer[wordNumber][j] = strNew[k];
            }
            wordNumber++;
            spaceCounter++;
        }
        // when we reach the last letter of the string
        else if (i == (strlen(str) - 1))
        {
            int k = i;
            for (int j = 0; j < 50; j++, k--)
            {
                if (strNew[k] == ' ')
                {
                    break;
                }
                // printf("%d", wordNumber);
                tokenizer[wordNumber][j] = strNew[k];
            }
        }
    }

    // to print the reversed string
    for (int i = 0; i < spaceCounter + 1; i++)
    {
        for (int j = 0; tokenizer[i][j] != '\0'; j++)
        {
            printf("%c", tokenizer[i][j]);
        }
        printf(" ");
    }
    // printf("%s",&tokenizer[1][0]);
    return 0;
}
