// Header Files Included

#include<register.h>
#include<help.h>
#include<credits.h>
#include<login.h>
#include<math.h>


// Function Prototypes

int  exitfunction();
void userinterface1();
int  userinterface0();
/*int developer();
void accinfo();
void i_captcha();
void i_credits();
void global();
void help();
void intrface();
void lgintrue();
void i_login();
void i_logout();
void records();
void registerh();
void settings();
void sms();   */

/*-------------------------------------------------------------------------*/

// Function Definations



// START OF Function UserInterface1
void userinterface1()
{
int i; unsigned char a;
startoffunction:

// Interface Presentation
_setcursortype(_SOLIDCURSOR);
clrscr();
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(13,25);
cout<<"ESC";
gotoxy(26,25);
cout<<"ARROW-KEYS";
gotoxy(50,25);
cout<<"ENTER";
textcolor(0);
gotoxy(16,25);
cprintf("-Exit");
gotoxy(36,25);
cprintf("-Navigate");
gotoxy(55,25);
cprintf("-Select Option");

window(1,1,80,24);
textbackground(0);
textcolor(15);
clrscr();

cout<<endl<<endl<<endl;
cout<<setw(33)<<""<<char(2)<<char(1)<<" Welcome "<<char(1)<<char(2);
cout<<endl<<endl<<endl<<endl;
cout<<setw(23)<<""<<"Student Management Software (SMS)";
cout<<endl<<endl<<endl<<endl<<endl;
cout<<setw(36)<<""<<"Register";
cout<<endl<<endl;
cout<<setw(36)<<""<<"Login";
cout<<endl<<endl;
cout<<setw(36)<<""<<"Help";
cout<<endl<<endl;
cout<<setw(36)<<""<<"Credits";
cout<<endl<<endl;
cout<<setw(36)<<""<<"Exit ";

// Interface Working
_setcursortype(_NOCURSOR);
i=13;
do
{
 cout<<"\b \b";
 gotoxy(35,i);
 cout<<char(175);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case UP_ARROW: {
	     if (i>13)
	     {
	      i-=2;
	     }
	    } break;


  case DOWN_ARROW: {
	     if (i<21)
	     {
	      i+=2;
	     }
	    } break;

/*  case CTRL_D : developer();
		i=1; break;
  */
  case 13 : {
	     switch(i)
	     {
	      case 13 : // Load Register Function
			{
			 registeraccount();
			 i=1;
			}
			break;
	      case 15 : // Load Login Function
			{
			 login();
			 i=1;
			}
			break;
	      case 17 : // Load Help
			{
			 main_help();
			 i=1;
			}
			break;
	      case 19 : // Load Credits
			{
			 credits();
			 i=1;
			 getch();
			}
			break;
	      case 21 : // Load Exit Function
			{
			 i=exitfunction();
			}break;
	     } break;
	    }
  case 27 : // Load Exit Function
	    {
	     i=exitfunction();
	    }break;
 }
 if (i==1)
 {
  goto startoffunction;
 }
} while(1);
}
// Function UserInterface1 Ends

/*=========================================================================*/

// Function ExitFunction Starts
int exitfunction()
{
char a;

// Interface Presentation
_setcursortype(_SOLIDCURSOR);
window(26,8,53,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<26; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(6)<<"";
textattr(30);
cprintf("Are You Sure?");
textattr(15);
cout<<setw(7)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Yes");
cout<<setw(4)<<"";
textattr(18);
cprintf("No");
textattr(15);
cout<<setw(9)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(26)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<26; ++i) cout<<char(205);
cout<<char(188);

// Interface Working
gotoxy(10,6);
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
i=10;
do
{
 gotoxy(i,6);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case LEFT_ARROW: {
		    if (i!=10)
		    {
		     i-=7;
		    }
		   } break;

  case RIGHT_ARROW: {
		     if(i!=17)
		     {
		      i+=7;
		     }
		    } break;

  case 9  : {
	     if (i!=10)
	     {
	      i-=7;
	     }
	     if(i!=17)
	     {
	      i+=7;
	     }
	    } break;

  case 13 : {
	    switch(i)
	    {
	     case 10 : { sound(5000);
			 delay(100);
			 nosound();
			 sound(500);
			 delay(200);
			 nosound();
			 exit(0);
		       } break;
	     case 17 : break;
	    }
	   } break;
  case 27 : break;
 }
 if ((a==27)||((a==13)&&(i==17)))  // IF Exit is Not Confirmed
 {
  break;
 }
}while(1);
return 1;
}
// Function ExitFunction Ends


int userinterface0(int ctr)
{
int i;
if(ctr==1) goto start;

_setcursortype(_NOCURSOR);
window(1,1,80,25);
textcolor(0);
textbackground(15);
clrscr();
gotoxy(39,13);
cprintf("Hi ");
for(i=0; i<3; ++i)
{
 cout<<"\b ";
 gotoxy(42,13);
 cout<<char(1);
 delay(150);
 cout<<"\b ";
 gotoxy(42,12);
 cout<<char(1);
 delay(150);
 cout<<"\b ";
 gotoxy(42,13);
 cout<<char(1);
 delay(150);
 cout<<"\b ";
 gotoxy(42,13);
 cout<<char(2);
 delay(150);
 cout<<"\b ";
 gotoxy(42,12);
 cout<<char(2);
 delay(150);
 cout<<"\b ";
 gotoxy(42,13);
 cout<<char(2);
 delay(150);
}
clrscr();
for(i=1; i<26; ++i)
{
 gotoxy(i,13);
 cout<<"Seems Like You Are New With Us";
 delay(30);
 gotoxy(1,13);
 if (i==25) break;
 clreol();
}
sleep(2);
clrscr();
for(i=67; i>32; --i)
{
 gotoxy(i,13);
 cout<<"Lets Start...";
 delay(30);
 gotoxy(1,13);
 if(i==33) break;
 clreol();
}
sleep(2);

start:
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(13,25);
cout<<"ESC";
gotoxy(26,25);
cout<<"ARROW-KEYS";
gotoxy(50,25);
cout<<"ENTER";
textcolor(0);
gotoxy(16,25);
cprintf("-Exit");
gotoxy(36,25);
cprintf("-Navigate");
gotoxy(55,25);
cprintf("-Select Option");

window(1,1,80,24);
textbackground(0);
textcolor(6);
clrscr();

cout<<endl<<endl<<endl;
cout<<setw(33)<<""<<char(2)<<char(1)<<" Welcome "<<char(1)<<char(2);
cout<<endl<<endl<<endl<<endl;
cout<<setw(23)<<""<<"Student Management Software (SMS)";
cout<<endl<<endl<<endl<<endl<<endl;
cout<<setw(21)<<""<<"Lets Learn How To Use The Software...";
cout<<endl<<endl;
cout<<setw(27)<<""<<"Press ENTER to View Help.";
cout<<endl<<endl;
cout<<setw(22)<<""<<"Make Sure To Read The Complete Help \n\n";
cout<<setw(16)<<""<<"Else You Will Not Be Able To Use The Software...";
cout<<endl<<endl;
cout<<setw(36)<<""<<"Help ";

_setcursortype(_NOCURSOR);
i=21; char a=0;
do
{
 cout<<"\b \b";
 gotoxy(35,i);
 cout<<char(175);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {
  case UP_ARROW: break;

  case DOWN_ARROW: break;

  case 13 : {
	     i=main_help();
	     return i;
	    }

  case 27 : {
	     i=exitfunction();
	     if(i==1)
	     goto start;
	    }
  }
 }while(1);
}


/*
int developer()
{
fstream file; int ctr=0; char pass[16]={"\0"};
_setcursortype(_NOCURSOR);
window(1,1,80,25);
textcolor(2);
textbackground(0);
clrscr();
cout<<"		Source Code Developer "<<endl<<endl;
delay(1000);
cout<<"/"; delay(250); cout<<"\b\\... Initializing"; for(int i=0; i<3; ++i) {cout<<"."; delay(500);}
delay(150);
cout<<endl;
cout<<"/"; delay(250); cout<<"\b\\... Checking Files"; for(i=0; i<3; ++i) {cout<<"."; delay(500);} cout<<endl<<endl;
file.open("C:/SMS/PROGRAM/SOURCE/ACCINFO.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing ACCINFO.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/CAPTCHA.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing CAPTCHA.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/CREDITS.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing CREDITS.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/GLOBAL.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing GLOBAL.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/HELP.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing HELP.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/INTRFACE.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing INTRFACE.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/LGINTRUE.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing LGINTRUE.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/LOGIN.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing LOGIN.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/LOGOUT.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing LOGOUT.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/RECORDS.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing RECORDS.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/REGISTER.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing REGISTER.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/SETTINGS.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing SETTINGS.SRC"; ctr++; }
file.close();
file.open("C:/SMS/PROGRAM/SOURCE/SMS.SRC",ios::in|ios::binary);
if(!file) { cout<<"Missing SMS.SRC"; ctr++; }
file.close();

if(ctr>0)
{
cout<<endl<<endl;
cout<<"     "<<ctr<<" of 13 Files Missing...\n\n";
cout<<"Press Any Key To Return To Program";
getch();
return 1;
}

else
cout<<"     File Validation Successful...";
cout<<endl<<endl;
cout<<"     Enter Developer Password : "; cin>>pass;
if(strcmp(pass,"developer@sms.in"))
{
cout<<endl<<endl<<"Incorrect Password..."<<endl<<endl;
cout<<"Press Any Key To Return To Program";
getch();
return 1;
}
cout<<"/"; delay(200); cout<<"\b\\... Generating Directory C:\\SMSSRC...";delay(500);
mkdir("C:/SMSSRC");
cout<<endl<<endl;
cout<<"/"; delay(200); cout<<"\b\\... Generating Files...";
cout<<endl;
cout<<"/"; delay(200); cout<<"\b\\... Please Wait"; for(i=0; i<3; ++i) {cout<<"."; delay(500);}
accinfo();
i_captcha();
i_credits();
global();
help();
intrface();
lgintrue();
i_login();
i_logout();
records();
registerh();
settings();
sms();

cout<<endl<<endl;
cout<<"/"; delay(200); cout<<"\b\\... File Generation Successful...";
cout<<endl<<endl;
cout<<setw(20)<<"Files Extracted To \" C:\\SMSSRC \"";
cout<<endl<<endl;
cout<<"Press Any Key To Return To Program";
getch();
return 0;
}

void accinfo()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/ACCINFO.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/ACCINFO.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void i_captcha()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/captcha.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/captcha.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void i_credits()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/credits.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/credits.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void global()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/global.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/global.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void help()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/help.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/help.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void intrface()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/intrface.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/intrface.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void lgintrue()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/lgintrue.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/lgintrue.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}



void i_login()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/login.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/login.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void i_logout()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/logout.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/logout.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void records()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/records.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/records.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void registerh()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/register.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/register.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void settings()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/settings.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/settings.H", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
}


void sms()
{
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("C:/SMS/PROGRAM/SOURCE/sms.SRC",ios::in|ios::binary);
file.open("C:/SMSSRC/SMS.CPP", ios::out);
while(f)
{
f.read((char*)&s,sizeof(s));
for(i=0,j=1;i<2;++i,--j)
{

 if(s[i]>=48&&s[i]<=57)
 {
 a=int(s[i])-48;
 }
 if(s[i]>=65&&s[i]<=70)
 {
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
file<<char(num);
num=0;
}
f.close();
file.close();
} */


void main()
{
int ctr=0;
start:
clrscr();
int i;
fstream file;
file.open("C:/SMS/PROGRAM/count.ct", ios::in);
if(!file)
{
 file.open("C:/SMS/PROGRAM/count.ct", ios::out);
 file<<0;
 file.close();
 goto start;
}
file>>i;
file.close();
if(i==0)
{
 userinterface0(ctr);
 ++ctr;
 goto start;
}
if(i==1)
{
 userinterface1();
}
}