// Sieve of eratoethense
// Simple NLogN function to compute prime numbers till 10k

#include <stdio.h>

#define N 10000

int main() {
  int array[N];
  // set every array elements to 1 (label as prime)
  for (int i = 0; i < N; i++)
    array[i] = 1;

  // Start from 2 till N
  for (int i = 2; i < N; i++)
    // Process only elems labelled as prime
    if (array[i])
      // find every multiple of the number till N, set it to 0 (label as
      // nonprime)
      for (int j = i; (i * j) < N; j++)
        array[i * j] = 0;

  // Output all the prime labelled nums
  for (int i = 2; i < N; i++)
    if (array[i])
      printf("%d\n", i);
}
