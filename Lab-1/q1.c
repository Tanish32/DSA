#include <stdio.h>
#include <stdlib.h>
void getSubSum();
int getB();
int main()
{
    getB();
    return 0;
}

int getB()
{
    // To get input
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    int matrixResult[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // To generateB
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            {
                //
                for (int k = 0; k < m; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        sum += matrix[k][l];
                        if (k == i && l == j)
                        {
                            k = m;
                            l = n;
                        }
                    }
                }
                //
                matrixResult[i][j] = sum;
            }
        }
    }
    // To print the matrix
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrixResult[i][j]);
        }
    }
    // To get sum of submatrix or cancel and print not possible
    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
        //To check submatrix can be determined
    if(ri+rh>m || ci+ch>n){
        printf("NOT POSSIBLE");
        return 0;
        //if submatrix is determinable
    }
    for (int i = ri; i < ri + rh; i++)
    {
        for (int j = ci; j < ci + ch; j++)
        {
            
        }
    }
}
