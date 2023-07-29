//write a program to find the root on non-linear equation using NewtonRapson method
#include<stdio.h>
#include<math.h>
#define MAX 20
#define E 0.0001
#define f(x) (exp(x)-x-2)
#define f1(x) (exp(x)-1)
int main()
{
    int count=1;
    float x0,x1;
    printf("Enter initial guess value:");
    scanf("%f",&x0);
    if(f1(x0)==0)
        printf("\nDerivative zero at initial guess\n");
    else
    {
        begin:
        x1=x0-(f(x0)/f1(x0));
        if(fabs((x1-x0)/x1)<E){
            printf("The root is %f",x1);
            printf("\n No if iteration is %d",count);
        }
        else
        {
            x0=x1;
            count++;

            if(count<MAX)
                goto begin;

            else
                printf("The process doesnt converge");
        }
    }
    return 0;
}

/* OUTPUT: */

/* ./bisection */
/* Enter initial guess x1 and x2 */
/* 5 6 */
/* The root is 5.741657 */
/* No. of iteration is 17% */
