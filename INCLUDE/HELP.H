
				/*---------
				   HELP.H
				 ---------*/


#ifndef __HELP_H
#define __HELP_H



// INCLUDED HEADER FILES

#include<global.h>


// FUNCTION PROTOTYPES

int main_help();
void show_pg1();
void show_pg2();
void show_pg3();


// FUNCTION DEFINATIONS

void show_pg1()
{
clrscr();
fstream file;
file.open("C:/SMS/PROGRAM/help.hlp", ios::binary|ios::in);
char arr[64]={"\0"};
gotoxy(2,2);
for(int i=2; i<22; ++i)
{
file.getline(arr,60,'\n');
cout<<arr;
gotoxy(2,i+1);
}
file.close();
}

void show_pg2()
{
clrscr();
fstream file;
file.open("C:/SMS/PROGRAM/help.hlp", ios::binary|ios::in);
char arr[64]={"\0"};
for(int i=2; i<21; ++i)
{
file.getline(arr,60,'\n');
}
gotoxy(39,2);
cout<<"            ";
gotoxy(2,3);
for(i=2; i<22; ++i)
{
file.getline(arr,60,'\n');
cout<<arr;
gotoxy(2,i);
}
file.close();
}


void show_pg3()
{
clrscr();
fstream file;
file.open("C:/SMS/PROGRAM/count.ct", ios::out|ios::trunc);
file<<1;
file.close();
file.open("C:/SMS/PROGRAM/help.hlp", ios::binary|ios::in);
char arr[64]={"\0"};
for(int i=2; i<21; ++i)
{
file.getline(arr,60,'\n');
}
gotoxy(39,2);
cout<<"            ";
gotoxy(1,3);
for(i=2; i<21; ++i)
{
file.getline(arr,65,'\n');
}

for(i=1; i<22; ++i)
{
file.getline(arr,65,'\n');
cout<<arr;
gotoxy(2,i);
}
file.close();
gotoxy(1,3);
cout<<" ";
textattr(20);
gotoxy(2,13); cprintf(" softtechnetwork@gmail.com");
gotoxy(2,15); cprintf(" Necessary Source File(s) Missing     " );
gotoxy(2,17); cprintf(" http://www.softtechnet.webege.com");
textattr(18);
}


int main_help()
{
window(8,1,72,24);
textbackground(1);
textcolor(2);
_setcursortype(_NOCURSOR);
clrscr();
textattr(31);
cprintf("%c",201);
for(int i=0; i<29; ++i)
{
cprintf("%c",205);
}
cprintf(" HELP ");
for(i=0; i<28; ++i)
{
cprintf("%c",205);
}
cprintf("%c",187);
for(i=2; i<23; ++i)
{
cprintf("%c",219);
gotoxy(65,i);
cprintf("%c",219);
}
cprintf("%c",200);
for( i=0; i<20; ++i)
{
cprintf("%c",174);
}
cprintf("  ARROW KEYS-Navigate  ");
for( i=0; i<20; ++i)
{
cprintf("%c",175);
}
cprintf("%c",188);
window(9,2,71,22);
textcolor(2);
textbackground(1);
clrscr();
unsigned char a;
i=0;
show_pg1();
do{
a=getch();
if(a==0x00)
a=getch();
switch(a)
{
 case UP_ARROW : if(i==0){ break;}
		 if(i==1){ show_pg1(); i=0;  break;}
		 if(i==2){ show_pg2(); i=1;  break;}

 case DOWN_ARROW : if(i==0){ show_pg2(); i=1;  break;}
		   if(i==1){ show_pg3(); i=2;  break;}
		   if(i==2){ break; }

 case LEFT_ARROW : if(i==0){ break;}
		   if(i==1){ show_pg1(); i=0;  break;}
		   if(i==2){ show_pg2(); i=1;  break;}

 case RIGHT_ARROW : if(i==0){ show_pg2(); i=1;  break;}
		    if(i==1){ show_pg3(); i=2;  break;}
		    if(i==2){ break;}

 case 27 : return 0;
}
}while(1);
}

#endif		/* __HELP_H*/

// END OF HELP.H