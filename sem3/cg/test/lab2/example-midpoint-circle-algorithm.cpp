#include<iostream>
#include "../graphics.h"
using namespace std;
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
    cout<<"ENTER CENTER AND RADIUS ";
    cout<< "ENTER (a, b) ";
    cin>>a>>b;
    cout<<"ENTER r ";
    cin>>r;
    cal(a, b, r);
    getch();
    closegraph();
}