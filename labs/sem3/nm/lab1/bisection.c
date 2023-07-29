/* Q.no : 1 Write a program to find the root of non-linear equation using bisection method. */

#include <math.h>
#include <stdio.h>
#define f(x) (x * x - 4 * x - 10)
#define e 0.00001
#define MAX 20
    int
    main() {
  float x0, x1, x2;
  printf("Enter initial guess x1 and x2\n");
  scanf("%f%f", &x1, &x2);
  if (f(x1) * f(x2) > 0) {
    printf("The guess value don\'t bracket root.");
    return 1;
  }
  int count = 0;
  while (1) {
    x0 = (x1 + x2) / 2;
    if (fabs(f(x0)) < e) {
      printf("The root is %f\n", x0);
      printf("No. of iteration is %d", count);
      return 0;
    }
    if (f(x0) > 0)
      x2 = x0;
    else if (f(x0) < 0)
      x1 = x0;
    count++;
    if (count > MAX) {
      printf("The process doesn\'t converge\n");
      return 1;
    }
  }
}


/* OUTPUT: */

/* ./bisection */
/* Enter initial guess x1 and x2 */
/* 5 6 */
/* The root is 5.741657 */
/* No. of iteration is 17% */
