#include<global.h>
#include<math.h>

void main()
{
clrscr();
fstream f, file;
char s[2];
int i,j,num=0,k,a,x;
f.open("help.SRC",ios::in|ios::binary);
file.open("C:/help.hlp", ios::binary|ios::out);
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
cout<<"Success";
}
f.close();
getch();
}