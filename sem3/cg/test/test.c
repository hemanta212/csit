#include<stdio.h>
#include "graphics.h"

// Add documentation comments to the function
// Mid point circle algorithm caclculation function
// Params: center(a,b) and r is radius
void cal(double a, double b, double r)
{
    double x=0, y=r, p;
    putpixel (a, b+r, WHITE);
    putpixel (a, b-r, WHITE);
    putpixel (a-r, b, WHITE);
    putpixel (a+r, b, WHITE);
    p=(5/4)-r;
    while (x<=y)
    {
        if(p<0)
            p+= (2*x)+3;
        else
        {
            p+=(2*(x-y))+5;
            y--;
        }
        x++;
        putpixel (a+x, b+y, WHITE);
        putpixel (a-x, b+y, WHITE);
        putpixel (a+x, b-y, WHITE);
        putpixel (a-x, b-y, WHITE);
        putpixel (a+y, b+x, WHITE);
        putpixel (a+y, b-x, WHITE);
        putpixel (a-y, b+x, WHITE);
        putpixel (a-y, b-x, WHITE);
        delay(100);
    }
}
int main()
{
    float x, y,a, b, r, p;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("ENTER CENTER AND RADIUS \n");
    printf("ENTER (a, b) ");
    scanf("%f %f", &a, &b);
    printf("ENTER r ");
    scanf("%f", &r);
    cal(a, b, r);
    getch();
    closegraph();
}
