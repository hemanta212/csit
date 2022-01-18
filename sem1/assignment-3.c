// 7 DeciToBin function
#include <stdio.h>

int deciToBin(int decimal);
int main(void) {
  printf("Give me decimal: ");
  int decimal;
  scanf("%d", &decimal);

  int bin = deciToBin(decimal);
  printf("The binary form of %d is %d\n", decimal, bin);
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

// 10 Max and min size
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* void maxAndMinSize(int a, int b); */
/* int main(void){ */
/*   maxAndMinSize(3, 4); */
/*   maxAndMinSize(2, 10); */
/*   maxAndMinSize(5, 10); */
/*   maxAndMinSize(2, 100); */
/*   return 0; */
/* } */

/* void maxAndMinSize(int a, int b){ */
/*   int max = a + b - 1;  */
/*   int min = abs(a - b) + 1; */
/*   printf("Maximum Side length is : %d\n", max); */
/*   printf("Minimum Side length is : %d\n", min); */
/* } */

// 9 repsEqual array digit test
/* #include <stdio.h> */

/* void p_arr(int arr[], int len); */
/* int break_to_array(int number, int arr[]); */
/* int repsEqual(int given_arr[], int number); */

/* int main(void){ */
/*   printf("Input a number: "); */
/*   int number; */
/*   scanf("%d", &number); */

/*   int correct_arr[100]; */
/*   int digit_no = break_to_array(number, correct_arr); */
/*   p_arr(correct_arr, digit_no); */

/*   printf("Input an array: "); */
/*   int given_arr[100]; */
/*   for (int i=0; i<digit_no; i++){ */
/*     scanf("%d", &given_arr[i]); */
/*   } */

/*   if(repsEqual(given_arr, number)){ */
/*     printf("Yes, array contains number digits in same order\n"); */
/*   } */
/*   else{ */
/*     printf("No, array doesnot have digits in same order\n"); */
/*   } */
/*   return 0; */
/* } */

/* int repsEqual(int given_arr[], int number){ */
/*   // Break given number to correct array */
/*   int number_arr[100]; */
/*   int digit_no = 0; */
/*   while(number!=0){ */
/*     int l_digit = number %10; */
/*     number_arr[digit_no++] = l_digit; */
/*     number /= 10; */
/*   } */
/*   p_arr(number_arr, digit_no); */

/*   // loop and check resp index of both correct and given array */
/*   // scan number_array from last beacuse it is reverse order because of % mod
 * stuff */
/*   for (int front = 0, last = digit_no-1; front<digit_no; front++, last--){ */
/*     printf("Comparing %d %d at %d\n", given_arr[front], number_arr[last],
 * digit_no); */
/*     if(given_arr[front] != number_arr[last]) */
/*       return 0; */
/*   } */
/*   return 1; */
/* } */

/* int break_to_array(int number, int arr[]){ */
/*   int index = 0; */
/*   while(number!=0){ */
/*     int l_digit = number %10; */
/*     arr[index++] = l_digit; */
/*     number /= 10; */
/*   } */
/*   return index; */
/* } */
/* void p_arr(int arr[], int len){ */
/*   for(int i =0; i<len; i++){ */
/*     printf("%d ", arr[i]); */
/*   } */
/*   puts(""); */
/* } */

// 8 Ascol Seqence
/* #include <stdio.h> */

/* int gen_ascol_seq(unsigned int n, int ascol_seq[]); */
/* int isAscolSequence(int seq[]); */

/* int main(void){ */
/*   printf("Input a positive number n: "); */
/*   unsigned int n; */
/*   scanf("%u", &n); */

/*   int ascol_seq[100]; */
/*   int size = gen_ascol_seq(n, ascol_seq); */

/*   if(isAscolSequence(ascol_seq)){ */
/*     printf("Yes it is an ascol sequence"); */
/*   } */
/*   else{ */
/*     printf("No it is not an ascol sequence"); */
/*   } */

/*   return 0; */
/* } */

/* int gen_ascol_seq(unsigned int n, int ascol_seq[]){ */
/*   int index = 0; */
/*   ascol_seq[index] = n; */
/*   index++; */

/*   while(n != 1){ */
/*     // if even */
/*     if(n %2 == 0){ */
/*       n /= 2; */
/*       ascol_seq[index++] = n; */
/*     } */
/*     // if odd */
/*     else{ */
/*       n = n * 3 + 1; */
/*       ascol_seq[index++] = n; */
/*     } */
/*   } */
/*   return index; */
/* } */

/* int isAscolSequence(int seq[]){ */
/*   int index = 0; */
/*   int n = seq[index]; */
/*   index++; */

/*   while(n!=1){ */
/*     if (n % 2 == 0){ */
/*       n = n/2; */
/*     } */
/*     else{ */
/*       n = n*3+1; */
/*     } */
/*     if(n != seq[index]){ */
/*       return 0; */
/*     } */
/*     index++; */
/*   } */
/*   return 1; */
/* } */

// 5
// 6. Recursive Array printer
/* #include <stdio.h> */

/* #define N 5 */

/* void print_array(int array[], int index); */

/* int main(void){ */
/*   int arr[N]; */
/*   printf("Input %d Numbers: ", N); */
/*   for (int i = 0; i < N; i++) { */
/*     scanf("%d", &arr[i]); */
/*   } */
/*   print_array(arr, N-1); */
/*   return 0; */
/* } */

/* void print_array(int array[], int index) { */
/*   if (index == -1) */
/*     return; */
  
/*   printf("%d ", array[index]); */
/*   print_array(array, index-1); */
/* } */

// 5 Quadratic solver
/* #include <math.h> */
/* #include <stdio.h> */

/* void get_roots(int det, int a, int b, double roots[]); */
/* int main(void) { */
/*   int a, b, c; */
/*   double roots[2]; */

/*   printf("Input a b c: "); */
/*   scanf(" %d %d %d", &a, &b, &c); */

/*   double det = pow(b, 2) - 4 * a * c; */
/*   if (det < 0) { */
/*     printf("Imaginary answer\n"); */
/*     return 1; */
/*   } */

/*   get_roots(det, a, b, roots); */

/*   int first = 0, second = 1; */
/*   printf("Roots are : %.2f, %.2f\n", roots[first], roots[second]); */
/*   return 0; */
/* } */

/* void get_roots(int det, int a, int b, double roots[]) { */
/*   double first_root = (-b + sqrt(det)) / (2 * a); */
/*   double second_root = (-b - sqrt(det)) / (2 * a); */
/*   roots[0] = first_root; */
/*   roots[1] = second_root; */
/* } */

// 4 Matrix sum and product
/* #include <stdio.h> */

/* void input_matrix(int I[3][3]); */
/* void print_matrix(int I[3][3]); */
/* int get_matrix_product(int A[3][3], int B[3][3], int i, int j); */

/* int main(void) { */
/*   int A[3][3], B[3][3], sum[3][3], product[3][3]; */

/*   printf("Input 1st 3x3 matrix A: \n"); */
/*   input_matrix(A); */
/*   printf("Input 2nd 3x3 matrix B: \n"); */
/*   input_matrix(B); */

/*   for (int i = 0; i < 3; i++) */
/*     for (int j = 0; j < 3; j++) { */
/*       sum[i][j] = A[i][j] + B[i][j]; */
/*       product[i][j] = get_matrix_product(A, B, i, j); */
/*     } */

/*   printf("Sum of given two matrix is:\n"); */
/*   print_matrix(sum); */
/*   printf("Product of given two matrix is:\n"); */
/*   print_matrix(product); */
/*   return 0; */
/* } */

/* void input_matrix(int I[3][3]) { */
/*   for (int i = 0; i < 3; i++) { */
/*     for (int j = 0; j < 3; j++) */
/*       scanf("%d", &I[i][j]); */
/*   } */
/* } */

/* void print_matrix(int I[3][3]) { */
/*   for (int i = 0; i < 3; i++) { */
/*     for (int j = 0; j < 3; j++) */
/*       printf("%d ", I[i][j]); */
/*     printf("\n"); */
/*   } */
/* } */

/* int get_matrix_product(int A[3][3], int B[3][3], int i, int j) { */
/*   return A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j]; */
/* } */

// 1 e: Prime number printer
/* #include <stdio.h> */

/* int is_prime(int n, int divider); */
/* void print_primes(int low, int high); */
/* int main(void) { */
/*   print_primes(200, 300); */
/*   return 0; */
/* } */

/* void print_primes(int low, int high) { */
/*   if (low == high) */
/*     return; */

/*   if (is_prime(high, high / 2) == 1) */
/*     printf("%d\n", high); */
/*   print_primes(low, high - 1); */
/* } */

/* int is_prime(int n, int divider) { */
/*   if (divider == 1){ */
/*     return 1; */
/*   } */
/*   if (n % divider == 0){ */
/*     return 0; */
/*   } */
/*   return is_prime(n, divider - 1); */
/* } */

// 1 d: Reverse of number using recursive function
/* #include <stdio.h> */

/* int get_reverse_number(int rev, int n); */
/* int main(void) { */
/*   int n; */
/*   printf("Input a digit: "); */
/*   scanf("%d", &n); */

/*   int reverse = get_reverse_number(0, n); */
/*   printf("The reverse of %d is %d\n", n, reverse); */
/*   return 0; */
/* } */

/* int get_reverse_number(int rev, int n) { */
/*   if (n == 0) { */
/*     return rev; */
/*   } */
/*   int l_digit = n % 10; */
/*   return get_reverse_number(rev * 10 + l_digit, n / 10); */
/* } */

// 1 c : Find sum of digits of number
/* #include <stdio.h> */

/* int get_sum_of_digits(int n); */

/* int main(void) { */
/*   int n; */
/*   printf("Input a digit: "); */
/*   scanf("%d", &n); */

/*   int sum = get_sum_of_digits(n); */
/*   printf("The sum of digits of %d is %d\n", n, sum); */
/*   return 0; */
/* } */

/* int get_sum_of_digits(int n){ */
/*   if (n == 0) */
/*     return 0; */
/*   return n%10 + get_sum_of_digits(n/10); */
/* } */

// 1: b : Fidn nth fibonnaci numbers
/* #include <stdio.h> */

/* int find_nth_fib(int sum, int last_sum, int n); */

/* int main(void){ */
/*   int n; */
/*   printf("Input the nth term: "); */
/*   scanf("%d", &n); */
/*   if (n <= 0){ */
/*     printf("Invalid, Given n >= 1\n"); */
/*     return 1; */
/*   } */

/*   int nth_fib = find_nth_fib(0, 1, n); */
/*   printf("%d\n", nth_fib); */
/*   return 0; */
/* } */

/* int find_nth_fib(int sum, int last_sum, int n){ */
/*   if (n == 1) */
/*     return sum; */
/*   else if (n==2) */
/*     return sum + last_sum; */
/*   return find_nth_fib(sum+last_sum, sum, n-1); */
/* } */

// 1 a: Find product of two numbers using recursive function
/* #include <stdio.h> */

/* int find_product(int a, int b); */

/* int main(void){ */
/*   int a; */
/*   int b; */
/*   printf("Input two numbers: "); */
/*   scanf("%d %d", &a, &b); */

/*   int product = find_product(a,b); */
/*   printf("The product is %d\n", product); */
/*   return 0; */
/* } */

/* int find_product(int a, int b){ */
/*   if(b==0) */
/*     return 0; */
/*   return a + find_product(a, b-1); */
/* } */
