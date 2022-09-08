#include "../graphics.h"
#include <iostream>

using std::cout;
using std::cin;

int main() {
    int gdriver = DETECT, gmode;
    //initgraph(&gdriver, &gmode, (char *)"");
    initwindow(800, 400, "DDA Line Drawing Algorithm");

    int x1, y1, x2, y2;
    cout << "Input:: x1 y1: ";
    cin >> x1 >> y1;
    cout <<  "Input:: x2 y2: ";
    cin >> x2 >> y2;
    int x_diff = abs(x2- x1);
    int y_diff = abs(y2- y1);
    int steps = x_diff > y_diff ? x_diff : y_diff;
    int x = x1, y = y1;
    int dx = int(steps/x_diff), dy = int(steps/y_diff);

    for (int s=0; s<steps; s++){
        x += dx;
        y += dy;
        putpixel(x,y, 15);
        delay(100);
    }
    getch();
    closegraph();
}