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


/****************************************************************


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

int settings(char name[])
{
char bgcolor_name[15], textcolor_name[15], a;
int i=8, j=0, k=35, temp_count=0;
int temp_bg, temp_text, _textcolor=text_color, _bgcolor=bgcolor, temp;
do{
switch(_bgcolor)
{
 case 0 : strcpy(bgcolor_name,color[0]); break;
 case 1 : strcpy(bgcolor_name,color[1]); break;
 case 2 : strcpy(bgcolor_name,color[2]); break;
 case 3 : strcpy(bgcolor_name,color[3]); break;
 case 4 : strcpy(bgcolor_name,color[4]); break;
 case 5 : strcpy(bgcolor_name,color[5]); break;
 case 6 : strcpy(bgcolor_name,color[6]); break;
 case 7 : strcpy(bgcolor_name,color[7]); break;
 case 15: strcpy(bgcolor_name,color[8]); break;
}
switch(_textcolor)
{
 case 0 : strcpy(textcolor_name,color[0]); break;
 case 1 : strcpy(textcolor_name,color[1]); break;
 case 2 : strcpy(textcolor_name,color[2]); break;
 case 3 : strcpy(textcolor_name,color[3]); break;
 case 4 : strcpy(textcolor_name,color[4]); break;
 case 5 : strcpy(textcolor_name,color[5]); break;
 case 6 : strcpy(textcolor_name,color[6]); break;
 case 7 : strcpy(textcolor_name,color[7]); break;
 case 15: strcpy(textcolor_name,color[8]); break;
}

window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(12,25);
cout<<"ARROW-KEY";
gotoxy(33,25);
cout<<"TAB";
gotoxy(51,25);
cout<<"ENTER";
textcolor(0);
gotoxy(21,25);
cprintf("-NAVIGATE");
gotoxy(36,25);
cprintf("-Next Option");
gotoxy(56,25);
cprintf("-SELECT OPTION");
window(1,1,80,24);
textbackground(3);
textcolor(0);
clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<setw(33)<<""<<char(2)<<char(1)<<" ";
textattr(52);
cprintf("SETTINGS");
cout<<" "<<char(1)<<char(2);
cout<<endl<<endl<<endl;
cout<<setw(30)<<""<<"Background-Color : "<<bgcolor_name;
cout<<endl<<endl<<endl;
cout<<setw(30)<<""<<"Text-Color"<<setw(7)<<""<<": "<<textcolor_name;
cout<<endl<<endl<<endl;
cout<<setw(30)<<""<<"Password"<<setw(9)<<""<<": Change Password";
cout<<endl<<endl<<endl;
cout<<setw(33)<<"";
textattr(17);
for(int x=0; x<3; ++x)
{
 for(int y=0; y<6; ++y)
 {
  cprintf("%c",219);
 }
 cout<<setw(5)<<"";
 for( y=0; y<9; ++y)
 {
  cprintf("%c",219);
 }
 cout<<endl<<setw(33)<<"";
}
textattr(18);
gotoxy(35,18);
cprintf("Save");
gotoxy(46,18);
cprintf("Discard");
gotoxy(54,18);
textattr(48);
_setcursortype(_SOLIDCURSOR);


 if (j==0) gotoxy(50,i);
 if (j==1) gotoxy(k,18);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case UP_ARROW: {
		  if ((i>8)&&(j==0))
		  {
		   i-=3;
		  }
		 } break;


  case DOWN_ARROW: {
		    if ((i<14)&&(j==0))
		    {
		     i+=3;
		    }
		   } break;

  case LEFT_ARROW: {
		    if((k>35)&&(j==1))
		    {
		     k-=11;
		    }
		   } break;

  case RIGHT_ARROW: {
		     if((k<46)&&(j==1))
		     {
		      k+=11;
		     }
		    } break;

  case 9  : {
	     if(j==0)
	     {
	      gotoxy(35,18);
	      j=1; break;
	     }
	     if(j==1)
	     {
	      gotoxy(50,18);
	      j=0; break;
	     }
	    } break;

  case 13 : {
	     if(j==0)
	     {
	      switch(i)
	      {
	       case 8 :  // Load BGCOLOR Changing Function
			{
			 temp_bg=change_color();
			 if(temp_bg!=(-1))
			 { _bgcolor=temp_bg; }
			}
			break;

	       case 11 :  // Load TEXTCOLOR Changing Function
			 {
			  temp_text=change_color();
			  if(temp_text!=(-1))
			  { _textcolor=temp_text; }
			 }
			 break;

	       case 14 : // Load Password Changing Function
			 {
			  temp=change_password();
			 }
			 break;
	      }break;
	     }

	     if(j==1)
	     {
	      switch(k)
	      {
	       case 35 : // Load Function To Save Data
			 {
			  // For Color
			  strcat(name,"/CONFIG.cfg");
			  strcat(dir,name);
			  file.open(dir, ios::binary|ios::out) ;
			  file<<_bgcolor<<"\n"<<_textcolor;
			  file.close();
			  // For Password
			  if(temp==0)
			  {
			   file.open("C:/SMS/USERS/usnm.unl", ios::in);
			   int c=0; char temp_nm[50];
			   while(file)
			   {
			    ++c;
			    file.getline(temp_nm, 8, '\n');
			    if(!(strcmp(name,temp_nm)))
			    {
			     temp_count=c;
			     break;
			    }
			   }
			   file.close();
			   c=0;
			   if(temp_count>0)
			   {
			    file.open("C:/SMS/USERS/0x706173.pad", ios::binary|ios::in);
			    fstream temp_file;
			    temp_file.open("C:/SMS/USERS/temp.pad", ios::binary|ios::out);
			    while(file)
			    {
			     ++c;
			     temp_file.getline(temp_pass, 50, '\n');
			     if(c==temp_count)
			     {
			      temp_file<<conf_temp<<"\n";
			     }
			     else
			     {
			      temp_file<<temp_pass<<"\n";
			     }
			    }
			    temp_file.close();
			    file.close();
			    remove("C:/SMS/USERS/0x706173.pad");
			    rename("C:/SMS/USERS/temp.pad","C:/SMS/USERS/0x706173.pad");
			   }
			   return 1;
			  }
			 }
	       case 46 : // Load Function To Discard Changes And Exit
			 return 0;

	      }break;
	     }
	    }

  case 27 : return 0;

 }
}while(1);
}

int change_color()
{
window(25,2,55,23);
textbackground(1);
textcolor(15);
clrscr();
cout<<char(201);
for(int i=0; i<10; ++i) cout<<char(205);
cout<<" COLORS ";
for( i=0; i<11; ++i) cout<<char(205);
cout<<char(187);
for(i=2; i<22; ++i)
{
gotoxy(1,i);
cout<<char(186)<<setw(29)<<""<<char(186);
}
gotoxy(1,i);
cout<<char(200);
for(i=0; i<29; ++i) cout<<char(205);
cout<<char(188);
int j;

window(33,4,35,22);
textbackground(0);
clrscr();
for( i=0, j=2; i<8; ++i, j+=2)
{
 gotoxy(2,j);
 textattr(i);
 cprintf("%c",219);
}
gotoxy(2,18);
textattr(15);
cprintf("%c",219);

window(37,4,54,22);
textbackground(1);
textcolor(15);
clrscr();
for( i=0, j=2; i<8; ++i, j+=2)
{
 gotoxy(1,j);
 cout<<" - "<<color[i];
}
gotoxy(1,j);
cout<<" - "<<color[i];

_setcursortype(_SOLIDCURSOR);
i=2;
do
{
 gotoxy(4,i);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case UP_ARROW: {
		  if (i>2)
		  {
		   i-=2;
		  }
		 } break;

  case DOWN_ARROW: {
		    if (i<18)
		    {
		     i+=2;
		    }
		   } break;
  case 13 : {
	     switch(i)
	     {
	      case 2 : return 0;
	      case 4 : return 1;
	      case 6 : return 2;
	      case 8 : return 3;
	      case 10: return 4;
	      case 12: return 5;
	      case 14: return 6;
	      case 16: return 7;
	      case 18: return 15;
	     }
	    }
  case 27 : return -1;
 }
}while(1);
}


int change_password()
{
startoffunction:
window(13,8,67,16);
textbackground(1);
textcolor(15);
_setcursortype(_NORMALCURSOR);
clrscr();
cout<<char(201);
for(int i=0; i<18; ++i) cout<<char(205);
cout<<" Change Password ";
for( i=0; i<18; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(2)<<"";
cout<<"New Password";
gotoxy(21,3);
cout<<":"<<setw(33)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(2)<<"";
cout<<"Confirm Password : "<<setw(32)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(18)<<"";
textcolor(2);
cprintf("Confirm");
textcolor(15);
cout<<setw(4)<<"";
textcolor(4);
cprintf("Cancel");
textcolor(15);
cout<<setw(18)<<""<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(53)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for(i=0; i<53; ++i) cout<<char(205);
cout<<char(188);

// Function Working

char ch;
i=0; int count=0;

// For New Password
place1:
{
 i=0; count=0;
 gotoxy(23,3);

 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   temp_pass[i]='\0';
   goto place2;
  }

  if(ch==char(9))
  {
   temp_pass[i]='\0';
   gotoxy(23,3);
   goto place2;
  }

  if(ch==char(27))
  {
   return 1;
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

  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(temp_pass,"\0");
   goto startoffunction;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   temp_pass[i]=ch;
   cout<<"*";
   ++i;
   ++count;
  }
 }while(1);
}

// For Password
place2:
{
 i=0; count=0;
 gotoxy(23,5);
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   conf_temp[i]='\0';
   break;
  }

  if(ch==char(9))
  {
   conf_temp[i]='\0';
   gotoxy(15,5);
   goto place3;
  }

  if(ch==char(27))
  {
   return 1;
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

  if(count==50)
  {
   // Load Extra-Character Function
   max_char_name();
   strcpy(conf_temp,"\0");
   goto startoffunction;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   conf_temp[i]=ch;
   cout<<"*";
   ++i;
   ++count;
  }
 }while(1);
}

// For Confirm Option
place3:
{
 count=0;
 gotoxy(20,7);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place4;

  case 8 : goto place3;

  case 13: {
	    int d=strlen(temp_pass), e=strlen(conf_temp);
	    if((d==0)||(e==0))
	    {
	     field_missing();
	     goto startoffunction;
	    }

	    if (strcmp(temp_pass,conf_temp))
	    {
	     password_mismatch();
	     ++count;
	    }

	    if(count)
	    {
	     goto startoffunction;
	    }
	    return 0;
	   }

  case 27: {
	    return 1;
	   }

  case RIGHT_ARROW: goto place4;

  default: goto place3;
 }
}

// For Cancel Option
place4:
{
 gotoxy(31,7);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place1;

  case 8 : goto place4;

  case 13: {
	    return 1;
	   }

  case 27: {
	    return 1;
	   }

  case LEFT_ARROW: goto place3;

  default: goto place4;
 }
}
}
*/

