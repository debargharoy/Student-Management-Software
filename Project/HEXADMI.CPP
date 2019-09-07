#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
unsigned char ch;
while ((ch=getch()) != 13)
{
 printf("%02X\n",ch);
}
}
