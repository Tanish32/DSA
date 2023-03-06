#include <stdio.h>
#include <string.h>

void compute(int n, int arr[]) {
  int indexes[n], j = 0;
  memset(indexes, 0, sizeof(indexes));
  for (int i = 0; i < n; i++) {
    indexes[arr[i]]++;
    if (indexes[arr[j]] == 1) {
      printf("%d\n", arr[j]);
    } else {
      while (!(indexes[arr[j]] == 1)) {
        j++;
        if (j > i) {
          printf("-1\n");
          break;
        }
      }
      if (j <= i) {
        printf("%d\n", arr[j]);
      }
    }
  }
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
