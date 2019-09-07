#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
//Declaration of Arrow Keys in Hexadecimal value..

#define UP_ARROW     0x48
#define LEFT_ARROW   0X4B
#define RIGHT_ARROW  0x4D
#define DOWN_ARROW   0x50

//LOGIN FUNCTION STARTS HERE..

int i;
unsigned char a;
  void Login()
{
  clrscr();
  window(1,1,80,25);
  textbackground(6);
  textcolor(4);
  clrscr();
  gotoxy(20,25);
  cout<<"ARROW-KEYS";
  gotoxy(50,25);
  cout<<"ENTER";
  textcolor(0);
  gotoxy(30,25);
  cprintf("-NAVIGATE");
  gotoxy(55,25);
  cprintf("-SELECT OPTION");

  window(1,1,80,24);
  textbackground(0);
  textcolor(15);
  clrscr();
  cout<<setw(26)<<""<<char(1)<<char(2)<<"  ACCOUNT INFO.  "<<char(2)<<char(1);
  gotoxy(65,4);
  cout<<"USERNAME";
  gotoxy(33,8);
  cout<<""<<"Proceed";
  cout<<"\n\n"<<setw(32)<<""<<"Setting";
  cout<<"\n\n"<<setw(32)<<""<<"Logs";
  cout<<"\n\n"<<setw(32)<<""<<"Logout";
  i=8;
  _setcursortype(_SOLIDCURSOR);

  do
  {
  gotoxy(31,i);

  a=getch();
  if(a==0x00)
  a=getch();
   switch(a)
   {   case UP_ARROW :{ if(i>8)
		       { i-=2;
		       }break;
		      }
       case DOWN_ARROW :{ if(i<14)
			 {i+=2;
			 }
			}break;
       default : exit(1); //To TERMINATE THIS PROGRAM...
   }
  }while(i);
  getch();
}

//LOGIN FUNCTION ENDS....

void main()
{
Login();
getch();
}