#include <stdio.h>
void compute(int n, int arr[]) {
    int greatest = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }
    int numOfNotDivisible = 0, gcd = 1;
    for (int i = 2; i <= greatest; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] % i != 0) {
                numOfNotDivisible++;
            }
        }
        if (numOfNotDivisible > 1) {
            continue;
        } else {
            gcd = i;
        }
    }
    printf("%d", gcd);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    compute(n, arr);
    return 0;
}
