#include "../graphics.h"
#include<iostream>
using namespace std;
void ellipse(double xc,double yc,double a,double b)
{
    double p=b*b-a*a*b+a*a/4;
    double x=0, y=b;
    while(2.0*b*b*x <= 2.0*a*a*y)
    {
        if(p < 0)
        {
            x++;
            p = p+2*b*b*x+b*b;
        }
        else
        {
            x++;
            y--;
            p = p+2*b*b*x-2*a*a*y-b*b;
        }
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        delay(100);
    }
    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y > 0)
    {
        if(p <= 0)
        {
            x++;
            y--;
            p = p+2*b*b*x-2*a*a*y+a*a;
        }
        else
        {
            y--;
            p = p-2*a*a*y+a*a;
        }
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        delay(100);
    }
}
int main()
{
    int gd = DETECT, gm;
    double xc,yc,x,y, a,b;
    initgraph(&gd, &gm, (char *) "");
    cout<<"Enter coordinates of centre: ";
    cin>>xc>>yc;
    cout<<"Enter length of major and minor axix a,b: ";
    cin>>a>>b;
    ellipse(xc, yc, a, b);
    getch();
    closegraph();
}