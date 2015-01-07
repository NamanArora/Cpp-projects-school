#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>

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
 return (int)t.ti_hund%3+1;
}

void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 //Note reading
 setfillstyle(SOLID_FILL, BLUE);
 int a,arr[4]={0},i=-1,b=1;
 int score=-1; //result increments the val
 char press;

 while(b)
 {
 //get the next box using my randomize func
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
