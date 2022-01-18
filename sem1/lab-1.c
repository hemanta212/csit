
// EVEN OR ODD
#include <stdio.h>

int main(void){
  int n;
  printf("Type a number: ");
  scanf("%d", &n);
  if (n % 2 == 0)
    printf("The number is even\n");
  else
    printf("the number is odd\n");

  return 0;
}

// Number reverser
#include <stdio.h>

int main(void){
  int n;
  printf("Type a number: ");
  scanf("%d", &n);

  while(n != 0){
    printf("%d", n%10);
    n /= 10;
  }
  printf("\n");
  return 0;
}

// Sum of digits finder
#include <stdio.h>

int main(void){
  int n, sum=0;
  printf("Type a number: ");
  scanf("%d", &n);
  while(n != 0){
    sum+=n%10;
    n /= 10;
  }
  printf("%d\n", sum);
  return 0;
}

// Prime or composite tester
#include <stdio.h>

int main(void) {
  int n, isComposite = 0;
  printf("Type a number: ");
  scanf("%d", &n);

  if (n < 2) {
    printf("Invalid input n muste be >= 2");
  }

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      isComposite = 1;
      break;
    }
  }
  if (isComposite)
    printf("The number is composite\n");
  else
    printf("The number is prime\n");
  return 0;
}

// Priems from 200 to 300
#include <stdio.h>

#define MIN 200
#define MAX 300

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


// Roots of quadratic equations
#include <stdio.h>
#include <math.h>

int main(void){
  int A, B, C;
  printf("Type values for A B C: ");
  scanf("%d %d %d", &A, &B, &C);
 
  float det = B*B - 4*A*C;
  if (det < 0){
    printf("Imaginary roots: not supported\n");
    return 1;
  }

  float root1 = (-B + sqrt(det))/(2*A);
  float root2 = (-B - sqrt(det))/(2*A);
  printf("the two roots are : %.2f and %.2f\n", root1, root2);
  return 0;
}

// GCD finder
#include <stdio.h>

int main(void){
  int A, B;
  printf("Type two numbers A B: ");
  scanf("%d %d", &A, &B);
 
  int lowest = A;
  if (B < A)
    lowest = B;

  int hcf;
  for(int i=1; i<=lowest; i++){
    if (B % i == 0 && A % i == 0)
      hcf = i;
  }
  printf("The GCD of %d and %d is %d\n", A, B, hcf);
  return 0;
}


// LCM finder
#include <stdio.h>

int main(void){
  int A, B;
  printf("Type two numbers A B: ");
  scanf("%d %d", &A, &B);

  if(A <= 0 || B <= 0){
    printf("Invalid input A or B equals 0 or less\n");
    return 1;
  }
 
  int lcm, i=A;
  while(1){
    if (i % A == 0 && i % B == 0){
      lcm = i;
      break;
    }
    i++;
  }
  printf("The LCM of %d and %d is %d\n", A, B, lcm);
  return 0;
}


// Ladder pattern
#include <stdio.h>

int main(void){
  int width = 6, height = 4;
  for(int i = 0; i < height; i++){
    int spaces = (width/2);
    int stars = 6 - width;
    // beginning spaces
    for (int j = 0; j < spaces; j++)
      printf(" ");
    
    for(int k=0; k<=stars; k++)
      printf("*");
    
    // after spaces
    for (int j = 0; j < spaces; j++)
      printf(" ");
    printf("\n");
    width-=2;
  }
  return 0;
}


// Number ladder
#include <stdio.h>

int main(void){
  for(int i=1; i<=5; i++){
    for(int j=1; j<=i; j++){
      printf("%d", j);
    }
  printf("\n");
}
  return 0;
}
