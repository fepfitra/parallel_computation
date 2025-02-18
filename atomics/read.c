#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define n 4

int main() {
  int maximum = 0;
  int z[n];

  printf("Array: ");

  for (int i = 0; i < n; i++) {
    z[i] = rand();
    printf("%d ", z[i]);
  }

#pragma omp parallel for
  for (int j = 0; j < n; j++) {
    if (z[j] > maximum) {

#pragma omp atomic read
      maximum = z[j];
    }
  }
  printf("\nMax: %d\n", maximum);
}
