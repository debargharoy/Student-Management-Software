
			       /*-----------
				  LOGOUT.H
				------------*/
#ifndef __LOGOUT_H
#define __LOGOUT_H


#include<global.h>

void logout( void );

// LOGOUT FUNCTION

void logout()
{
 window(1,1,80,25);
 textbackground(7);
 textcolor(0);
 clrscr();
 window(1,1,80,25);
 textcolor(15);
 textbackground(0);
 clrscr();
 cout<<endl<<endl<<endl;
 cout<<setw(24)<<""<<"Thank You For Using The Software"<<endl;
 cout<<endl<<endl<<endl;
 cout<<setw(34)<<""<<"Logging-Out!"<<endl;
 cout<<endl<<endl<<endl;
 cout<<setw(33)<<""<<"Please Wait";
 textattr(143);
 cprintf("...");
 textattr(15);
 cout<<endl<<endl<<endl;
 window(25,16,55,16);
 textbackground(1);
 textcolor(15);
 _setcursortype(_NOCURSOR);
 clrscr();
 delay(1000);
 for(int i=0; i<31; ++i)
 {
  cout<<char(219);
  delay(100);
 }
}

#endif		/* __LOGOUT_H*/

// END OF LOGOUT.H