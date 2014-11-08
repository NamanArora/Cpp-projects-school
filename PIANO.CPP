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
// Check coordinates of mouse
void getmousepos(int *button,int *x,int *y)
{
    i.x.ax=3;
    int86(0x33,&i,&o);

    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
}
void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 //We set the keyboard here
 line(getmaxx()/3-50,0,getmaxx()/3-50,getmaxy());
 line(getmaxx()*2/3+50,0,getmaxx()*2/3+50,getmaxy());

 //Now the columns
  line(getmaxx()/3+55,0,getmaxx()/3+55,getmaxy());
  line(getmaxx()/3+160,0,getmaxx()/3+160,getmaxy());

 //Now the rows
   line(getmaxx()/3-50,getmaxy()/4,getmaxx()*2/3+50,getmaxy()/4);
   line(getmaxx()/3-50,getmaxy()/2,getmaxx()*2/3+50,getmaxy()/2);
   line(getmaxx()/3-50,getmaxy()*3/4,getmaxx()*2/3+50,getmaxy()*3/4);


 getch();

}
