#include <omp.h>
#include <stdio.h>

#define N 4

int main() {
  int count = 0, k;
#pragma omp parallel num_threads(N)
  {

#pragma omp atomic capture
    k = count++;
  }
  printf("Count: %d\n", count);
}
