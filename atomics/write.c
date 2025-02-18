#include <omp.h>
#include <stdio.h>

#define N 4

int main() {
  int arr[4] = {10, 10, 10, 10};
  int sum = 0;

#pragma omp parallel for
  for (int i = 0; i < N; i++) {

#pragma omp atomic write
    sum = sum + arr[i];
  }

  printf("Sum: %d\n", sum);
}
