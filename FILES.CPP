#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
class account
{
  char name[30];
  char password[15];
  int balance;
  char line[45];
  public:
  //To create the account
  void create()
  {
   ofstream out;
   out.open("accounts.txt", ios::ate);

   if(out.eof())
   out.clear();

   cout << "Enter your name: "; cin >> name;
   cout << "Enter your password: "; cin >> password;
   cout << "Enter your balance: "; cin >> balance;
   out << "NAME=" << name << "PASS=" << password << "BAL=" << balance << "\n";
  }

  //To login in your account
  int login()
  {
   ifstream in;
   in.open("accounts.txt", ios::ate);
   in.seekg(0);

   if(in.eof())
   in.clear();

   cout << "Enter your name: ";
   cin >> name;
   cout << "Enter your password: ";
   cin >> password;

   //prepare the line to be searched
   strcat(line,"NAME=");
   strcat(line,name);
   strcat(line,"PASS=");
   strcat(line,password);

   char *a,get[45];
   int found=0;
   while(!in.eof())   //we lost the inline facility
   {
   in.getline(get,45);
   a=strstr(get,line); //source,search
   if(a)      //match found for the exact string
   {
   found =1;
   break;
   }
   }

   if(found)
   {
   char *b=strstr(a,"BAL=");    //get pointer to desired position
   b+=4;       //take the cursor to the digits
   balance=atoi(b);    //convert char(digits) to int(digits)
   return 1;
   }
   else
   return 0;
   in.close();
  }

  void change(char *newpass,int amt=0)
  {

   ofstream out("new.txt");
   ifstream in("accounts.txt");
   //prepare the line to be searched
   strcpy(line,"");
   strcat(line,"NAME=");
   strcat(line,name);
   strcat(line,"PASS=");
   strcat(line,password);
   strcat(line,"BAL=");
   char bal[33];
   itoa(balance,bal,10);
   strcat(line,bal);

   char get[45];
   system("pause");
   while(!in.eof())
   {
    in.getline(get,45);
    if(!strcmp(get,line)==0)
    out << get << endl;
   }
   in.close();
   remove("accounts.txt");
   balance+=amt;
   out << endl;

   if(strcmp(newpass,""))
   strcpy(password,newpass);
   out << "NAME=" << name << "PASS=" << password << "BAL=" << balance << endl;
   out.close();
   rename("new.txt","accounts.txt");
  }

  void show()
  {
   cout << "The current balance in your account is Rs. " << balance << endl;
   system("pause");
  }

};

void menu(account ac)
{
 int input,amt,counter=0;
 char newpass[15],name[30];
 do{
 clrscr();
 cout << "\t\t\t\t Access Granted!"
 		<< endl << endl << endl
      << "1.Deposit funds" << endl << endl
      << "2.Withdraw funds" << endl << endl
      << "3.Show balance" << endl << endl
      << "4.Change password" << endl << endl
      << "5.Exit" << endl << endl
      << endl;
 cout << "Enter your option: ";
 cin >> input;
 switch(input)
 {
  case 1:
  cout << "Enter the amount you want to deposit: ";
  cin >> amt;
  ac.change("",amt);
  break;
  case 2:
  cout << "Enter the amount you want to withdraw: ";
  cin >> amt;
  counter+=amt;
  if(counter <=20000)
  ac.change("",-amt);
  else
  {
  cout << "Withdrawal limit reached for this session" << endl;
  system("pause");
  }
  break;
  case 3:
  ac.show();
  break;
  case 4:
  cout << "Enter the new password: ";
  cin >> newpass;
  ac.change(newpass);
  break;
  case 5:
  exit(0);
  break;
 }
   }while(input<6);
}


void main()
{
 account acc;
 int input,status;
 char a;

 do{
 clrscr();
 cout << "1.New user" << endl << "2.Old user" << endl;

 cin >> input;
 switch(input)
 {
  case 1:
  acc.create();
  break;
  case 2:
  status=acc.login();       //1 for login succeeded else 0
  break;
 }

 if(input==2)           //to only show when tried to login
 if(status)
 menu(acc);
 else
 cout << "Invalid name/pass";
 }while(input!=2);
 system("pause");
}
