#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
class accdet;
void menu(fstream &filehandle,accdet &object,int seekval);
class accdet
{
char name[10];
int pass;
int bal;
public:
void filldet()
{
cout << "Enter your name: ";
cin >> name;
cout << "Enter your pass: ";
cin >> pass;
cout << "Enter your balance: ";
cin >> bal;
}
void withdraw(int amt)
{

cout << "Old balance: " << bal;
bal=bal-amt;
cout << "New balance: " << bal;
}
void deposit(int amt)
{

cout << "Old balance: " << bal;
bal=bal+amt;
cout << "New balance: " << bal;
}
void disp()
{
cout << "Balance=" << bal;
system("pause");
}
void display()
{
 cout << "name=" << name;
 cout << "pass=" << pass;
 cout << "bal=" << bal;
}
int check(char* gotname,int gotpass)
{
if(strcmp(gotname,name)==0 && gotpass==pass)
return 1;
else
return 0;
}
};
int login(fstream &filehandle,accdet &object)
{
char name[10];
int pass;
cout << "Enter name: ";
cin >> name;
cout << "Enter pass: ";
cin>> pass;
filehandle.seekg(0);
int i=0,size=sizeof(object);
while(!filehandle.eof())
{
i++;
filehandle.read((char*)&object,size);
if(object.check(name,pass))
return (i-1)*size;
}
return -1;
}
void menu(fstream &filehandle,accdet &object,int seekval)
{
filehandle.open("accounts.dat" , ios:: in | ios:: out | ios:: binary | ios::ate);
filehandle.clear();
filehandle.seekg(seekval);
int input,amt;
char a;
do{
clrscr();
cout << "ACCESS GRANTED!" << endl;
cout << "1.Check balance" << endl << "2.Withdraw money" << endl << "3.Change information" << endl << "4.Deposit money" << endl << "5.Exit"<< "6.display";
cin >> input;
switch(input)
{
case 1:
object.disp();
break;
case 2:
cout << "Enter amount to be withdrawn: ";
cin >> amt;
object.withdraw(amt);
break;
case 3:
filehandle.seekg(seekval);
cout << "Enter your new details: " << endl << endl;
object.filldet();
filehandle.write((char*)&object,sizeof(object));
cout << "Update successful" << endl;
break;
case 4:
cout << "Enter amount to be deposited: ";
cin >> amt;
object.deposit(amt);
break;
case 5:
cout << "byte no=" << seekval;
filehandle.write((char*)&object,sizeof(object)) << flush;
filehandle.close();
exit(0);

break;
case 6:
filehandle.clear();
filehandle.seekg(0);
while(!filehandle.eof())
{
filehandle.read((char*)&object,sizeof(object));
object.display();
cout << endl;
}
}
cout << "Return to main menu? [y/n] ";
cin >> a;
}while(a=='y');
}
void main()
{
clrscr();
accdet object;
fstream filehandle;
filehandle.open("accounts.dat" , ios:: in | ios:: out | ios:: binary | ios::ate);
filehandle.clear();
cout << "Menu screen" << endl << endl;
cout << "1.Are you a new user?" << endl << "2.Existing user" << endl;
int input;
cin >> input;
switch(input)
{
case 1:
object.filldet();
//prevent data redundancy!
filehandle.write((char*)&object,sizeof(object));
filehandle.close();
break;
case 2:
int seekval=login(filehandle,object);
if(seekval >=0)
menu(filehandle,object,seekval);
else
cout << "Invalid pass/name";
break;
}
getch();

}