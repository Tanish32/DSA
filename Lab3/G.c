#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initializing array
  int nodesNum = 0, target = 0;
  scanf("%d %d", &nodesNum, &target);
  int arr[nodesNum];
  for (int i = 0; i < nodesNum; i++) {
    scanf("%d", &arr[i]);
  }

  // Quesiton logic
  // use biary search:
  int low = 0, high = nodesNum - 1, mid = 0;
  while (low != high) {
    mid = (low + high) / 2;
    if (target < arr[mid]) {
      high = mid - 1;
    } else if (low + 1 == high) {
      printf("\n%d", arr[mid]);
      exit(0);
      break;
    } else if (target > arr[mid]) {
      low = mid;
    } else if (target == arr[mid]) {
      printf("\n%d", arr[mid]);
      break;
    }
  }
  printf("\n%d\n", arr[mid - 1]);
  //   To print the array
}
