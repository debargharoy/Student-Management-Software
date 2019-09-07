#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<bios.h>

#define UP_ARROW    0x48
#define LEFT_ARROW  0x4B
#define RIGHT_ARROW 0x4D
#define DOWN_ARROW  0x50

void main()
{

for (int i=0; i<5; ++i)
{
unsigned char ch=getch();
if(ch==0x00)
ch=getch();
switch(ch)
{
case UP_ARROW: cout<<"UP";break;
case DOWN_ARROW:cout<<"Down";break;
case LEFT_ARROW: cout<<"LEFT"; break;
case RIGHT_ARROW: cout<<"RIGHT"; break;
}
getch();
}
}