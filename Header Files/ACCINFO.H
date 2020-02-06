#ifndef  __ACCINFO_H
#define  __ACCINFO_H


void show_acc_details(char usnm[], int bgcolor, int txtcolor)
{

class Register
{
char fname[50], lname[50], iname[100], email[50], username[8], password[50];
char confirm_password[50];

 public:
	Register()
	{
	 strcpy(fname,"\0");
	 strcpy(lname,"\0");
	 strcpy(iname,"\0");
	 strcpy(email,"\0");
	 strcpy(username,"\0");
	 strcpy(password,"\0");
	 strcpy(confirm_password,"\0");
	}

	char* ret_username( void ) { return username; }
	char* ret_iname( void )    { return iname;    }
	char* ret_fname( void )    { return fname;    }
	char* ret_lname( void )    { return lname;    }
	char* ret_email( void )    { return email;    }
};

Register ob;
fstream file;
file.open("C:/SMS/PROGRAM/REGUSER.USR", ios::binary|ios::in);
while(file)
{
file.read((char*)&ob, sizeof(ob));
if(strcmp(ob.ret_username(), usnm)==0)
break;
}

clrscr();
window(1,1,80,25);
textbackground(7);
clrscr();
gotoxy(5,25);
textattr(240);
cprintf("PRESS ANY KEY TO GO BACK TO MENU");

window(1,1,80,24);
textcolor(txtcolor);
textbackground(bgcolor);
_setcursortype(_NOCURSOR);
clrscr();
delay(500);
for(int i=5,j=69;i<34;++i,--j)
{
clrscr();
gotoxy(i,2);
cout<<"ACCOUNT";
gotoxy(j,2);
cout<<"INFO.";
delay(30);
}
int m;
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
gotoxy(7,8);
cout<<"Username  : "<<ob.ret_username();
delay(150);
gotoxy(7,12);
cout<<"Name      : "<<ob.ret_fname()<<" "<<ob.ret_lname();
delay(150);
gotoxy(7,15);
cout<<"Institute : "<<ob.ret_iname();
delay(150);
gotoxy(7,19);
cout<<"E-Mail    : "<<ob.ret_email();
getch();
}

#endif		/* __ACCINFO_H*/

// END OF ACCINFO.H