#include<global.h>
#include<math.h>
void main()
{
fstream file,f;
char s[2];
int i,j,num=0,k,a,x;

// FOR SMS DIRECTORY
file.open("C:/SMS/try56.tmp", ios::in);
if(!file)
{
 mkdir("C:/SMS");
}
else{ file.close(); remove("C:/SMS/try56.tmp"); }

// FOR SMS/PROGRAM DIRECTORY
file.open("C:/SMS/PROGRAM/try56.tmp", ios::in);
if(!file)
{
 mkdir("C:/SMS/PROGRAM");
}
else{ file.close(); remove("C:/SMS/PROGRAM/try56.tmp"); }

// FOR SMS/USERS DIRECTORY
file.open("C:/SMS/USERS/try56.tmp", ios::in);
if(!file)
{
 mkdir("C:/SMS/USERS");
}
else{ file.close(); remove("C:/SMS/USERS/try56.tmp"); }


// FOR CREDITS DIRECTORY
file.open("C:/SMS/PROGRAM/CREDITS/try56.tmp", ios::in);
if(!file)
{
 mkdir("C:/SMS/PROGRAM/CREDITS");
}
else{ file.close(); remove("C:/SMS/PROGRAM/CREDITS/try56.tmp"); }


// FOR SOURCE DIRECTORY
file.open("C:/SMS/PROGRAM/SOURCE/try56.tmp", ios::in);
if(!file)
{
 mkdir("C:/SMS/PROGRAM/SOURCE");
}
else{ file.close(); remove("C:/SMS/PROGRAM/SOURCE/try56.tmp"); }

// FOR HELP FILE
f.open("PRJFILES/help.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/help.hlp", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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


// FOR CREDITS FILE

// FOR IFDESIG.CDT
f.open("PRJFILES/IFDESIG.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/ifdesig.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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

// FOR IFDEV.CDT
f.open("PRJFILES/IFDEV.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/IFDEV.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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

// FOR PRJ.CDT
f.open("PRJFILES/PRJ.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/PRJ.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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

// FOR PROGRMER.CDT
f.open("PRJFILES/PROGRMER.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/PROGRMER.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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

// FOR QA.CDT
f.open("PRJFILES/QA.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/QA.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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

// FOR SPTHX.CDT
f.open("PRJFILES/SPTHX.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/CREDITS/SPTHX.cdt", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
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


// FOR HEADER FILES


// FOR ACCINFO.SRC
f.open("PRJFILES/ACCINFO.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/ACCINFO.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR CAPTCHA.SRC
f.open("PRJFILES/CAPTCHA.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/CAPTCHA.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();

// FOR CREDITS.SRC
f.open("PRJFILES/CREDITS.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/CREDITS.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR GLOBAL.SRC
f.open("PRJFILES/GLOBAL.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/GLOBAL.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR INTRFACE.SRC
f.open("PRJFILES/INTRFACE.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/INTRFACE.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR LGINTRUE.SRC
f.open("PRJFILES/LGINTRUE.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/LGINTRUE.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR LOGIN.SRC
f.open("PRJFILES/LOGIN.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/LOGIN.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR LOGOUT.SRC
f.open("PRJFILES/LOGOUT.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/LOGOUT.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR RECORDS.SRC
f.open("PRJFILES/RECORDS.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/RECORDS.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR REGISTER.SRC
f.open("PRJFILES/REGISTER.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/REGISTER.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR SETTINGS.SRC
f.open("PRJFILES/SETTINGS.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/SETTINGS.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();


// FOR C++ (CPP) FILE

// FOR SMS.SRC
f.open("PRJFILES/SMS.SRC",ios::in|ios::binary);
file.open("C:/SMS/PROGRAM/SOURCE/SMS.SRC", ios::binary|ios::out);
while(f.read((char*)&s,sizeof(s)))
{
file.write((char*)&s, sizeof(s));
}
f.close();
file.close();

// INTERFACE TO SHOW INSTALLATION
window(1,1,80,25);
textbackground(0);
textcolor(2);
_setcursortype(_NOCURSOR);
clrscr();
textcolor(15);
gotoxy(33,13);
cprintf("Please Wait...");
sleep(2);
clrscr();
gotoxy(30,10);
cprintf("Student Management Software");
gotoxy(15,12);
cout<<"Status : Initializing";
for(i=0; i<4; ++i) { cout<<"."; delay(800);}
gotoxy(15,12);
clreol();
cout<<"Status : Installing...";
window(25,16,55,16);
textbackground(1);
textcolor(15);
_setcursortype(_NOCURSOR);
clrscr();
delay(1000);
for(i=0; i<31; ++i)
{
 cout<<char(219);
 delay(100);
}
window(1,1,80,25);
textbackground(0);
textcolor(2);
clrscr();
textcolor(15);
gotoxy(30,10);
cprintf("Student Management Software");
gotoxy(15,12);
cout<<"Status : Completed";
gotoxy(35,15);
textcolor(15);
cprintf("Thank You");
gotoxy(28,17);
cprintf("\n\nPress Any Key To Exit...");
getch();
}