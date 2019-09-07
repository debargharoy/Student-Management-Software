



// Included Header Files

#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<captcha.h>
#include<fstream.h>
#include<direct.h>

// Declaration For ARROW KEYS in Hexadecimal Values

#define UP_ARROW    0x48
#define LEFT_ARROW  0x4B
#define RIGHT_ARROW 0x4D
#define DOWN_ARROW  0x50


// Function Prototypes

int reg_exit_register( void );
void registeraccount( void );
int validate_name( char []);
int validate_iname( char [] );
int validate_email( char [] );
int validate_username( char[] );
void invalid_name( void );
void invalid_email( void );
void invalid_username( void );
void field_missing( void );
void password_mismatch( void );
int write_user( void );
void existing_username( void );
void write_successful( void );
void max_char_name( void );
void max_char_iname( void );
void max_char_username( void );


/****************************************************************************/

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

	int new_register( void );
	char* ret_username( void );
	char* ret_password( void );
};

Register ob;

/*--------------------------------------------------------------------------*/


char* Register::ret_username()
{
 return username;
}

char* Register::ret_password()
{
 return password;
}

// START OF NEW_REGISTER() Class Function

int Register::new_register( void )
{
int count=0;
clrscr();
// Interface OF Function
cout<<endl<<endl;
cout<<setw(29)<<""<<char(1)<<char(2)<<" REGISTER ACCOUNT "<<char(2)<<char(1);
cout<<endl<<endl<<endl;
cout<<setw(10)<<""<<"First Name       : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"Last Name        : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"Institution Name : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"Email-ID^        : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"USERNAME         : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"PASSWORD         : ";
cout<<endl<<endl;
cout<<setw(10)<<""<<"CONFIRM PASSWORD : ";
cout<<endl<<endl<<endl;
cout<<setw(30)<<"";
textcolor(2);
cprintf("PROCEED");
cout<<setw(7)<<"";
textcolor(4);
cprintf("CANCEL");
textcolor(15);

// Working OF Function

char ch; int i=0, verify=0, t_1=0, t_2=0, t_3=0, t_4=0, t_5=0;

// For First Name
place1:
{
 i=0; count=0;
 gotoxy(30,6);
 if(fname[0]!='\0')
 {
  cout<<fname;
  i=strlen(fname);
  if(!(t_1))
  {
   ++t_1;
   goto place2;
  }
 }

 do
 {
  ch=getch();

  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(fname,"\0");
   return 1;
  }

  // Check for Special keys

  if(ch==13)
  {
   fname[i]='\0';
   verify=validate_name(fname);
   if(verify==1)
   {
    strcpy(fname,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==9)
  {
   fname[i]='\0';
   gotoxy(30,6);
   goto place2;
  }

  if(ch==27)
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
  }

  if(ch==8)
  {
   if(i>0)
   {
    cout<<"\b \b";
    --i;
    --count;
    fname[i]='\0';
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

  fname[i]=ch;
  cout<<fname[i];
  ++i;
  ++count;


 }while(1);
}

// For Last Name
place2:
{
 i=0; count=0;
 gotoxy(30,8);
 if(lname[0]!='\0')
 {
  cout<<lname;
  i=strlen(lname);
  if(!(t_2))
  {
   ++t_2;
   goto place3;
  }
 }
 do
 {
  ch=getch();
  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(lname,"\0");
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   lname[i]='\0';
   verify=validate_name(lname);
   if(verify==1)
   {
    strcpy(lname,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   lname[i]='\0';
   gotoxy(30,8);
   goto place3;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  lname[i]=ch;
  cout<<lname[i];
  ++i;
  ++count;

 }while(1);
}

// For Institution Name
place3:
{
 i=0; count=0;
 gotoxy(30,10);
 if(iname[0]!='\0')
 {
  cout<<iname;
  i=strlen(iname);
  if(!(t_3))
  {
   ++t_3;
   goto place4;
  }
 }
 do
 {
  ch=getch();
  if(count==100)
  {
   // Load Extra-Character Function
   max_char_iname();
   strcpy(iname,"\0");
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   iname[i]='\0';
   verify=validate_iname(iname);
   if(verify==1)
   {
    strcpy(iname,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   iname[i]='\0';
   gotoxy(30,10);
   goto place4;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  iname[i]=ch;
  cout<<iname[i];
  ++i;
  ++count;

 }while(1);
}

// For E-Mail
place4:
{
 i=0; count=0;
 gotoxy(30,12);
 if(email[0]!='\0')
 {
  cout<<email;
  i=strlen(email);
  if(!(t_4))
  {
   ++t_4;
   goto place5;
  }
 }
 do
 {
  ch=getch();
  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(email,"\0");
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   email[i]='\0';
   verify=validate_email(email);
   if(verify==1)
   {
    strcpy(email,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   email[i],'\0';
   gotoxy(30,12);
   goto place5;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  email[i]=ch;
  cout<<email[i];
  ++i;
  ++count;

 }while(1);
}

// For Username
place5:
{
 i=0; count=0;
 gotoxy(30,14);
 if(username[0]!='\0')
 {
  cout<<username;
  i=strlen(username);
  if(!(t_5))
  {
   ++t_5;
   goto place6;
  }
 }
 do
 {
  ch=getch();
  if(count==8)
  {
   // Load Extra-Character Function
   max_char_username();
   strcpy(username,"\0");
   t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   username[i]='\0';
   verify=validate_username(username);
   if(verify==1)
   {
    strcpy(username,"\0");
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   username[i]='\0';
   gotoxy(30,14);
   goto place6;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if((ch>=97)&&(ch<=122))
  {
   ch-=32;
  }
  username[i]=ch;
  cout<<username[i];
  ++i;
  ++count;

 }while(1);
}

// For Password
place6:
{
 i=0; count=0;
 gotoxy(30,16);
 do
 {
  ch=getch();
  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(password,"\0");
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   password[i]='\0';
   break;
  }

  if(ch==char(9))
  {
   password[i]='\0';
   gotoxy(30,16);
   goto place7;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

   password[i]=ch;
   cout<<"*";
   ++i;
   ++count;

 }while(1);
}

// For Password Confirmation
place7:
{
 i=0; count=0;
 gotoxy(30,18);
 do
 {
  ch=getch();
  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(confirm_password,"\0");
   return 1;
  }
  // Check for Special keys
  if(ch==13)
  {
   confirm_password[i]='\0';
   if (strcmp(password,confirm_password))
   {
    password_mismatch();
    return 1;
   }
   break;
  }

  if(ch==char(9))
  {
   confirm_password[i]='\0';
   gotoxy(30,18);
   goto place8;
  }

  if(ch==char(27))
  {
   i=reg_exit_register();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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


  confirm_password[i]=ch;
  cout<<"*";
  ++i;
  ++count;

 }while(1);
}

// For Proceed Option
place8:
{
 gotoxy(31,21);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place9;

  case 8 : goto place8;

  case 13: {
	    int cp=0;
	    int a=strlen(fname), b=strlen(lname), c=strlen(iname), g=strlen(email);
	    int d=strlen(username), e=strlen(password), f=strlen(confirm_password);
	    if((a==0)||(b==0)||(c==0)||(d==0)||(e==0)||(f==0))
	    {
	     field_missing();
	     return 1;
	    }

	    verify=0;
	    verify=validate_name(fname);
	    if(verify==1)
	    {
	     strcpy(fname,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     return 1;
	    }

	    verify=0;
	    verify=validate_name(lname);
	    if(verify==1)
	    {
	     strcpy(lname,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     return 1;
	    }

	    verify=0;
	    verify=validate_iname(iname);
	    if(verify==1)
	    {
	     strcpy(iname,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     return 1;
	    }

	    verify=0;
	    if(g!=0)
	    {
	     verify=validate_email(email);
	     if(verify==1)
	     {
	      strcpy(email,"\0");
	      t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	      return 1;
	     }
	    }

	    verify=0;
	    verify=validate_username(username);
	    if(verify==1)
	    {
	     strcpy(username,"\0");
	     return 1;
	    }

	    if (strcmp(password,confirm_password))
	    {
	     password_mismatch();
	     return 1;
	    }


	    cp=captcha(); int temp;
	    if(cp==0)
	    {
	     // Load File Writing Function
	     temp=write_user();
	     if(temp==0)
	     { return 0; }
	     if((temp==1)||(temp==2))
	     { return 1; }
	    }
	    if(cp==1)
	    {
	     clrscr();
	     cout<<"Exiting";
	     return 0;
	    }
	   }

  case 27: {
	    i=reg_exit_register();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case RIGHT_ARROW: goto place9;

  default: goto place8;
 }
}

// For Cancel Option
place9:
{
 gotoxy(45,21);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place1;

  case 8 : goto place9;

  case 13: {
	    i=reg_exit_register();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case 27: {
	    i=reg_exit_register();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case LEFT_ARROW: goto place8;

  default: goto place9;
 }
}
}
// END OF NEW_REGISTER() Class Function

/****************************************************************************/

// START OF REGISTERACCOUNT() Function

void registeraccount()
{
int i;
startoffunction:
clrscr();
window(1,1,80,25);
textbackground(7);
textcolor(4);
_setcursortype(_NORMALCURSOR);
clrscr();
gotoxy(3,25);
cout<<"ESC";
gotoxy(15,25);
cout<<"TAB";
gotoxy(30,25);
cout<<"ENTER";
gotoxy(63,25);
cout<<"^";
textcolor(0);
gotoxy(7,25);
cprintf("-Cancel");
gotoxy(18,25);
cprintf("-Next Field");
gotoxy(35,25);
cprintf("-Input & Move to Next Field");
gotoxy(64,25);
cprintf("-Optional Field");

window(1,1,80,24);
textbackground(0);
textcolor(15);
clrscr();
i=ob.new_register();
if (i==1)
{
 goto startoffunction;
}
}
// END OF REGISTERACCOUNT() Function

/****************************************************************************/

// START DATA VALIDATING FUNCTION DEFINATION

// START OF NAME VALIDATING validate_name() Function

int validate_name( char name[])
{
 int ctr=0;
 for(int i=0; i<strlen(name); ++i)
 {
  ctr=isalpha(name[i]);
  if ((ctr==0)&&(name[i]!=char(32)))
  {
   invalid_name();
   return 1;
  }
 }
 return 0;
}
// END OF validate_name() Function


// START OF Institute Name Validating validate_iname() Function

int validate_iname( char name[])
{
 int ctr=0;
 for(int i=0; i<strlen(name); ++i)
 {
  ctr=isalpha(name[i]);
  if ((ctr==0)&&(name[i]!=char(32))&&(name[i]!=char(58))&&(name[i]!=char(46))&&(name[i]!=char(44))&&(name[i]!=char(45)))
  {
   invalid_name();
   return 1;
  }
 }
return 0;
}
// END OF Institute Name Validating Function


// START OF E-MAIL VALIDATING validate_email() Function

int validate_email( char email[])
{
 int ctr1=0,ctr2=0;
 for(int i=0; i<strlen(email); ++i)
 {
  if(email[i]==char(64)) ++ctr1;
  if(email[i]==char(46)) ++ctr2;
 }
 if(email[0]=='\0')
 {
  return 0;
 }
 if((ctr1==0)||(ctr2==0)||(ctr1>1))
 {
  invalid_email();
  return 1;
 }
 if((ctr1==strlen(email))||(ctr2==strlen(email))||((ctr1+ctr2)==strlen(email)))
 {
  invalid_email();
  return 1;
 }
 return 0;
}
// END OF E-MAIL Validating Function


// START OF USERNAME VALIDATING validate_username() Function

int validate_username( char usname[])
{
 int ctr=0;
 for(int i=0; i<strlen(usname); ++i)
 {
  ctr=isalnum(usname[i]);
  if (ctr==0)
  {
   invalid_username();
   return 1;
  }
 }
 return 0;
}
// END OF USERNAME Validating Function

// END OF DATA VALIDATING FUNCTION DEFINATIONS

/****************************************************************************/

// START OF DATA-ERROR HANDLING FUNCTION DEFINATIONS

// START ERROR-MESSAGE FUNCTION FOR INVALID NAME
void invalid_name( void )
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
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Invalid Name!");
textattr(18);
cout<<setw(9)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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


void invalid_username( void )
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
cout<<char(186)<<setw(7)<<"";
textattr(20);
cprintf("Invalid Username!");
textattr(18);
cout<<setw(6)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(5)<<"";
textattr(20);
cprintf("Space Is Not Allowed!");
textattr(18);
cout<<setw(4)<<""<<char(186);
cout<<"\n";
cout<<setw(24)<<""<<char(186)<<setw(30)<<""<<char(186)<<"\n";
cout<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186)<<"\n";
cout<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<""<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}
// END ERROR-MESSAGE FUNCTION FOR INVALID NAME


// START ERROR-MESSAGE FUNCTION FOR INVALID E-MAIL

void invalid_email( void )
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
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Invalid E-Mail!");
textattr(18);
cout<<setw(7)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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
// END ERROR-MESSAGE FUNCTION FOR INVALID E-MAIL


// START OF FUNCTION TO VALIDATE PRESENCE OF CONPULSORY FIELD

void field_missing( void )
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
cout<<char(186)<<setw(3)<<"";
textattr(20);
cprintf("Compulsory Field Missing!");
textattr(18);
cout<<setw(2)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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
// END OF FUNCTION TO VALIDATE PRESENCE OF CONPULSORY FIELD


// START OF ERROR-FUNCTION DEFINATION IF PASSWORD CONFIRMATION DOES NOT MATCHES WITH PASSWORD

void password_mismatch( void )
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
cout<<char(186)<<setw(3)<<"";
textattr(20);
cprintf("Passwords Do Not Match!");
textattr(18);
cout<<setw(4)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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
// END OF ERROR-FUNCTION DEFINATION IF PASSWORD CONFIRMATION DOES NOT MATCHES WITH PASSWORD

void max_char_name( void )
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
cprintf("Max. Allowed : 50 Characters");
textattr(18);
cout<<setw(1)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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

void max_char_iname( void )
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
cprintf("Max. Allowed : 100 Character");
textattr(18);
cout<<setw(1)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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

void max_char_username( void )
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
cprintf("Max. Allowed : 8 Characters ");
textattr(18);
cout<<setw(1)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(30)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
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

// END OF DATA-ERROR HANDLING FUNCTION DEFINATIONS

/****************************************************************************/

// START OF EXIT FUNCTION TO CANCEL REGISTRATION

int reg_exit_register()
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
// END OF EXIT FUNCTION TO CANCEL REGISTRATION


// START OF WRITEUSER FUNCTION TO WRITE USER DETAILS TAKEN

int write_user()
{
int i=0; Register temp; unsigned char* dirnm;  char dir_str[]={"C:/RMS/USERS/"};
fstream file;
file.open("C:/RMS/RegUser.usr", ios::binary | ios::in | ios::out | ios::app);
if (!file)
{
 return 1;
}
file.seekp(0,ios::end);
i=file.tellp();
i=i/sizeof(ob);
file.seekp(0,ios::beg);
while(i)
{
 file.read((char*)&temp, sizeof(temp));
 if (!(strcmp(temp.ret_username(), ob.ret_username())))
 {
  // Load Same Username Existing Error Function
  existing_username();
  return 2;
 }
 --i;
}
file.write((char*)&ob, sizeof(ob));
// Load File Writing Successful Function
write_successful();
file.close();
file.open("C:/RMS/usnm.rmu", ios::binary|ios::out|ios::app);
file<<ob.ret_username()<<"\n";
file.close();
file.open("C:/RMS/0x706173.rmp", ios::binary|ios::out|ios::app);
file<<ob.ret_password()<<"\n";
file.close();
strcat(dir_str,ob.ret_username());
mkdir(dir_str);
return 0;
}



void existing_username( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,57,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<31; ++i) cout<<char(205);
cout<<char(187)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(31)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(0)<<"";
textattr(20);
cprintf("Sorry! Username Already Exists.");
textattr(18);
cout<<setw(0)<<""<<char(186)<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(31)<<""<<char(186);
cout<<"\n"<<setw(24)<<"";
cout<<char(186)<<setw(0)<<"";
textattr(20);
cprintf("Please Select Another Username.");
textattr(18);
cout<<setw(0)<<""<<char(186);
cout<<"\n";
cout<<setw(24)<<""<<char(186)<<setw(31)<<""<<char(186)<<"\n";
cout<<setw(24)<<"";
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(1)<<""<<char(186)<<"\n";
cout<<setw(24)<<"";
cout<<char(186)<<setw(31)<<""<<char(186);
cout<<"\n"<<setw(24)<<""<<char(200);
for (i=0; i<31; ++i) cout<<char(205);
cout<<char(188);
getch();
}

void write_successful()
{
window(1,1,80,25);
textbackground(7);
clrscr();
window(1,1,80,24);
textbackground(0);
textcolor(15);
clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<setw(18)<<""<<char(2)<<char(1);
textattr(2);
cprintf(" Congratulation !! Registration Successful ");
cout<<char(1)<<char(2);
cout<<endl<<endl<<endl<<endl<<endl;
textattr(5);
cout<<setw(18)<<"";
cprintf("Thank You For Being An End-User Of Our Software");
cout<<endl<<endl<<endl<<endl<<endl;
cout<<setw(18)<<""<<char(2)<<char(1);
textattr(3);
cprintf(" We Wish You A Pleasant Experience With Us ");
cout<<char(1)<<char(2);
cout<<endl<<endl<<endl<<endl<<endl;
cout<<setw(26)<<"";
textattr(134);
cprintf("Press Any Key To Continue...");
textattr(26);
getch();
}

void main()
{
registeraccount();
}