#include <stdio.h>
int main() {
  int n;
  int k;
  scanf("%d %d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int high = a[n - 1];
  int low = 1;
  int target;
  int ans = 0, mid, index;
  while (low <= high) {
    target = 0;
    mid = (high + low) / 2;
    for (int i = 0; i < n; i++) {
      target = target + a[i] / mid;
    }
    if (target >= k) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  printf("%d", ans);
}
