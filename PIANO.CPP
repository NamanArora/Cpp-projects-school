#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>

 // Mouse functions
        union REGS i,o;
// Initialize mouse
        void initmouse()
        {
            i.x.ax=0;
            int86(0x33,&i,&o);
        }

// Show Mouse pointer
        void showmouseptr()
        {
            i.x.ax=1;
            int86(0x33,&i,&o);
        }
// Hide Mouse pointer
        void hidemouseptr()
        {
            i.x.ax=2;
            int86(0x33,&i,&o);
        }

void getmousepos(int *button,int *x,int *y)
{
    i.x.ax=3;
    int86(0x33,&i,&o);

    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
}
void grid()
{
 line((getmaxx()*3/4)*1/4,0,(getmaxx()*3/4)*1/4,getmaxy());
 line((getmaxx()*3/4)*2/4,0,(getmaxx()*3/4)*2/4,getmaxy());
 line((getmaxx()*3/4)*3/4,0,(getmaxx()*3/4)*3/4,getmaxy());
 line((getmaxx()*3/4)*4/4,0,(getmaxx()*3/4)*4/4,getmaxy());
 line(getmaxx()*3/16,getmaxy()/4,getmaxx()*3/4,getmaxy()/4);
 line(getmaxx()*3/16,getmaxy()/2,getmaxx()*3/4,getmaxy()/2);
 line(getmaxx()*3/16,getmaxy()*3/4,getmaxx()*3/4,getmaxy()*3/4);
}

void fill(int i)
{
switch(i)
 {
	case 1:
	floodfill((getmaxx()*3/4)*1/4+1,0,WHITE);
	break;
	case 2:
	floodfill((getmaxx()*3/4)*2/4+1,0,WHITE);
	break;
	case 3:
	floodfill((getmaxx()*3/4)*3/4+1,0,WHITE);
	break;
	case 4:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()/4+1,WHITE);
	break;
	case 5:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()/2-1,WHITE);
	break;
	case 6:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()/2-1,WHITE);
	break;
	case 7:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()/2+1,WHITE);
	break;
	case 8:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()/2+1,WHITE);
	break;
	case 9:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()/2+1,WHITE);
	break;
	case 10:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()*3/4+1,WHITE);
	break;
	case 11:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()*3/4+1,WHITE);
	break;
	case 12:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()*3/4+1,WHITE);
	break;
 }
}

void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 
 //Keyboard creation

 //Keyboard ends
 //Note reading
 setfillstyle(SOLID_FILL, BLUE);
 ifstream file("notes.txt");
 int a,arr[4]={0},i=-1;
 int x,y,button;
 showmouseptr();
 getch();
 while(!kbhit())
 {
 getmousepos(&button,&x,&y); //stores the location of mouse in x and y each time
 //get the next box
 file >> a;
 
 //draw the grid again
 grid();
 
 //store the value
 arr[0]=a;
 
 //to prevent incrmenting values initially
 if(i<=3)
 i++;
 
 //fill the colour
 for(int k=0; k<4; k++)
 fill(arr[k]);

 //move the box down
 for(int f=0; f<=i; f++)
 arr[f]+=3 ;
 
 //shift the array to right
 for(int d=3; d>=1; d--)
 arr[d]=arr[d-1];
 
  
 
 delay(1000);
 cleardevice();
 
 }
 
 
 
 

 getch();

}