// 8 Ascol Seqence
#include <stdio.h>

int isAscolSequence(int seq[]);
int main(void) {
  int seq[] = {16, 8, 4, 2, 1};
  int result = isAscolSequence(seq);
  if (result == 1) {
    printf("Yes, it is ascol sequence");
  } else {
    printf("No, not ascol sequence");
  }
  return 0;
}

int isAscolSequence(int seq[]) {
  int index = 0;
  int n = seq[index];
  index++;

  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = n * 3 + 1;
    }
    if (n != seq[index]) {
      return 0;
    }
    index++;
  }
  return 1;
}


// 9 repsEqual array digit test
#include <stdio.h>

int repsEqual(int given_arr[], int number);
int main(void) {
  int seq[] = {4, 2, 1};
  int result = repsEqual(seq, 421);
  if (result == 1) {
    printf("Yes, array contain digits in same order");
  } else {
    printf("No, array doesnot contain digits in same order");
  }
  return 0;
}

int repsEqual(int given_arr[], int number) {
  // Break given number to correct array
  int number_arr[100];
  int digit_no = 0;
  while (number != 0) {
    int l_digit = number % 10;
    number_arr[digit_no++] = l_digit;
    number /= 10;
  }
  // loop and check resp index of both correct and given array
  // scan number_array from last as it is reverse order because of % mod stuff
  for (int front = 0, last = digit_no - 1; front < digit_no; front++, last--) {
    if (given_arr[front] != number_arr[last])
      return 0;
  }
  return 1;
}


// 10 Max and min size
#include <stdio.h>
#include <stdlib.h>

void maxAndMinSize(int a, int b);

int main(void) {
  maxAndMinSize(3, 4);
  maxAndMinSize(10, 5);
  return 0;
}

void maxAndMinSize(int a, int b) {
  int max = a + b - 1;
  int min = abs(a - b) + 1;
  printf("Maximum Side length is : %d\n", max);
  printf("Minimum Side length is : %d\n", min);
}



// 1 a: Find product of two numbers using recursive function
#include <stdio.h>

int find_product(int a, int b);

int main(void) {
  int a;
  int b;
  printf("Input two numbers: ");
  scanf("%d %d", &a, &b);

  int product = find_product(a, b);
  printf("The product is %d\n", product);
  return 0;
}

int find_product(int a, int b) {
  if (b == 0)
    return 0;
  return a + find_product(a, b - 1);
}

// 1: b : Fidn nth fibonnaci numbers
#include <stdio.h>

int find_nth_fib(int sum, int last_sum, int n);

int main(void) {
  int n;
  printf("Input the nth term: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("Invalid, Given n >= 1\n");
    return 1;
  }

  int nth_fib = find_nth_fib(0, 1, n);
  printf("%d\n", nth_fib);
  return 0;
}

int find_nth_fib(int sum, int last_sum, int n) {
  if (n == 1)
    return sum;
  else if (n == 2)
    return sum + last_sum;
  return find_nth_fib(sum + last_sum, sum, n - 1);
}

// 1 c : Find sum of digits of number
#include <stdio.h>

int get_sum_of_digits(int n);

int main(void) {
  int n;
  printf("Input a digit: ");
  scanf("%d", &n);

  int sum = get_sum_of_digits(n);
  printf("The sum of digits of %d is %d\n", n, sum);
  return 0;
}

int get_sum_of_digits(int n) {
  if (n == 0)
    return 0;
  return n % 10 + get_sum_of_digits(n / 10);
}

// 1 d: Reverse of number using recursive function
#include <stdio.h>

int get_reverse_number(int rev, int n);
int main(void) {
  int n;
  printf("Input a digit: ");
  scanf("%d", &n);

  int reverse = get_reverse_number(0, n);
  printf("The reverse of %d is %d\n", n, reverse);
  return 0;
}

int get_reverse_number(int rev, int n) {
  if (n == 0) {
    return rev;
  }
  int l_digit = n % 10;
  return get_reverse_number(rev * 10 + l_digit, n / 10);
}

// 1 e: Prime number printer
#include <stdio.h>

int is_prime(int n, int divider);
void print_primes(int low, int high);
int main(void) {
  print_primes(200, 300);
  return 0;
}

void print_primes(int low, int high) {
  if (low == high)
    return;

  if (is_prime(high, high / 2) == 1)
    printf("%d\n", high);
  print_primes(low, high - 1);
}

int is_prime(int n, int divider) {
  if (divider == 1) {
    return 1;
  }
  if (n % divider == 0) {
    return 0;
  }
  return is_prime(n, divider - 1);
}

// 4 Matrix sum and product
#include <stdio.h>

void input_matrix(int I[3][3]);
void print_matrix(int I[3][3]);
int get_matrix_product(int A[3][3], int B[3][3], int i, int j);

int main(void) {
  int A[3][3], B[3][3], sum[3][3], product[3][3];

  printf("Input 1st 3x3 matrix A: \n");
  input_matrix(A);
  printf("Input 2nd 3x3 matrix B: \n");
  input_matrix(B);

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      sum[i][j] = A[i][j] + B[i][j];
      product[i][j] = get_matrix_product(A, B, i, j);
    }

  printf("Sum of given two matrix is:\n");
  print_matrix(sum);
  printf("Product of given two matrix is:\n");
  print_matrix(product);
  return 0;
}

void input_matrix(int I[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &I[i][j]);
  }
}

void print_matrix(int I[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d ", I[i][j]);
    printf("\n");
  }
}

int get_matrix_product(int A[3][3], int B[3][3], int i, int j) {
  return A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j];
}

// 5 Quadratic solver
#include <math.h>
#include <stdio.h>

void get_roots(int det, int a, int b, double roots[]);
int main(void) {
  int a, b, c;
  double roots[2];

  printf("Input a b c: ");
  scanf(" %d %d %d", &a, &b, &c);

  double det = pow(b, 2) - 4 * a * c;
  if (det < 0) {
    printf("Imaginary answer\n");
    return 1;
  }

  get_roots(det, a, b, roots);

  int first = 0, second = 1;
  printf("Roots are : %.2f, %.2f\n", roots[first], roots[second]);
  return 0;
}

void get_roots(int det, int a, int b, double roots[]) {
  double first_root = (-b + sqrt(det)) / (2 * a);
  double second_root = (-b - sqrt(det)) / (2 * a);
  roots[0] = first_root;
  roots[1] = second_root;
}

// 6. Recursive Array printer
#include <stdio.h>
#define N 5

void print_array(int array[], int index);

int main(void) {
  int arr[N];
  printf("Input %d Numbers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  print_array(arr, N - 1);
  return 0;
}

void print_array(int array[], int index) {
  if (index == -1)
    return;

  print_array(array, index - 1);
  printf("%d ", array[index]);
}


7 DeciToBin function
#include <stdio.h>

int deciToBin(int decimal);
int main(void) {
  int decimal = 15;
  int binary = deciToBin(decimal);
  printf("%d", binary);
  return 0;
}

int deciToBin(int decimal) {
  int bin = 0, factor = 1;
  while (decimal != 0) {
    int l_digit = decimal % 2;
    bin += l_digit * factor;
    factor *= 10;
    decimal /= 2;
  }
  return bin;
}


