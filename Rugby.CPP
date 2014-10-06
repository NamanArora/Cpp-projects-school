#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
int x=200,y=200;
void movex(int i)
{
 static int dis;
 dis+=i*5;
 x=200+dis;
 cleardevice();
 circle(x,y,30);
}
void movey(int i)
{
static int dis;
dis+=i*5;
y=200+dis;
cleardevice();
circle(x,y,30);
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm, "C:\\TC\\BGI");
unsigned char a;
	while(!kbhit())
	{

		a=getch();
		//for detect the function\arrow keys
		//we must call the getch() again
		//testing if a is '0' or '0xE0'
		if (a==0 || a==0xE0) a=getch();

		if (a==27) //ESC for exit the 'while'
			break;
		else if (a==72)
		{
		       cout << "up";
		       movey(-1);
		}
		else if (a==80)
		{
		    movey(1);
			cout << "down";
		}
		else if (a==75)
		{
			cout <<"LEFT";
			movex(-1);
		}
		else if (a==77)
		{
			cout << "RIGHT";
			movex(1);
		}
	}


}
