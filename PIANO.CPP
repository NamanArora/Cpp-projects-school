#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>

void intro()
{
  settextstyle(7,HORIZ_DIR,7);  // For setting the text: font,direction,size
  setcolor(3);	  //Set color to blue
  outtextxy(100,150,"PIANO TILES"); //Place the text at 100,100
  settextstyle(7,HORIZ_DIR,3); //change the font size
  outtextxy(150,250,"BY: NAMAN & AKARSH" );
  getch(); //wait for user to press any button
  setcolor(15); //set color to default(black)
  cleardevice(); //clear the screen
}

void over()
{
 settextstyle(3,HORIZ_DIR,7);  // For setting the text: font,direction,size
 setcolor(4);	  //Set color to red
 outtextxy(140,10,"Game over!"); //Place the text at 100,100

}

void grid()
{
 //Monitor is in the 4th quadrant
 line((getmaxx()*3/4)*1/4,0,(getmaxx()*3/4)*1/4,getmaxy()); // keep the x axis constant and draw 4 lines vertically
 line((getmaxx()*3/4)*2/4,0,(getmaxx()*3/4)*2/4,getmaxy());
 line((getmaxx()*3/4)*3/4,0,(getmaxx()*3/4)*3/4,getmaxy());
 line((getmaxx()*3/4)*4/4,0,(getmaxx()*3/4)*4/4,getmaxy());
 line(getmaxx()*3/16,getmaxy()/4,getmaxx()*3/4,getmaxy()/4); // keep y axis constant and draw 3 lines horizontally
 line(getmaxx()*3/16,getmaxy()/2,getmaxx()*3/4,getmaxy()/2);
 line(getmaxx()*3/16,getmaxy()*3/4,getmaxx()*3/4,getmaxy()*3/4);
}

void fill(int i)
{
setfillstyle(SOLID_FILL, BLUE); //blue color for the tiles
switch(i) // i tells which tile to fill
 {
/*
	Floodfill fills the color in the desired area
	The first 2 parameters define a point inside the region to be coloured
	The last paramater tells the color of the boundary that needs to be filled
 */
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
 return rand()%3+1 ; //get any rand var between 1 and 3, stdlib.h
}

void bar(int time)
{
 int update=time*16; //no of pixels to update on each second
 rectangle(0,getmaxy()-update,50,getmaxy()); //draw the bar with the coordinates
 setfillstyle(SOLID_FILL, RED); //colour to be filled is set to RED
 floodfill(1,getmaxy()-time+1,WHITE); //Fill the colour
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "C:\\TC\\BGI");
 intro();
 int a,arr[4]={0},i=-1,b=1;
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
 arr[0]=a; //store the value in our grid array
 if(i<=3) //wait for array to get filled
 i++;
 for(int k=0; k<4; k++) //fill the colour
 fill(arr[k]); //color the boxes corresponding to our grid array
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
 if(arr[3]==10)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*1/4+1,getmaxy()*3/4+1,WHITE);
 break;

 case 's': // Button 's' from keyboard
 if(arr[3]==11)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*2/4+1,getmaxy()*3/4+1,WHITE);
 break;

 case 'd': // Button 'd' from keyboard
 if(arr[3]==12)
 setfillstyle(SOLID_FILL, GREEN);
 else
 {
 b=0;
 setfillstyle(SOLID_FILL, RED);
 }
 floodfill((getmaxx()*3/4)*3/4+1,getmaxy()*3/4+1,WHITE);
 break;

 default: //if any other key is pressed
 b=0; //set b to zero to end the game
 }
 }

 for(int f=0; f<=i; f++) //move the box down
 arr[f]+=3 ;
 for(int d=3; d>=1; d--)
 arr[d]=arr[d-1]; //shifts the array to the right to accomodate new val
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
 cout << name;
 scores.getline(name,20);
 cout << '\t' << name << endl;
 }
 getch();
}
