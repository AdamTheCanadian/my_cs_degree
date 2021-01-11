#include <stdio.h>
#include <stdlib.h>

/* Function to swap position of elements */
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

/* Partition the array on the basis of pivot element */
int partition(int array[], int low, int high) {
  /* Select the pivot element */
  int pivot = array[high];
  int i = (low - 1);

  /* Put the elements smaller than pivot on the left and greater than pivot on the right of pivot */
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    /* Select pivot position and put all the elements smaller than pivot 
      on left and greater than pivot on right */
    int pivot = partition(array, low, high);
    
    /* Sort the elements on the left of pivot */
    quickSort(array, low, pivot - 1);
    
    /* Sort the elements on the right of pivot */
    quickSort(array, pivot + 1, high);
  }
}

int main() {
  int n = 1000;
  int data[n];
  for (int i = 0; i < n; i++) {
    data[i] = rand();
  }
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  for (int i = 0; i < n; i++) {
    printf("\t%i\n", data[i]);
  }
}