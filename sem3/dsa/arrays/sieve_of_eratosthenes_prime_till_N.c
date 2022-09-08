// Sieve of eratoethense
// Simple NLogN function to compute prime numbers till 10k

#include <stdio.h>
#include <stdlib.h>

int *gen_array(char *argv[]);

int main(int argc, char *argv[]) {
  fprintf(stdin, "%d", argc);
  unsigned long long N = atoi(argv[1]);
  unsigned long long *array = malloc(sizeof(unsigned long long) * N);
  if (array == NULL) {
    printf("Insufficient memory\n");
    return -1;
  }
  // set every array elements to 1 (label as prime)
  for (unsigned long long i = 0; i < N; i++)
    array[i] = 1;

  // Start from 2 till N
  for (unsigned long long i = 2; i < N; i++)
    // Process only elems labelled as prime
    if (array[i])
      // find every multiple of the number till N, set it to 0 (label as
      // nonprime)
      for (unsigned long long j = i; (i * j) < N; j++)
        array[i * j] = 0;

  // Output all the prime labelled nums
  for (unsigned long long i = 2; i < N; i++)
    if (array[i])
      printf("%llu\n", i);
}
