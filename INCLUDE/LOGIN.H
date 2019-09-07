				/*------------
				    LOGIN.H
				 ------------*/


#ifndef __LOGIN_H
#define __LOGIN_H


#include<lgintrue.h>

// Function Prototypes

int  check_usnm_pass( char [], char [] );
void wrong_password( void );
void usnm_no_exist( void );
int  login( void );
int  lvalidate_username( char [] );
void linvalid_username( void );
void l_field_missing( void );
void l_max_char_username( void );
void l_max_char_name( void );

// Login Function Defination

int login()
{
// Function Interface
startoffunction:
window(13,8,67,16);
textbackground(1);
textcolor(15);
_setcursortype(_NORMALCURSOR);
clrscr();
cout<<char(201);
for(int i=0; i<23; ++i) cout<<char(205);
cout<<" LOGIN ";
for( i=0; i<23; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(2)<<"";
cout<<"Username : "<<setw(40)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(2)<<"";
cout<<"Password : "<<setw(40)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(19)<<"";
textcolor(2);
cprintf("Login");
textcolor(15);
cout<<setw(5)<<"";
textcolor(4);
cprintf("Cancel");
textcolor(15);
cout<<setw(18)<<""<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for(i=0; i<53; ++i) cout<<char(205);
cout<<char(188);

// Function Working

char ch=0, password[50]={"\0"}; int t_1=0, count=0, verify=0; i=0;
char username[8]={"\0"};
// For Username
place1:
{
 i=0; count=0;
 gotoxy(15,3);
 if(username[0]!='\0')
 {
  cout<<username;
  i=strlen(username);
  if(!(t_1))
  {
   ++t_1;
   goto place2;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   username[i]='\0';
   verify=lvalidate_username(username);
   if(verify==1)
   {
    strcpy(username,"\0");
    goto startoffunction;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   username[i]='\0';
   gotoxy(15,3);
   goto place2;
  }

  if(ch==char(27))
  {
   return 1;
  }

  if(ch==char(8))
  {
   if(i>0)
   {
    cout<<"\b \b";
    --i;
    --count;
    continue;
   }
  }

  if(ch==0x00)
  {
   ch=getch();
   switch(ch)
   {
    case UP_ARROW :
    case DOWN_ARROW:
    case LEFT_ARROW:
    case RIGHT_ARROW: continue;
   }
  }

  if(count==8)
  {
   // Load Extra-Character Function
   l_max_char_username();
   strcpy(username,"\0");
   t_1=0;
   goto startoffunction;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   if((ch>=97)&&(ch<=122))
   {
    ch-=32;
   }
   username[i]=ch;
   cout<<username[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Password
place2:
{
 i=0; count=0;
 gotoxy(15,5);
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   password[i]='\0';
   break;
  }

  if(ch==char(9))
  {
   password[i]='\0';
   gotoxy(15,5);
   goto place3;
  }

  if(ch==char(27))
  {
   return 1;
  }

  if(ch==char(8))
  {
   if(i>0)
   {
    cout<<"\b \b";
    --i;
    --count;
    continue;
   }
  }

  if(ch==0x00)
  {
   ch=getch();
   switch(ch)
   {
    case UP_ARROW :
    case DOWN_ARROW:
    case LEFT_ARROW:
    case RIGHT_ARROW: continue;
   }
  }

  if(count==50)
  {
   // Load Extra-Character Function
   l_max_char_name();
   strcpy(password,"\0");
   goto startoffunction;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   password[i]=ch;
   cout<<"*";
   ++i;
   ++count;
  }
 }while(1);
}

// For Login Option
place3:
{
 count=0;
 gotoxy(21,7);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place4;

  case 8 : goto place3;

  case 13: {
	    int d=strlen(username), e=strlen(password);
	    if((d==0)||(e==0))
	    {
	     l_field_missing();
	     goto startoffunction;
	    }

	    verify=0;
	    verify=lvalidate_username(username);
	    if(verify==1)
	    {
	     strcpy(username,"\0");
	     ++count;
	    }

	    if(count)
	    {
	     goto startoffunction;
	    }
	    count=0;
	    count=check_usnm_pass(username,password);
	    switch(count)
	    {
	     case 0  : login_success(username);
		       return 0;
	     case 1  : wrong_password(); goto startoffunction;
	     case -1 : usnm_no_exist(); goto startoffunction;
	    }
	   }

  case 27: {
	    return 1;
	   }

  case RIGHT_ARROW: goto place4;

  default: goto place3;
 }
}

// For Cancel Option
place4:
{
 gotoxy(31,7);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place1;

  case 8 : goto place4;

  case 13: {
	    return 1;
	   }

  case 27: {
	    return 1;
	   }

  case LEFT_ARROW: goto place3;

  default: goto place4;
 }
}
}


// Function To Check Username & Password Combination

int check_usnm_pass(char username[], char password[])
{
int temp=0, count=0;
char usname[8]={"\0"}, pass[50];
fstream file;
file.open("C:/SMS/PROGRAM/usnm.unl", ios::binary|ios::in);
while(file)
{
 ++count;
 file.getline(usname, 8, '\n');
 if(!(strcmp(usname,username)))
 {
  temp=count;
  break;
 }
}
file.close();
if(temp>0)
{
 file.open("C:/SMS/PROGRAM/0x706173.pad", ios::binary|ios::in);
 while(count)
 {
  file.getline(pass, 50, '\n');
  --count;
  if(!(strcmp(pass, "\0")))
  {
   ++count;
  }
 }
 if(!(strcmp(pass,password)))
 {
  return 0;
 }
 else
 {
  return 1;
 }
}
else
{
return -1;
}
}


// Function To Display Error For Wrong Password

void wrong_password()
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(15,8,65,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<49; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(49)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(6)<<"";
textattr(20);
cprintf("Wrong Username-Password Combination!!");
textattr(18);
cout<<setw(6)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(49)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(49)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(11)<<"";
textattr(154);
cprintf("Press Any Key To Continue...");
textattr(26);
cout<<setw(10)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(49)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(49)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<49; ++i) cout<<char(205);
cout<<char(188);
getch();
}



// Function To Flag Error If Username Does Not Exist

void usnm_no_exist()
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,15);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(3)<<"";
textattr(20);
cprintf("Username Does Not Exist!");
textattr(18);
cout<<setw(3)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,8);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


int lvalidate_username( char usname[])
{
 int ctr=0;
 for(int i=0; i<strlen(usname); ++i)
 {
  ctr=isalnum(usname[i]);
  if (ctr==0)
  {
   linvalid_username();
   return 1;
  }
 }
 return 0;
}

void linvalid_username( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(7)<<"";
textattr(20);
cprintf("Invalid Username!");
textattr(18);
cout<<setw(6)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(5)<<"";
textattr(20);
cprintf("Space Is Not Allowed!");
textattr(18);
cout<<setw(4)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


void l_field_missing( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(3)<<"";
textattr(20);
cprintf("Compulsory Field Missing!");
textattr(18);
cout<<setw(2)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}



void l_max_char_username( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Max. Allowed : 8 Characters ");
textattr(18);
cout<<setw(1)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


void l_max_char_name( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Max. Allowed : 50 Characters");
textattr(18);
cout<<setw(1)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}



#endif		/* __LOGIN_H*/

// END OF LOGIN.H