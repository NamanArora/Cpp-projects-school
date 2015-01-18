#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>

void intro()
{
  setfillstyle(2,RED);
  settextstyle(7,HORIZ_DIR,7);
  setcolor(3);
  outtextxy(100,100,"PIANO TILES");
  settextstyle(7,HORIZ_DIR,3);
  outtextxy(160,250,"BY: NAMAN & AKARSH" );
  getch();
  setcolor(15);
  cleardevice();
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
setfillstyle(SOLID_FILL, BLUE);
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

int rnd()
{
 struct time t;
 gettime(&t);
 //ti_hund=hundredth of a second
 //rand int <=3
 return (int)t.ti_hund%3+1;
}

int time()
{
 
 char f[10];
 struct time t;
 gettime(&t);
 settextstyle(3, HORIZ_DIR, 1);

 //stores the starting time
 static int time=t.ti_sec;
 //current time-starting time=diff
 int diff=t.ti_sec-time;
 //put the time limit
 if(diff>=30 || diff <0 )
 return 0;
 itoa(diff,f,10);
 outtextxy(getmaxx()-150,100,"Time: ");
 outtextxy(getmaxx()-80, 100, f);
 return 1;
}

void bar(int score)
{
 //score meter
 int update=score*3;
 rectangle(0,getmaxy()-update,50,getmaxy());
 setfillstyle(SOLID_FILL, MAGENTA);
 floodfill(1,getmaxy()-score+1,WHITE);
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 intro();
 setfillstyle(SOLID_FILL, BLUE);
 int a,arr[4]={0},i=-1,b=1;
 int score=-1; //result increments the val
 char press;

 while(b)
 {


 //key press bar
 bar(score);

 //get the next box using randomize func
 a=rnd();

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

 if(i>=3)
 {
 score++;
 press=getch();
 switch(press)
 {
 case 27:
 exit(0);
 case 'a':
 if(arr[3]==10)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*1/4+1,getmaxy()*3/4+1,WHITE);
 break;

 case 's':
 if(arr[3]==11)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*2/4+1,getmaxy()*3/4+1,WHITE);
 break;

 case 'd':
 if(arr[3]==12)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*3/4+1,getmaxy()*3/4+1,WHITE);
 break;
 default:
 b=0;
 }
 }

 //move the box down
 for(int f=0; f<=i; f++)
 arr[f]+=3 ;

 //shift the array to right
 for(int d=3; d>=1; d--)
 arr[d]=arr[d-1];

 delay(100);
 cleardevice();
  //time keeper
 int lim=time();
 if(lim==0)
 b=0;
 }
 cleardevice();
 fstream scores("scores.txt",ios::ate | ios::in | ios::out);
 cout << "Your score was " << score << endl;
 cout << "Enter your name: ";
 char name[20];
 cin >> name;
 if(scores)
 scores<< endl << name << " " << score ;
 else
 cout << "Unable to save score!";
 cout << endl << endl<< "Scores: " << endl << endl;
 scores.seekg(ios::beg);
 while(!scores.eof())
 {
 scores.getline(name,20,' ');
 cout << name;
 scores.getline(name,20);
 cout << '\t' << name << endl;
 }
 getch();

}
