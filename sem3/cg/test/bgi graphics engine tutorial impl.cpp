#include <windows.h> //#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graphics.h"

/// Global Variables ///////////////////////////////////////////////////////////////////////
const float g=9.8;
typedef struct
{
    float x1,y1,x2,y2;
}BoundaryType;

int R;

float TimeDelay;
float Theta;
float Vo,NewVo;
BoundaryType WBound,DBound,NewDBound;

int AlienX, AlienY;
int PrevMouseX,PrevMouseY;
int TankX,TankY;
int BulletX, BulletY;
time_t ChangeTime, CurrentTime;

/// Function Prototypes ////////////////////////////////////////////////////////////////////
void MoveSprite();
void AnimateTank();
/// User-defined Functions /////////////////////////////////////////////////////////////////
// World-to-Device Coordinates Transformation
int Xdev(BoundaryType WorldBound,BoundaryType DevBound,float xworld)
{
    float xslope,xint;

    if((WorldBound.x2-WorldBound.x1) == 0)
        xslope = (DevBound.x2-DevBound.x1)/(WorldBound.x2-
                                            WorldBound.x1+.001);
    else
        xslope = (DevBound.x2-DevBound.x1)/(WorldBound.x2-WorldBound.x1);
    xint = DevBound.x1-xslope*WorldBound.x1;
    return (int)ceil(xslope*xworld+xint);
}

void MultiplePages(){
    int i;
    int x,y;
    bool PageFlag=FALSE;
    setactivepage(1);
    cleardevice();
    outtext("PAGE 1");
    setvisualpage(1);
    y=getmaxy()/2;
    while( (GetAsyncKeyState(VK_ESCAPE))==0 )
        for(x=0;x<getmaxx();x++) {
            if(GetAsyncKeyState(VK_ESCAPE) != 0) {break;}

            if (PageFlag) {
                setactivepage(0);
                cleardevice();
                setfillstyle(SOLID_FILL,RED);
                fillellipse(x,y,12,12);
                rectangle(x,y+(getmaxy()/12),x+100,y+(getmaxy()/11));
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
                outtextxy(getmaxx()/2,getmaxy()/8,"PAGE 0");
                setvisualpage(0);
            } else {
                setactivepage(1);
                cleardevice();
                setfillstyle(SOLID_FILL,RED);
                fillellipse(x,y,12,12);
                rectangle(x,y+(getmaxy()/12),x+100,y+(getmaxy()/11));
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
                outtextxy(getmaxx()/2,getmaxy()/8,"PAGE 1");
                setvisualpage(1);
            }
            if (ismouseclick(WM_LBUTTONDOWN)){}
            PageFlag=!PageFlag;
        }
}

int main(void)
{
    char tempstring[80];
    srand(time(NULL)); // Seed the random number generator
    int GraphDriver=0,GraphMode=0;
    GraphDriver = DETECT; GraphMode;
    initgraph(&GraphDriver,&GraphMode,""); // Start Window
    initwindow(1280, 1024);
// TankGame();
//SinglePage();
MultiplePages();
//GraphicsDemo();
    getch();
    return 0;
}
