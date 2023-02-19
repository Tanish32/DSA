#include <stdio.h>
void compute(int n, int arr[]) {
    int numZeros[n], div, sum;
    for (int i = 0; i < n; i++) {
        div = 5;
        sum = 0;
        while (div <= arr[i]) {
            sum += arr[i] / div;
            div *= 5;
        }
        numZeros[i] = sum;
    }
    int greatest = 0;
    for (int i = 0; i < n; i++) {
        if (numZeros[i] > greatest) {
            greatest = numZeros[i];
        }
    }
    int aggeregateNumZeros[greatest];
    for (int i = 0; i < n; i++) {
        aggeregateNumZeros[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        aggeregateNumZeros[numZeros[i]]++;
    }
    sum = 0;
    for (int i = 0; i < greatest; i++) {
        if (aggeregateNumZeros[i] > 0) {
            sum += (aggeregateNumZeros[i] * (aggeregateNumZeros[i] - 1)) / 2;
        }
    }
    printf("%d\n", sum);
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
