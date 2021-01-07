#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

/* 
  Calculate factorial using recursion
*/
unsigned int factorial(unsigned int x) {
  /* Base case */
  if (x == 1) {
    return 1;
  }
  /* Recursive case */
  return x * factorial(x - 1);
}

int main(int argc, char* argv[]) {
  unsigned int n = 3;
  printf("Factorial of %u is %u\n", n, factorial(n));
  return 0;
}