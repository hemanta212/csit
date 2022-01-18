// Max min in 10 numbers
# include <stdio.h>

#define SIZE 3

int main(void){
  printf("Input 10 numbers: ");
  int nums[SIZE];
  for (int i = 0; i < SIZE; i++) {
    scanf(" %d", &nums[i]);
  }

  int max=nums[0], min=nums[0];
  for(int i=0; i<SIZE; i++){
    if (nums[i] > max)
      max = nums[i];
    else if (nums[i] < min)
      min = nums[i];
  }
  printf("Maximum: %d\nMinimum: %d\n",max, min);
  return 0;
}




// Addition of 20 numbers
# include <stdio.h>

#define SIZE 20

int main(void){
  printf("Input 20 numbers: ");
  int nums[SIZE];
  for (int i = 0; i < SIZE; i++) {
    scanf(" %d", &nums[i]);
  }

  int sum = 0;
  for(int i=0; i<SIZE; i++){
    sum += nums[i];
  }
  printf("The sum of numbers is %d", sum);

  return 0;
}






// Ascending sort
#include <stdio.h>

#define SIZE 10

int main(void) {
  printf("Input 3 numbers: ");
  int nums[SIZE];
  for (int i = 0; i < SIZE; i++) {
    scanf(" %d", &nums[i]);
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (nums[i] < nums[j]) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
  }
  for(int i=0; i<SIZE; i++){
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}






// sum and product of matrices
#include <stdio.h>

#define SIZE 3

void get_input_matrix(int I[SIZE][SIZE]) {
  printf("Input 3x3 matrix: \n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      scanf(" %d", &I[i][j]);
    }
  }
}

void print_matrix(int M[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int A[SIZE][SIZE], B[SIZE][SIZE], sum[SIZE][SIZE], product[SIZE][SIZE];
  get_input_matrix(A);
  get_input_matrix(B);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      sum[i][j] = A[i][j] + B[i][j];
      product[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] *
B[2][j];
    }
  }
  printf("The sum of the two matrix is \n");
  print_matrix(sum);
  printf("The product of the two matrix is \n");
  print_matrix(product);
  return 0;
}




// Palindrome or not
#include <stdio.h>

int main(void) {
  printf("Input a string: ");
  char str[100];
  scanf(" %s", str);

  int len = 0, isPalindrome = 1;
  for (int i = 0; str[i] != '\0'; i++, len++);
  /* printf("Got len %d\n", len); */

  for (int i = 0, j = len - 1; i <= len / 2; i++, j--) {
    /* printf("Comparing %c and %c\n", str[i], str[j]); */
    if (str[i] != str[j]) {
      isPalindrome = 0;
      break;
    }
  }
  if (isPalindrome) {
    printf("The given string %s is a palindrome\n", str);
  } else {
    printf("The given string %s is not a palindrome\n", str);
  }
  return 0;
}




// factorial using recursion
# include <stdio.h>

int factorial(int n){
  if(n == 0){
    return 1;
  }
  return n * factorial(n-1);
}

int main(void){
  printf("Input a number: ");
  int n;
  scanf(" %d", &n);

  int f = factorial(n);
  printf("The factorial of %d is %d", n, f);
  return 0;
}




// sum using recursion
# include <stdio.h>

int sum_of_digits(int n){
  if (n == 0){
    return 0;
  }
  return n%10 + sum_of_digits(n/10);
}

int main(void){
  printf("Input a number: ");
  int n;
  scanf(" %d", &n);

  int sum_digits = sum_of_digits(n);
  printf("the sum of digits in %d is %d", n, sum_digits);
  return 0;
}




// multiply using recursion
# include <stdio.h>

int mult(const int m, int n){
  if (n == 0){
    return 0;
  }
  else{
    return m + mult(m, n-1);
  }
}

int main(void){
  printf("Input two numbers A B: ");
  int m, n;
  scanf(" %d %d", &m, &n);

  int product = mult(m, n);
  printf("The product of %d and %d is %d\n", m, n, product);
  return 0;
}




// nth fib number
#include <stdio.h>

int fib(int n){
  if (n == 1){
    return 0;
  }else if (n == 2){
    return 1;
  }else{
    return fib(n-1)+fib(n-2);
  }
}

int main(void){
  printf("Input n for nth term: ");
  int n;
  scanf(" %d", &n);

  if (n <= 0){
    printf("Invalid input: must be greater than 0\n");
    return 1;
  }
  int nth_fib = fib(n);
  printf("The %dth fibonacci number is %d", n, nth_fib);
  return 0;
}


// Primes from 200 to 500
#include <stdio.h>

#define MIN 200
#define MAX 500

int isPrime(int n){
  int isComposite = 0;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      isComposite = 1;
      break;
    }
  }
  if (isComposite)
    return 0;
  else
    return 1;
}

int main(void){
  for(int i=MIN; i<=MAX; i++){
    if(isPrime(i))
      printf("%d\n", i);
  }
  return 0;
}
