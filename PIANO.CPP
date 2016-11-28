#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>

struct node
{
	int data;
	node *next;
};

class queue
{
	node *head;

	public:

	queue()
	{
		head=NULL;
	}

node* setup()
{
	node *t= new node;
	t->data=0;
	t->next=NULL;
	return t;
}

void createlist()
{
    head = setup();
    head->next = setup();
    head->next->next = setup();
    head->next->next->next = setup();
}

void set(int loc, int data)
{
	node *t=head;
    for(int i=0; i<loc; i++)
    {
	t=t->next;
    }
    t->data=data;
}
int get(int index)
{
	node *t=head;
    for(int i=0; i<index; i++)
    {
	t=t->next;
    }
    return t->data;
}
};

/*
  THIS FUNCTION CREATES THE INTRO
  SCREEN.
*/

void intro()
{
  int maxx = getmaxx();
  int maxy = getmaxy();
  int font=3;
  int black=15;
  int blue=3;
  int white = 15;
  int size1=8, size2=4;

  setbkcolor(white);
  settextstyle(font,HORIZ_DIR,size1);  // For setting the text: font,direction,size
  setcolor(blue);	  //Set color to blue
  outtextxy(maxx/5,maxy/4,"PIANO TILES"); //Place the text at 100,100
  settextstyle(font,HORIZ_DIR,size2); //change the font size
  outtextxy(maxx/5,maxx/3,"BY: GROUP 4" );

  outtextxy(maxx/5,maxy/2,"Press any key to continue..");
  settextstyle(font,HORIZ_DIR,2);
  //outtextxy(maxx/5-5,maxy/2+40,"/");
  for(int i=0; i<400; i++)
  {
	outtextxy(maxx/5-5+i,maxy/2+40,"/");
	delay(5);

  }


  getch(); //wait for user to press any button
  setcolor(black); //set color to default(black)
  cleardevice(); //clear the screen
  setbkcolor(0);
}

void start()
{
	setbkcolor(15);
	setcolor(4);
	settextstyle(3,HORIZ_DIR,15);
	outtextxy(getmaxx()/3+30, getmaxy()/3,"1");
}

void controls()
{
  cleardevice();
  setbkcolor(15);
  getch();
  //setbkcolor(0);
}

/*
  GAME OVER SCREEN
*/
void over()
{
 int size=7;
 int font=3;
 int red=4;
 setbkcolor(0);
 settextstyle(font,HORIZ_DIR,size);  // For setting the text: font,direction,size
 setcolor(red);	  //Set color to red
 outtextxy(140,10,"Game over!"); //Place the text at 100,100

}

/*
	THIS FUNCTION CREATES THE MAIN
	LAYOUT OF OUR 'TILES'. IT RENDERS
	A 4X3 GRID EVERY TIME THE SCREEN
	REFRESHES.
	THE COORDINATES ARE SET KEEPING IN
	MIND THAT THE LAYOUT LOOKS SAME IN
	ALL THE RESOLUTIONS.
	THE MONITOR BEHAVES LIKE A
	CARTESIAN PLACE INSIDE A 4TH QUADRANT.
*/

void grid()
{
	setbkcolor(15);
	setcolor(3);
 int maxx=getmaxx();
 int maxy=getmaxy();
 line((maxx*3/4)*1/4,0,(maxx*3/4)*1/4,maxy); // keep the x axis constant and draw 4 lines vertically
 line((maxx*3/4)*2/4,0,(maxx*3/4)*2/4,maxy);
 line((maxx*3/4)*3/4,0,(maxx*3/4)*3/4,maxy);
 line((maxx*3/4)*4/4,0,(maxx*3/4)*4/4,maxy);
 line(maxx*3/16,maxy/4,maxx*3/4,maxy/4); // keep y axis constant and draw 3 lines horizontally
 line(maxx*3/16,maxy/2,maxx*3/4,maxy/2);
 line(maxx*3/16,maxy*3/4,maxx*3/4,maxy*3/4);
}

/*
	THIS FUNCTION FILLS COLORS
	IN OUR TILES BY SPECIFYING
	THE COORDINATE FOR EACH OF OUR
	TILE.
	THE TILES ARE NUMBERED FROM 1-12
	FROM WHICH WE FILTER OUT THE TILES
	WHICH NEED TO BE COLOURED USING THE
	SWITCH CASE.

*/

void fill(int i)
{
setfillstyle(SOLID_FILL, 5); //blue color for the tiles
int color=3;
switch(i) // i tells which tile to fill
 {
/*
	Floodfill fills the color in the desired area
	The first 2 parameters define a point inside the region to be coloured
	The last paramater tells the color of the boundary that needs to be filled
 */
	case 1:
	floodfill((getmaxx()*3/4)*1/4+1,0,color);
	break;
	case 2:
	floodfill((getmaxx()*3/4)*2/4+1,0,color);
	break;
	case 3:
	floodfill((getmaxx()*3/4)*3/4+1,0,color);
	break;
	case 4:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()/4+1,color);
	break;
	case 5:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()/2-1,color);
	break;
	case 6:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()/2-1,color);
	break;
	case 7:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()/2+1,color);
	break;
	case 8:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()/2+1,color);
	break;
	case 9:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()/2+1,color);
	break;
	case 10:
	floodfill((getmaxx()*3/4)*1/4+1,getmaxy()*3/4+1,color);
	break;
	case 11:
	floodfill((getmaxx()*3/4)*2/4+1,getmaxy()*3/4+1,color);
	break;
	case 12:
	floodfill((getmaxx()*3/4)*3/4+1,getmaxy()*3/4+1,color);
	break;
 }
}

/*
	SINCE RANDOM() FUNCTION GENERATES
	SAME VALUE AT EACH RUN. TO PREVENT THAT
	FROM HAPPENING WE EXPLICITLY PROVIDE
	A SEED VALUE TO THE RANDOM NUMBERED
	GENERATOR SO THAT WE GET NEW VALUES AT
	EACH RUN.
*/

int rnd()
{
 int rnd_num=rand();
 return (rnd_num%3)+1 ; //get any rand var between 1 and 3, stdlib.h
}



/*
	THIS FUNCTION CREATES A TIME BAR
	BY CREATING A RECTANGLE AND INCREASING
	ITS LENGHT BY 16PX FOR EVERY SECOND PASSED.
*/

void bar(int time)
{
 setcolor(5);
 int update=time*16; //no of pixels to update on each second
 rectangle(0,getmaxy()-update,50,getmaxy()); //draw the bar with the coordinates
 setfillstyle(SOLID_FILL, RED); //colour to be filled is set to RED
 floodfill(1,getmaxy()-time,5); //Fill the colour
}


void main()
{
 queue q;
 q.createlist();
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 //intro();
 start();
 int a,i=-1,b=1;
 int score=-1; //result increments the val
 char press;
 time_t start,end; //time_t variables can store values returned by time function
 time(&start); //stores the current time in start
 time(&end); //stores the current time in end
 int diff=difftime(end,start); //stores the time elapsed
 srand(time(0)); //stdlib.h, time(0)

 while(b && diff<=30) //run while b is true and time elapsed is less than 30 secs
 {
 bar(diff); //shows the time bar
 a=rnd(); //get the next box using randomize func
 grid(); //draw the grid again else the old boxes wont go away
 q.set(0,a); //store the value in our grid array
 if(i<=3) //wait for array to get filled
 i++;
 for(int k=0; k<4; k++) //fill the colour
 fill(q.get(k)); //color the boxes corresponding to our grid array
 if(i>=3) //dont start game until array is filled
 {
 score++; //score keeper integer
 press=getch(); //get the key-press
 switch(press)
 {
 case 27: //escape key ascii
 exit(0);

 /*
	If the key-press and the last number in our array is same
	then show green colour on the button else red.
 */
 case 'a': // Button 'a' from keyboard
 if(q.get(3)==10)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*1/4+1,getmaxy()*3/4+1,3);
 break;

 case 's': // Button 's' from keyboard
 if(q.get(3)==11)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*2/4+1,getmaxy()*3/4+1,3);
 break;

 case 'd': // Button 'd' from keyboard
 if(q.get(3)==12)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*3/4+1,getmaxy()*3/4+1,3);
 break;

 default: //if any other key is pressed
 b=0; //set b to zero to end the game
 }
 }

 for(int f=0; f<=i; f++) //move the box down
 q.set(f,q.get(f)+3);
 //q.arr[f]+=3 ;
 for(int d=3; d>=1; d--)
 q.set(d,q.get(d-1));

 //q.arr[d]=q.arr[d-1]; //shifts the array to the right to accomodate new val
 delay(100);
 cleardevice();
 time(&end); //get the time
 diff=difftime(end,start); //update time elapsed
 }
 cleardevice();
 over();
 fstream scores("scores.txt",ios::ate | ios::in | ios::out); //Open the file in read,write,append-to-end mode
 gotoxy(28,10); 
 cout << "Your score was " << score;
 gotoxy(27,12);
 cout << "Enter your name: ";
 char name[20];
 cin >> name;
 if(scores)
 scores<< endl << name << " " << score ; //write the name and score to the file
 else
 cout << "Unable to save score!";

 cout << endl << endl<< "Scores: " << endl << endl;
 scores.seekg(ios::beg);  //move the pointer to the starting of file
 while(!scores.eof()) //display al the previous score
 {
 scores.getline(name,20,' ');
 cout << '\t' << name;
 scores.getline(name,20);
 cout << '\t' << name << endl;
 }
 getch();
}
