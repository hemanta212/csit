/* 1. I counter */
#include <stdio.h>

int main(void) {
  char input[100];
  printf("Input a string: ");
  fgets(input, 100, stdin);

  int i_count = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == 'I') {
      i_count++;
    }
  }
  printf("Char 'I' occurs %d times in %s", i_count, input);
}

/* 2.SUME AND PRODUCT 3x3 MATRIX */
#include <stdio.h>

int main(void) {
  int A[3][3];
  int B[3][3];

  printf("Input 1st 3x3 matrix A: \n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &A[i][j]);
  }

  printf("Input 2nd 3x3 matrix B: \n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &B[i][j]);
  }
  printf("\n");

  printf("Sum of given two matrix is:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d ", A[i][j] + B[i][j]);
    printf("\n");
  }

  printf("Product of given two matrix is:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int product = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j];
      printf("%d ", product);
    }
    printf("\n");
  }
  return 0;
}

/* 3. PALINDROME OR NOT? */
#include <ctype.h>
#include <stdio.h>

int main(void) {
  char input[100];
  printf("Input a string: ");
  scanf("%s", input);

  int input_len;
  while (input[input_len] != '\0')
    input_len++;

  int is_palindrome = 1;
  for (int i = 0; i <= input_len / 2; i++) {
    char one_end_char = tolower(input[i]);
    char other_end_char = tolower(input[input_len - 1 - i]);
    if (one_end_char != other_end_char)
      is_palindrome = 0;
  }

  if (is_palindrome == 1)
    printf("The string %s is a palindrome\n", input);
  else
    printf("The string %s is not a palindrome\n", input);
}

/* 4. MATRIX diagnol and non diagnol sum*/
#include <stdio.h>

int main(void) {
  int A[3][3];
  printf("Input a 3x3 matrix: \n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &A[i][j]);
  }
  printf("\n");

  int diagonal_sum = 0;
  int non_diagonal_sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j)
        diagonal_sum += A[i][j];
      else
        non_diagonal_sum += A[i][j];
    }
  }
  printf("The Diagonal Sum is : %d\n", diagonal_sum);
  printf("The Non Diagonal Sum is : %d\n", non_diagonal_sum);
  return 0;
}

/* 5. ARRAY Largest and smalleest element */
#include <stdio.h>

#define N 10

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  int largest = arr[0], smallest = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] > largest)
      largest = arr[i];
    if (arr[i] < smallest)
      smallest = arr[i];
  }
  printf("The largest number is: %d\n", largest);
  printf("The smallest number is: %d\n", smallest);
  return 0;
}

/* 6. PRIME NUMBER FINDER*/
#include <math.h>
#include <stdio.h>

#define N 10

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  printf("Prime numbers are: ");
  for (int i = 0; i < N; i++) {
    if (arr[i] == 0 || arr[i] == 1)
      continue;

    int is_prime = 1;
    int root = sqrt(arr[i]);
    for (int j = 2; j <= root; j++) {
      if (arr[i] % j == 0)
        is_prime = 0;
    }
    if (is_prime == 1)
      printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

/* 7. ARRAY SORTER */
#include <stdio.h>

#define N 10

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }

  printf("Ascending Order: ");
  for (int i = 0; i < N; i++)
    printf("%d ", arr[i]);

  printf("\n");
  return 0;
}

/* 8. TWIN PRIMES */
#include <math.h>
#include <stdio.h>

#define N 10

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  int primes[N], prime_count = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] == 0 || arr[i] == 1)
      continue;

    int is_prime = 1;
    int root = sqrt(arr[i]);
    for (int j = 2; j <= root; j++) {
      if (arr[i] % j == 0)
        is_prime = 0;
    }
    if (is_prime == 1)
      primes[prime_count++] = arr[i];
  }

  int has_twin = 0;
  for (int i = 0; i < prime_count; i++) {
    for (int j = 0; j < prime_count; j++) {
      int difference = primes[j] - primes[i];
      if (difference > 0 && difference <= 2) {
        has_twin = 1;
        printf("Twin primes: %d %d\n", primes[i], primes[j]);
      }
    }
  }
  if (has_twin == 0)
    printf("No twin primes found!\n");

  return 0;
}

/* 9.  ISALLPOSISBLITIES */
#include <stdio.h>

#define N 5

int isAllPossibilities(int arr[N]);

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);
  if (isAllPossibilities(arr))
    printf("The given array is an array of all possibility\n");
  else
    printf("The given array is not an array of all possibility\n");
}

int isAllPossibilities(int arr[N]) {
  for (int i = 0; i < N; i++) {
    int contains_i = 0;
    for (int j = 0; j < N; j++) {
      if (arr[j] == i)
        contains_i = 1;
    }
    if (contains_i == 0) {
      return 0;
    }
  }
  return 1;
}

/* 10. ODD HEAVY*/
/* Principle just compare smallest odd with largest even if true its ood heavy
 */
#include <stdio.h>

#define N 5

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  int smallest_odd = 0; // -1 represtents unset condition
  int largest_even = 0;

  for (int i = 0; i < N; i++) {
    if (arr[i] == 0)
      continue;

    if (arr[i] % 2 == 0) {
      if (arr[i] > largest_even)
        largest_even = arr[i];
    } else if (smallest_odd == 0 || arr[i] < smallest_odd)
      smallest_odd = arr[i];
  }

  printf("%d %d\n", smallest_odd, largest_even);

  if (smallest_odd > largest_even)
    printf("The given array is odd-dominant.\n");
  else
    printf("The given array is not odd-dominant.\n");
}
