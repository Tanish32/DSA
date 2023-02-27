#include <stdio.h>
void compute(int n, int A[], int m, int B[])
{
    int C[n * m];
    for (int i = 0; i < n * m; i++)
    {
        C[i] = A[i / m] ^ B[i % m];
        // printf("%d ", C[i]);
    }
    int ans = C[0];
    for (int i = 1; i < n * m ; i++)
    {
        ans = ans ^ C[i];
    }
    printf("%d ", ans);
}
int main()
{
    int n, m;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }
    compute(n, A, m, B);
    return 0;
}
