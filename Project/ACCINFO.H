		/*    Header File
		       ACCINFO.h       	*/



#include<register.h>


Register o;

void account_existence(char usr[])  // For Existence of Account...
{
fstream f;
int i,x;
strupr(usr);
f.open("c:/sms/program/reguser.usr",ios::in|ios::binary);
while(!f.eof())
{
f.read((char*)&o,sizeof(o));
x=strcmp( o.ret_username()  , usr );
if(x==0)
{
f.close();
break;
}
}

}



void account_details( char usnm[] ) //Presentation of Account Info....
{

 clrscr();
 account_existence(usnm);
 char n[100],e[10],inm[50],u[10];
 strcpy( n , o.ret_fname());
 strcat( n , " " );
 strcat( n , o.ret_lname());
 strcpy( e , o.ret_email());
 strcpy( inm , o.ret_iname());
 strcpy( u , o.ret_username());

// FORMATION OF INTERFACE....

_setcursortype(_NOCURSOR);
window(1,1,80,25);
textbackground(7);
clrscr();
textcolor(4);
gotoxy(10,25);
cprintf("Press Any Key To Go Back");
int i,j,m,g;
window(1,1,80,24);
textbackground(0);
textcolor(2);
clrscr();
for(i=5,j=69;i<34;++i,--j)
{
clrscr();
gotoxy(i,2);
cout<<"ACCOUNT";
gotoxy(j,2);
cout<<"INFO.";
delay(30);
}
delay(100);
for(i=31,m=1,j=46;i<40;++i,--j,++m)
{
if(m>7)
{
m=1;
}
textcolor(m);
gotoxy(i,3);
cprintf("-");
gotoxy(j,3);
cprintf("-");
gotoxy(i,1);
cprintf("-");
gotoxy(j,1);
cprintf("-");
delay(80);
}
gotoxy(30,2);
cout<<"|";
gotoxy(47,2);
cout<<"|";
textcolor(6);
for(i=4,j=76;i<41;++i,--j)
{
gotoxy(i,4);
cprintf("-");
gotoxy(j,4);
cprintf("-");
gotoxy(i,23);
cprintf("-");
gotoxy(j,23);
cprintf("-");
delay(40);
}
for(i=5,j=23;i<24;++i,--j)
{
gotoxy(4,i);
cprintf("|");
gotoxy(76,j);
cprintf("|");
delay(60);
}
textcolor(3);
gotoxy(7,8);
delay(250);
cprintf("Email-ID");
gotoxy(7,12);
delay(200);
cprintf("Name");
gotoxy(7,16);
delay(200);
cprintf("Institution Name");
gotoxy(7,20);
delay(200);
cprintf("Username");
for(i=7;i<18;++i)
{
gotoxy(i,9);
cprintf("-");
gotoxy(i,7);
cprintf("-");
delay(70);
}
for(i=7;i<12;++i)
{
gotoxy(i,13);
cprintf("-");
gotoxy(i,11);
cprintf("-");
delay(70);
}
for(i=7;i<24;++i)
{
gotoxy(i,17);
cprintf("-");
gotoxy(i,15);
cprintf("-");
delay(70);
}
for(i=7;i<16;++i)
{
gotoxy(i,21);
cprintf("-");
gotoxy(i,19);
cprintf("-");
delay(70);
}
for(i=8;i<=20;i+=4)
{
gotoxy(6,i);
cprintf("|");
}
gotoxy(17,8);
cprintf("|");
gotoxy(12,12);
cprintf("|");
gotoxy(23,16);
cprintf("|");
gotoxy(15,20);
cprintf("|");
delay(500);
textcolor(4);
for(i=8,g=2;i<=20;i+=4,++g)
{
textcolor(g);
gotoxy(30,i);
cprintf(":-");
delay(80);
}

textcolor(15);
gotoxy(40,8);
cprintf(e);
delay(150);
gotoxy(40,12);
cprintf(n);
delay(150);
gotoxy(40,16);
cprintf(inm);
delay(150);
gotoxy(40,20);
cprintf(u);

for(i=0,g=1;i<28;++g,++i)
{
if(g>7)
{
g=1;
}
textcolor(g);
gotoxy(8,2);
cprintf("%c",1);
gotoxy(10,2);
cprintf("%c",1);
gotoxy(12,2);
cprintf("%c",1);
gotoxy(14,2);
cprintf("%c",1);
gotoxy(71,2);
cprintf("%c",1);
gotoxy(69,2);
cprintf("%c",1);
gotoxy(67,2);
cprintf("%c",1);
gotoxy(65,2);
cprintf("%c",1);
delay(200);
}
//END OF INTERFACE....
getch();
clrscr();
}
