#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

#define STARTX 200
#define STARTY 200
#define SPEED 100
#define CHASESPEED 3
#define USERSPEED 2
int x=STARTX,y=STARTY;
int x1=200,y1=500;
int chase()
{
if(x1==x && y1==y)
exit(0); //balls at same place, collision, game over
else if(x1==x)
{
//same x column
if(y1>y) //its above
{
y1-=CHASESPEED;
circle(x1,y1,30);
}
else
{
y1+=CHASESPEED;
circle(x1,y1,30);
}
}

else if(y1==y)
{
//same y row
if(x1>x)
{
x1-=CHASESPEED;
circle(x1,y1,30);
}
else
{
x1+=CHASESPEED;
circle(x1,y1,30);
}
return 1;
}

}
void movex(int i=0)
{
 static int dis;
 dis+=i*USERSPEED;
 x=STARTX+dis;
 cleardevice();
 circle(x,y,30);
}
void movey(int i=0)
{
static int dis;
dis+=i*USERSPEED;
y=STARTY+dis;
cleardevice();
circle(x,y,30);
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm, "C:\\TC\\BGI");
circle(x1,y1,30);
circle(STARTX,STARTY,30);
unsigned char a;
int b=1;
while(b)
{
while(!kbhit())
{
setbkcolor(2);
//animation material
movex();
chase();
delay(SPEED);
cleardevice();
}
a=getch();
		//for detect the function\arrow keys
		//we must call the getch() again
		//testing if a is '0' or '0xE0'
		if (a==0 || a==0xE0) a=getch();

		if (a==27) //ESC for exit the 'while'
			break;
		else if (a==72)
		{

			movey(-1);
		}
		else if (a==80)
		{
			movey(1);

		}
		else if (a==75)
		{

			movex(-1);
		}
		else if (a==77)
		{

			movex(1);
		}
}


}
