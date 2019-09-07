
/*


PROGRAM TO CONVERT HEXADECIMAL VALUES TO DECIMAL AND DISPLAY IT ON THE SCREEN..


*/
		/* MAKE SURE YOU HAVE HEADER FILE - global.h     */


#include<global.h>
#include<math.h>

void main()
{
clrscr();
fstream f;
char s[2]; // Array to get characters.
int i,j,num=0,k,a,x;
f.open("e:/ACCINFO.SRC",ios::in|ios::binary); // Specify File and its Location.
while(f)
{
f.read((char*)&s,sizeof(s));  // Reading two characters each time.
for(i=0,j=1;i<2;++i,--j)
{
			     //             ____  ______  _____   ______
 if(s[i]>=48&&s[i]<=57)       //   |       |   |  |         |     |
 {                           //    |       |   |  |         |     |
 a=int(s[i])-48;              //   |       |   |  |         |     |
 }                          //     |       |   |  |  __     |     |
 if(s[i]>=65&&s[i]<=70)      //    |       |   |  |  | |    |     |
 {                           //    |______ |___|  |__| |  __|___  |_____
 a=int(s[i])-55;
 }
 k=pow(16,j);
 num+=a*k;
}
cout<<char(num); // num is the decimal value of the character to be printed.
num=0;
delay(3);
}
f.close();
getch();
}