#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Searches for searchNum in an array arr of size n.
  Returns 0 if unable to find it, 1 otherwise.
  Sets index of searchNum to idx
*/
int binary_search(int* arr, uint64_t n, uint64_t searchNum, uint64_t* idx, uint64_t* steps) {
  uint64_t low = 0;
  uint64_t high = n - 1;
  *steps = 0;
  uint64_t cnt = 0;
  while (low <= high) {
    /* Get the middle index */
    uint64_t mid = low + (high - 1) / 2;
    /* Get the value at the middle index */
    uint64_t guess = arr[mid];
    cnt += 1;
    if (guess == searchNum) {
      *idx = mid;
      printf("cnt %lld\n", cnt);
      return 1;
    }
    if (guess > searchNum) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Not enough input arguments\n");
    printf("./binary_search arr_size search_num\n");
    printf("./binary_search 1024 10\n");
    return 0;
  }
  /* Convert input arguments into integers */
  char* s = argv[1];
  uint64_t n = atoll(s);
  int arr[n];
  s = argv[2];
  uint64_t desired_num = atoll(s);
  printf("Searching for %lld in an array of size %lld\n", desired_num, n);
  /* Initialize array */
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  uint64_t idx = 0, steps = 0;
  if (binary_search(arr, n, desired_num, &idx, &steps) == 1) {
    printf("Found value %lld at index %lld and it took %lld steps\n", desired_num, idx, steps);
  }
  else {
    printf("Could not find value %lld\n", desired_num);
  }
  return 1;
}