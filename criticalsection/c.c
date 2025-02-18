#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main() {
  int i;
  int max;
  int a[SIZE];
  for (i = 0; i < SIZE; i++) {
    a[i] = rand();
    printf("a[%d] = %d\n", i, a[i]);
  }
  max = a[0];

#pragma omp parallel for
  for (i = 1; i < SIZE; i++) {
    if (a[i] > max) {

#pragma omp critical
      {
        if (a[i] > max) {
          max = a[i];
        }
      }
    }
  }

  printf("Max: %d\n", max);
  return 0;
}
