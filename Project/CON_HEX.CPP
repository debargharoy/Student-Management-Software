#include<fstream.h>
#include<conio.h>
#include<process.h>
void main()
{
clrscr();
fstream ifile,ofile;
ifile.open("help.txt", ios::in);
ofile.open("help2.txt", ios::out|ios::trunc);
if(!(ifile&&ofile))
{
cout<<"Error";
getch();
exit(1);
}
while(ifile)
{
char a;
ifile.get(a);
int temp=0, i=2; char b[2];
while(i)
{
temp=a%16;
a/=16;
switch(temp)
{
 case 0 : temp='0'; break;
 case 1 : temp='1'; break;
 case 2 : temp='2'; break;
 case 3 : temp='3'; break;
 case 4 : temp='4'; break;
 case 5 : temp='5'; break;
 case 6 : temp='6'; break;
 case 7 : temp='7'; break;
 case 8 : temp='8'; break;
 case 9 : temp='9'; break;
 case 10: temp='A'; break;
 case 11: temp='B'; break;
 case 12: temp='C'; break;
 case 13: temp='D'; break;
 case 14: temp='E'; break;
 case 15: temp='F'; break;
}
--i;
b[i]=temp;
}
ofile<<b[0]<<b[1];
}
cout<<"Success";
getch();
}