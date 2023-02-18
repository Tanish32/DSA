#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    int arr[n];
    //
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int count = 0;
    long long int chocPerStudent = sum / n;
    for (int i = 0; i < n; i++) {
        while (arr[i] != chocPerStudent) {
            if (arr[i] > chocPerStudent) {
                arr[i]--;
                count++;
            } else {
                arr[i]++;
                count++;
            }
        }
    }
    printf("%d\n", count);
    //
    return 0;
}
