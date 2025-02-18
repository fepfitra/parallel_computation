#include <omp.h>
#include <stdio.h>

int main() {
  int count = 0;

#pragma omp parallel num_threads(4)
  {

#pragma omp atomic update
    count++;
  }

  printf("Count: %d\n", count);
}
