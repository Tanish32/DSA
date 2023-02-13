#include <stdio.h>
#include <stdlib.h>
int numComparisions(int mid, int numElements, int totalComparisions) {
  int index = numElements - mid - 1;
  int comparisions = totalComparisions - ((index * (index - 1)) / 2);
  return comparisions;
}
int main() {
  int numElements = 0;
  scanf("%d", &numElements);
  int totalComparisons = (numElements * (numElements - 1)) / 2;
  int target = totalComparisons / 2;
  int left = 0, right = numElements - 1, mid = 0, result = 0;
  while (left != right) {
    mid = (left + right) / 2;
    if (numComparisions(mid, numElements, totalComparisons) < target) {
      left = mid + 1;
    } else if (numComparisions(mid, numElements, totalComparisons) > target) {
      right = mid;
      result = mid;
    } else if (numComparisions(mid, numElements, totalComparisons) == target) {
      printf("Number found ");
      break;
    }
  }
  printf("%d", result + 1);
  return 0;
}
