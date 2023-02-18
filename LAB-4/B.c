#include <stdio.h>
void merge(int l, int r, int mid, int arr[]) {
    // printf("@");
    int leftLength = mid - l + 1, rightLength = r - mid;
    int leftArr[leftLength], rightArr[rightLength];
    int i, j, k;
    for (int i = 0; i < leftLength; i++) {
        leftArr[i] = arr[l + i];
    }
    for (int i = 0; i < rightLength; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    for (i = 0, j = 0, k = l; k <= r; k++) {
        if ((i < leftLength) &&
            (j >= rightLength || leftArr[i] <= rightArr[j])) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
    }
}
void merge_sort(int l, int r, int arr[]) {
    int mid = (l + r) / 2;
    if (l < r) {
        merge_sort(l, mid, arr);
        merge_sort(mid + 1, r, arr);
        merge(l, r, mid, arr);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Q logic
    merge_sort(0, n - 1, arr);
    for (int i = n - 1, count = 1; i >= 0; i--, count++) {
        if (arr[i] == count) {
            printf("%d", count);
            break;
        }
    }
    return 0;
}
