#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

#define SPEED 100
#define CHASESPEED 5
#define USERSPEED 5
int x=200,y=200;
int x1=100,y1=200;
int chase()
{
if(x1==x && y1==y)
exit(0); //balls at same place, collision, game over
if(x1==x)
{
//same x column
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
 x=200+dis;
 cleardevice();
 circle(x,y,30);
}
void movey(int i)
{
static int dis;
dis+=i*USERSPEED;
y=200+dis;
cleardevice();
circle(x,y,30);
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm, "C:\\TC\\BGI");
circle(x1,y1,30);
circle(200,200,30);
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
