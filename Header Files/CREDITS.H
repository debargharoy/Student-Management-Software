
			      /*-----------
				 CREDITS.H
				-----------*/

#ifndef __CREDITS_H
#define __CREDITS_H


// INCLUDED HEADER FILE

#include<global.h>


// FUNCTION PROTOTYPES

int prj ( void );
int ifdesig ( void );
int ifdev ( void );
int progrmer ( void );
int qa ( void );
int spthx ( void );
void credits ( void );


// GLOBAL VARIABLES

char content[100];
int i=0;
/****************************************************************************/

// FUNCTION DEFINATIONS

void credits()
{
char a=0;
strcpy(content,"\0");
window(20,7,60,9);
textbackground(2);
textcolor(0);
clrscr();
gotoxy(18,2);
cout<<"Credits";
window(20,10,60,19);
textbackground(0);
textcolor(2);
clrscr();
for(int i=1; i<10; ++i)
{
 gotoxy(1,i);
 cout<<char(219);
 gotoxy(41,i);
 cout<<char(219);
}
gotoxy(1,10);
for(i=0; i<41; ++i)
{
 cout<<char(219);
}
window(21,10,59,18);
textcolor(2);
textbackground(0);
do
{
 a=prj(); if(a) break;
 a=ifdesig(); if(a) break;
 a=ifdev(); if(a) break;
 a=progrmer(); if(a) break;
 a=qa(); if(a) break;
 a=spthx(); if(a) break;
}while(1);
}



int prj ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/prj.cdt", ios::binary|ios::in);

gotoxy(13,2);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(16,4);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(13,6);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(15,8);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}
file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}



int ifdesig ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/ifdesig.cdt", ios::binary|ios::in);

gotoxy(12,2);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,5);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,5);
file.getline(content, 100, '\n');
while(content[i])
{
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}
file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}



int ifdev ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/ifdev.cdt", ios::binary|ios::in);

gotoxy(10,2);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,5);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,5);
file.getline(content, 100, '\n');
while(content[i])
{
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}
file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}



int progrmer ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/progrmer.cdt", ios::binary|ios::in);

gotoxy(15,2);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,5);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,5);
file.getline(content, 100, '\n');
while(content[i])
{
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}
file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}



int qa ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/qa.cdt", ios::binary|ios::in);

gotoxy(9,2);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,5);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,5);
file.getline(content, 100, '\n');
while(content[i])
{
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(2,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(30,7);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}
file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}



int spthx ( void )
{
clrscr();
_setcursortype(_SOLIDCURSOR);
fstream file; i=0;
file.open("C:/SMS/PROGRAM/CREDITS/spthx.cdt", ios::binary|ios::in);

gotoxy(13,3);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(6);
 cprintf("%c",content[i]);
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

i=0;
gotoxy(5,6);
file.getline(content, 100, '\n');
while(content[i])
{
 textattr(2);
 cout<<content[i];
 ++i;
 if(kbhit()) return 1;
 delay(80);
}

file.close();
_setcursortype(_NOCURSOR);
if(kbhit()) return 1;
delay(1000);
return 0;
}

#endif		/* __CREDITS_H*/

// END OF CREDITS.H