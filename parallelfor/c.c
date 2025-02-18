#include <omp.h>
#include <stdio.h>

int main() {
  int i, sum = 0;
  int thread_sum[4];

  omp_set_num_threads(4);

#pragma omp parallel
  {
    int ID = omp_get_thread_num();
    thread_sum[ID] = 0;

#pragma omp for
    for (i = 0; i < 100; i++) {
      thread_sum[ID] += i;
    }
  }

  for (i = 0; i < 4; i++) {
    sum += thread_sum[i];
    printf("Thread %d: %d\n", i, thread_sum[i]);
  }
  printf("Sum: %d\n", sum);
  return 1;
};
