			    /*-------------------
				   CAPTCHA.H
			      -------------------*/

#ifndef __CAPTCHA_H
#define __CAPTCHA_H



// Included Header Files


#include<global.h>


// Declaration For Various Keys Required By The Fuctions In Hexadecimal Values


#define ONE    0x31
#define TWO    0x32
#define THREE  0x33
#define FOUR   0x34
#define FIVE   0x35
#define SIX    0x36
#define SEVEN  0x37


// Function Prototypes

int captcha( void );
void invalid_captcha( void );
int exit_register( void );

/****************************************************************************/

// Function Definations


// START OF Captcha Function

int captcha( void )
{
int cap_img=0, ret_num=0, i=0; unsigned char input;
start:
// Interface Presentation
_setcursortype(_NORMALCURSOR);
clrscr();
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(13,25);
cout<<"ESC";
gotoxy(28,25);
cout<<"CTRL+R";
gotoxy(51,25);
cout<<"ENTER";
textcolor(0);
gotoxy(16,25);
cprintf("-Cancel");
gotoxy(34,25);
cprintf("-New Captcha");
gotoxy(56,25);
cprintf("-Input Choice");

window(1,1,80,24);
textbackground(0);
textcolor(15);
clrscr();

cout<<endl;
cout<<setw(25)<<""<<char(2)<<char(1)<<" Prove You Are Not A Robot "<<char(1)<<char(2);

// Captcha Window
window(35,4,45,9);
randomize();
cap_img=random(7)+1;
textbackground(cap_img);
clrscr();

window(1,10,80,24);
textbackground(0);
textcolor(15);
clrscr();
cout<<endl;
cout<<setw(25)<<""<<"Which Color Is Visible Above ?";
cout<<endl<<endl;
cout<<setw(28)<<""<<"Color Code"<<setw(4)<<""<<"Color Name";
cout<<endl;
cout<<setw(33)<<""<<"1"<<setw(9)<<""<<"Blue"<<endl;
cout<<setw(33)<<""<<"2"<<setw(9)<<""<<"Green"<<endl;
cout<<setw(33)<<""<<"3"<<setw(9)<<""<<"Cyan/Sea Green"<<endl;
cout<<setw(33)<<""<<"4"<<setw(9)<<""<<"Red"<<endl;
cout<<setw(33)<<""<<"5"<<setw(9)<<""<<"Magenta/Pink"<<endl;
cout<<setw(33)<<""<<"6"<<setw(9)<<""<<"Yellow/Brown"<<endl;
cout<<setw(33)<<""<<"7"<<setw(9)<<""<<"Light Gray/White"<<endl;
cout<<endl;
cout<<setw(20)<<""<<"Input Color Code Of Color Shown Above : ";

// Captcha Working
working:
input=getch();
if(input==0x00)
input=getch();
switch(input)
{
 case CTRL_R : goto start;
 case ENTER  : break;
 case ESC    : i=exit_register(); if(i==1) return 1; else { input='\0'; goto start;}
 case BCKSPC : cout<<"\b \b"; input='\0'; goto working;
 case ONE    : ret_num=1; cout<<ret_num; input='\0'; goto working;
 case TWO    : ret_num=2; cout<<ret_num; input='\0'; goto working;
 case THREE  : ret_num=3; cout<<ret_num; input='\0'; goto working;
 case FOUR   : ret_num=4; cout<<ret_num; input='\0'; goto working;
 case FIVE   : ret_num=5; cout<<ret_num; input='\0'; goto working;
 case SIX    : ret_num=6; cout<<ret_num; input='\0'; goto working;
 case SEVEN  : ret_num=7; cout<<ret_num; input='\0'; goto working;
}

if(ret_num==cap_img)
{
 return 0;
}
else
{
 invalid_captcha();
 goto start;
}
}
// END OF CAPTCHA Function


// START OF Captcha-Error Handling Function

void invalid_captcha( void )
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
cout<<char(187)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Invalid Captcha Verification");
textattr(18);
cout<<setw(1)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue....");
textattr(26);
cout<<setw(0)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<"";
cout<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<""<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}
// END OF Captcha-Error Handling Function


// START OF EXIT TO FUNCTION TO CANCEL REGISTRATION

int exit_register( void )
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
cout<<char(187)<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(26)<<""<<char(186);
cout<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(3)<<"";
textattr(30);
cprintf("Cancel Registration?");
textattr(18);
cout<<setw(3)<<""<<char(186)<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(26)<<""<<char(186);
cout<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(26)<<""<<char(186);
cout<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Yes");
textattr(18);
cout<<setw(4)<<""<<"No"<<setw(9)<<""<<char(186)<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(26)<<"";
cout<<char(186)<<"\n"<<setw(25)<<"";
cout<<char(186)<<setw(26)<<""<<char(186);
cout<<"\n"<<setw(25)<<""<<char(200);
for (i=0; i<26; ++i) cout<<char(205);
cout<<char(188);

// Interface Working
gotoxy(10,6);
sound(500);
delay(150);
nosound();
sound(5000);
delay(100);
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
	      case 10 : {
			 sound(5000);
			 delay(120);
			 nosound();
			 sound(400);
			 delay(100);
			 nosound();
			 return 1;
			}
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
return 0;
}
// END OF EXIT TO FUNCTION TO CANCEL REGISTRATION

#endif		/* __CAPTCHA_H*/

// END OF CAPTCHA.H