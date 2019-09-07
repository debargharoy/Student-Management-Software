#include<intrface.h>

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