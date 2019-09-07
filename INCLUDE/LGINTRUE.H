
			       /*------------
				  LGINTRUE.H
				 ------------*/

#ifndef __LGINTRUE_H
#define __LGINTRUE_H


// INCLUDED HEADER FILES

//#include<records.h>
#include<logout.h>
#include<accinfo.h>
#include<settings.h>



// FUNCTION PROTOTYPES

int login_success( char [] );



// FUNCTION DEFINATIONS

//LOGIN FUNCTION STARTS HERE..



int login_success(char username[])
{
//char o_dir={"C:/SMS/USERS/"};
char ch=0; char temp_usnm[10]={"\0"}, dir[100]={"C:/SMS/USERS/"}, temp_dir1[100]={"\0"};
int bgcolor=0, txtcolor=0;
int i;

strcpy(temp_usnm,username);
//strcpy(dir, o_dir);
strcat(dir, temp_usnm);
strcpy(temp_dir1, dir);
strcat(temp_dir1,"/CONFIG.cfg");

startoffunction:
fstream file;
file.open(temp_dir1, ios::binary|ios::in);
file>>bgcolor;
file>>txtcolor;
file.close();

clrscr();
window(1,1,80,25);
if(bgcolor==3) textbackground(7);
else textbackground(3);
textcolor(4);
clrscr();
gotoxy(19,25);
cout<<"ARROW-KEYS";
gotoxy(45,25);
cout<<"ENTER";
textcolor(0);
gotoxy(29,25);
cprintf("-NAVIGATE");
gotoxy(50,25);
cprintf("-SELECT OPTION");
window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
gotoxy(32,4);
cout<<char(2)<<char(1)<<"  ACCOUNT  "<<char(1)<<char(2);
gotoxy(65,6);
cout<<username;
gotoxy(36,11);
cout<<""<<"Proceed";
gotoxy(36,14);
cout<<"Account Details";
gotoxy(36,17);
cout<<"Settings";
gotoxy(36,20);
cout<<"Logout ";
i=11;
_setcursortype(_NOCURSOR);

do
{
 cout<<"\b \b";
 gotoxy(34,i);
 cout<<char(175);
 ch=getch();
 if(ch==0x00)
 ch=getch();

 switch(ch)
 {
  case UP_ARROW : {
		   if(i>11)
		   { i-=3; }
		  } break;

  case DOWN_ARROW : {
		     if(i<20)
		     { i+=3; }
		    } break;

  case ENTER : {
		switch(i)
		{
		 case 11 : // Load Function To Proceed To Records
			   {
//			    records(username, bgcolor, txtcolor);
			    goto startoffunction;
			   }

		 case 14 : // Load Function To Show Account Details
			   {
			    show_acc_details(username, bgcolor, txtcolor);
			    goto startoffunction;
			   }

		 case 17 : // Load Settings Function
			   {
			    settings(username);
			    goto startoffunction;
			   }

		 case 20 : // Load Logout Function
			   {
			    logout();
			    return 0;
			   }
		} break;
	       }

 }
}while(1);
}

//LOGIN FUNCTION ENDS....

#endif		/* __LGINTRUE_H*/