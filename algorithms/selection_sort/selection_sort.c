#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

/* 
  Sort an array arr of size n
  Start at element [0], and go from element [0 + 1] to [n] and find the minimum
  element. Swap it to element [0]. Repeat starting at element [1]
*/
void selection_sort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      /* Check if we have a new minimum */
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    /* Swap the current element i with the minimum found */
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

int main(int argc, char* argv[]) {
  int n = 20;
  int arr[n];
  printf("Sorting an array size of %d\n", n);
  /* Initialize array */
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
  }
  printf("Array before sorting: \n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  selection_sort(arr, n);
  printf("Array after sorting: \n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 1;
}