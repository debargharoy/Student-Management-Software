#include<global.h>
#include<math.h>

void main()
{
clrscr();
fstream f;
char s[2];
int i,j,num=0,k,a,x;
f.open("e:/RAHUL.DAT",ios::in|ios::binary);
while(f)
{
f.read((char*)&s,sizeof(s));
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
cout<<char(num);
num=0;
}
f.close();
getch();
}