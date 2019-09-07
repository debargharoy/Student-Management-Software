			      /*-------------
				  RECORDS.H
				------------*/

#ifndef __RECORDS_H
#define __RECORDS_H


// INCLUDED HEADER FILES
//#include<settings.h>
//#include<register.h>

void far function()
{
// FUNCTION PROTOTYPES

int records( char [], int , int );
int exit_create_record ( void );                 // EXIT RECORD CREATION
int create_student_record ( char [], int , int );// CREATE STUDENT RECORD
int write_student_record ( char [] );            // WRITE NEW RECORD TO FILE BY SORTING
int write_modified_student_record( char [] );    // WRITE MODIFIED STUDENT RECORD
int confirm_replace ( void );                    // CONFIRM REPLACEMENT OF RECORD WITH SAME ID
int search ( char [], int, int );                // SEARCH RECORDS
int search_id ( char [], int, int );             // SEARCH BY ID
int search_name( char [], int , int );           // SEARCH BY NAME
int search_standard( char [], int, int );        // SEARCH BY STANDARD/CLASS
int search_section( char [], int, int );         // SEARCH BY SECTION
int validate_sname ( char [] );                  // VALIDATE STUDENT NAME
int validate_standard ( char [] );               // VALIDATE STANDARD
int validate_section ( char [] );                // VALIDATE SECTION
int validate_percentage ( char [] );             // VALIDATE PERCENTAGE(%)
void max_char_id ( void );                       // MAXIMUM ID STRING LENGTH
void max_char_standard ( void );                 // MAXIMUM STANDARD STRING LENGTH
void max_char_comment ( void );                  // MAXIMUM COMMENT STRING LENGTH
void max_char_sname ( void );                    // MAXIMUM NAME STRING LENGTH
void invalid_sname ( void );                     // FLAGS ERROR FOR ERROR IN NAME
void invalid_standard ( void );                  // FLAGS ERROR FOR ERROR IN STANDARD
void invalid_section ( void );                   // FLAGS ERROR FOR ERROR IN SECTION
void invalid_percentage ( void );                // FLAGS ERROR FOR ERROR IN PERCENTAGE
void delete_record ( char [],char [], int );     // DELETE RECORD
void modify_record ( char [] );                  // MODIFY RECORD
void rec_field_missing ( void );                 // FLAGS ERROR IF COMPULSORY FILED IS MISSING


/****************************************************************************/
class far Student
{
char id[10], name[50], standard[5], section[5], comment[1024], per[5];

public:

Student()
{
strcpy(id,"\0");
strcpy(name,"\0");
strcpy(standard,"\0");
strcpy(section,"\0");
strcpy(per,"\0");
strcpy(comment,"\0");
}

void delet()
{
strcpy(id,"\0");
strcpy(name,"\0");
strcpy(standard,"\0");
strcpy(section,"\0");
strcpy(per,"\0");
strcpy(comment,"\0");
}

int create_record( char [] );
int show_record( int );
int show_details( char [], int, int , int );
int show_search_details( int, int, int );
int mod_record( char [] );
char* ret_id();
char* ret_nm();
char* ret_standard();
char* ret_section();
char* ret_comment();
};

Student far record, temp_record;

/****************************************************************************/

// START OF FUNCTION DEFINATIONS


char* Student::ret_id()
{
return id;
}

/*==========================================================================*/

char* Student::ret_nm()
{
return name;
}

/*==========================================================================*/

char* Student::ret_standard()
{
return standard;
}

/*==========================================================================*/

char* Student::ret_section()
{
return section;
}

/*==========================================================================*/

char* Student::ret_comment()
{
return comment;
}

/*==========================================================================
  ==========================================================================*/

int Student::show_details(char temp_dir[], int id_count, int bgcolor, int txtcolor)
{
window(1,1,80,25);
textbackground(7);
textcolor(5);
clrscr();
gotoxy(10,25);
cout<<"EDITING DISABLED";
textcolor(4);
gotoxy(34,25);
cprintf("ESC");
textcolor(0);
gotoxy(37,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
_setcursortype(_NOCURSOR);
clrscr();
fstream file;
file.open(temp_dir, ios::binary|ios::in);
--id_count;
while(id_count)
{
--id_count;
file.read((char*)&record, sizeof(record));
}
file.read((char*)&record, sizeof(record));
file.close();
gotoxy(30,1);
cout<<char(2)<<char(1)<<" RECORD DETAILS "<<char(1)<<char(2);
gotoxy(2,2);
cout<<"ID             : "<<record.ret_id();
delay(150);
gotoxy(2,4);
cout<<"Name           : "<<record.ret_nm();
delay(150);
gotoxy(2,6);
cout<<"Class/Standard : "<<record.ret_standard();
delay(150);
gotoxy(2,8);
cout<<"Section        : "<<record.ret_section();
delay(200);
gotoxy(2,10);
cout<<"Comment        : "<<record.ret_comment();
char ch=0;
do{
ch=getch();
switch(ch)
{
 case ESC : return 0;
}
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int Student::mod_record( char temp_dir1[])
{
int count=0;
_setcursortype(_NORMALCURSOR);
clrscr();
// Interface OF Function
cout<<setw(28)<<""<<char(1)<<char(2)<<" Create Student Profile "<<char(2)<<char(1);
gotoxy(2,2);
cout<<"ID            : ";
gotoxy(2,3);
cout<<"Name          : ";
gotoxy(2,4);
cout<<"Class         : ";
gotoxy(2,5);
cout<<"Section       : ";
gotoxy(2,6);
cout<<"Percentage(%) : ";
gotoxy(2,7);
cout<<"Comments^ ( Max. 1024 Characters ) : ";
gotoxy(30,23);
textattr(2);
cprintf("CONFIRM");
gotoxy(43,23);
textattr(4);
cprintf("CANCEL");
textcolor(15);

// Working OF Function

char ch; int i=0, verify=0, t_1=0, t_2=0, t_3=0, t_4=0, t_5=0;

// For ID
place1:
{
 i=0; count=0;
 gotoxy(18,2);
 if(id[0]!='\0')
 {
  cout<<id;
  i=strlen(id);
  if(!(t_1))
  {
   ++t_1;
   goto place2;
  }
 }

 do
 {
  ch=getch();

  // Check for Special keys

  if(ch==13)
  {
   id[i]='\0';
   break;
  }

  if(ch==9)
  {
   id[i]='\0';
   gotoxy(18,2);
   goto place2;
  }

  if(ch==27)
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
  }

  if(ch==8)
  {
   if(i>0)
   {
    cout<<"\b \b";
    --i;
    --count;
    id[i]='\0';
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

  if(count==10)
  {
   // Load Extra-Character Function
   max_char_id();
   strcpy(id,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   id[i]=ch;
   cout<<id[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Name
place2:
{
 i=0; count=0;
 gotoxy(18,3);
 if(name[0]!='\0')
 {
  cout<<name;
  i=strlen(name);
  if(!(t_2))
  {
   ++t_2;
   goto place3;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   name[i]='\0';
   verify=validate_sname(name);
   if(verify==1)
   {
    strcpy(name,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   name[i]='\0';
   gotoxy(18,3);
   goto place3;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==100)
  {
   // Load Extra-Character Function
   max_char_sname();
   strcpy(name,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   name[i]=ch;
   cout<<name[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Standard
place3:
{
 i=0; count=0;
 gotoxy(18,4);
 if(standard[0]!='\0')
 {
  cout<<standard;
  i=strlen(standard);
  if(!(t_3))
  {
   ++t_3;
   goto place4;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   standard[i]='\0';
   verify=validate_standard(standard);
   if(verify==1)
   {
    strcpy(standard,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   standard[i]='\0';
   gotoxy(18,4);
   goto place4;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(standard,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   standard[i]=ch;
   cout<<standard[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Section
place4:
{
 i=0; count=0;
 gotoxy(18,5);
 if(section[0]!='\0')
 {
  cout<<section;
  i=strlen(section);
  if(!(t_4))
  {
   ++t_4;
   goto place5;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   section[i]='\0';
   verify=validate_section(section);
   if(verify==1)
   {
    strcpy(section,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   section[i],'\0';
   gotoxy(18,5);
   goto place5;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(section,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   section[i]=ch;
   cout<<section[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Percentage
place5:
{
 i=0; count=0;
 gotoxy(18,6);
 if(per[0]!='\0')
 {
  cout<<per;
  i=strlen(per);
  if(!(t_5))
  {
   ++t_5;
   goto place6;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   per[i]='\0';
   verify=validate_percentage(per);
   if(verify==1)
   {
    strcpy(per,"\0");
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   per[i]='\0';
   gotoxy(18,6);
   goto place6;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(per,"\0");
   t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   per[i]=ch;
   cout<<per[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Comment
place6:
{
 i=0; count=0;
 gotoxy(2,8);
 if(!(comment[0]=='\0'))
 {
 cout<<comment;
 i=strlen(comment);
 i+=2;
 }
 gotoxy(i,8);
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   comment[i]='\0';
   break;
  }

  if(ch==char(9))
  {
   comment[i]='\0';
   gotoxy(1,8);
   goto place7;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==1024)
  {
   // Load Extra-Character Function
   max_char_comment();
   strcpy(comment,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   comment[i]=ch;
   cout<<comment[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Confirm Option
place7:
{
 count=0;
 gotoxy(30,23);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place8;

  case 8 : goto place7;

  case 13: {
	    int a=strlen(id), b=strlen(name), c=strlen(standard), g=strlen(section);
	    int d=strlen(per), e=strlen(comment);
	    if((a==0)||(b==0)||(c==0)||(d==0)||(g==0))
	    {
	     rec_field_missing();
	     return 1;
	    }

	    verify=0;
	    verify=validate_sname(name);
	    if(verify==1)
	    {
	     strcpy(name,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_standard(standard);
	    if(verify==1)
	    {
	     strcpy(standard,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_section(section);
	    if(verify==1)
	    {
	     strcpy(section,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_percentage(per);
	    if(verify==1)
	    {
	     strcpy(per,"\0");
	     ++count;
	    }

	    if(e!=0)
	    {
	     verify=0;
	    }

	    if(count)
	    {
	     return 1;
	    }
	    i=confirm_replace();
	    if(i)
	    {
	     i=write_modified_student_record(temp_dir1);
	     if(i==0)
	     {
	      return 0;
	     }
	    }
	    else return 1;
	   }

  case 27: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case RIGHT_ARROW: goto place8;

  default: goto place7;
 }
}

// For Cancel Option
place8:
{
 gotoxy(43,23);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place1;

  case 8 : goto place8;

  case 13: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case 27: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case LEFT_ARROW: goto place7;

  default: goto place8;
 }
}
}


/*==========================================================================
  ==========================================================================*/


int Student::create_record(char usnm[])
{
int count=0;
clrscr();
// Interface OF Function
cout<<setw(28)<<""<<char(1)<<char(2)<<" Create Student Profile "<<char(2)<<char(1);
gotoxy(2,2);
cout<<"ID            : ";
gotoxy(2,3);
cout<<"Name          : ";
gotoxy(2,4);
cout<<"Class         : ";
gotoxy(2,5);
cout<<"Section       : ";
gotoxy(2,6);
cout<<"Percentage(%) : ";
gotoxy(2,7);
cout<<"Comments^ ( Max. 1024 Characters ) : ";
gotoxy(30,23);
textattr(2);
cprintf("CONFIRM");
gotoxy(43,23);
textattr(4);
cprintf("CANCEL");
textcolor(15);

// Working OF Function

char ch; int i=0, verify=0, t_1=0, t_2=0, t_3=0, t_4=0, t_5=0;

// For ID
place1:
{
 i=0; count=0;
 gotoxy(18,2);
 if(id[0]!='\0')
 {
  cout<<id;
  i=strlen(id);
  if(!(t_1))
  {
   ++t_1;
   goto place2;
  }
 }

 do
 {
  ch=getch();

  // Check for Special keys

  if(ch==13)
  {
   id[i]='\0';
   break;
  }

  if(ch==9)
  {
   id[i]='\0';
   gotoxy(18,2);
   goto place2;
  }

  if(ch==27)
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
  }

  if(ch==8)
  {
   if(i>0)
   {
    cout<<"\b \b";
    --i;
    --count;
    id[i]='\0';
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

  if(count==10)
  {
   // Load Extra-Character Function
   max_char_id();
   strcpy(id,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   id[i]=ch;
   cout<<id[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Name
place2:
{
 i=0; count=0;
 gotoxy(18,3);
 if(name[0]!='\0')
 {
  cout<<name;
  i=strlen(name);
  if(!(t_2))
  {
   ++t_2;
   goto place3;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   name[i]='\0';
   verify=validate_sname(name);
   if(verify==1)
   {
    strcpy(name,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   name[i]='\0';
   gotoxy(18,3);
   goto place3;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==100)
  {
   // Load Extra-Character Function
   max_char_sname();
   strcpy(name,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   name[i]=ch;
   cout<<name[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Standard
place3:
{
 i=0; count=0;
 gotoxy(18,4);
 if(standard[0]!='\0')
 {
  cout<<standard;
  i=strlen(standard);
  if(!(t_3))
  {
   ++t_3;
   goto place4;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   standard[i]='\0';
   verify=validate_standard(standard);
   if(verify==1)
   {
    strcpy(standard,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   standard[i]='\0';
   gotoxy(18,4);
   goto place4;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(standard,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   standard[i]=ch;
   cout<<standard[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Section
place4:
{
 i=0; count=0;
 gotoxy(18,5);
 if(section[0]!='\0')
 {
  cout<<section;
  i=strlen(section);
  if(!(t_4))
  {
   ++t_4;
   goto place5;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   section[i]='\0';
   verify=validate_section(section);
   if(verify==1)
   {
    strcpy(section,"\0");
    t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   section[i],'\0';
   gotoxy(18,5);
   goto place5;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(section,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   section[i]=ch;
   cout<<section[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Percentage
place5:
{
 i=0; count=0;
 gotoxy(18,6);
 if(per[0]!='\0')
 {
  cout<<per;
  i=strlen(per);
  if(!(t_5))
  {
   ++t_5;
   goto place6;
  }
 }
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   per[i]='\0';
   verify=validate_percentage(per);
   if(verify==1)
   {
    strcpy(per,"\0");
    return 1;
   }
   if(verify==0)
   {
    break;
   }
  }

  if(ch==char(9))
  {
   per[i]='\0';
   gotoxy(18,6);
   goto place6;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==5)
  {
   // Load Extra-Character Function
   max_char_standard();
   strcpy(per,"\0");
   t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   per[i]=ch;
   cout<<per[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Comment
place6:
{
 i=0; count=0;
 gotoxy(2,8);
 if(!(comment[0]=='\0'))
 {
 cout<<comment;
 i=strlen(comment);
 i+=2;
 }
 gotoxy(i,8);
 do
 {
  ch=getch();

  // Check for Special keys
  if(ch==13)
  {
   comment[i]='\0';
   break;
  }

  if(ch==char(9))
  {
   comment[i]='\0';
   gotoxy(1,8);
   goto place7;
  }

  if(ch==char(27))
  {
   i=exit_create_record();
   if(i==1)
   {
    return 1;
   }
   else
   {
    return 0;
   }
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

  if(count==1024)
  {
   // Load Extra-Character Function
   max_char_comment();
   strcpy(comment,"\0");
   return 1;
  }

  if(!((ch==13)||(ch==27)||(ch==9)||(ch==8)))
  {
   comment[i]=ch;
   cout<<comment[i];
   ++i;
   ++count;
  }
 }while(1);
}

// For Confirm Option
place7:
{
 count=0;
 gotoxy(30,23);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place8;

  case 8 : goto place7;

  case 13: {
	    int a=strlen(id), b=strlen(name), c=strlen(standard), g=strlen(section);
	    int d=strlen(per), e=strlen(comment);
	    if((a==0)||(b==0)||(c==0)||(d==0)||(g==0))
	    {
	   //  field_missing();
	     return 1;
	    }

	    verify=0;
	    verify=validate_sname(name);
	    if(verify==1)
	    {
	     strcpy(name,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_standard(standard);
	    if(verify==1)
	    {
	     strcpy(standard,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_section(section);
	    if(verify==1)
	    {
	     strcpy(section,"\0");
	     t_1=0; t_2=0; t_3=0; t_4=0; t_5=0;
	     ++count;
	    }

	    verify=0;
	    verify=validate_percentage(per);
	    if(verify==1)
	    {
	     strcpy(per,"\0");
	     ++count;
	    }

	    if(e!=0)
	    {
	     verify=0;
	    }

	    if(count)
	    {
	     return 1;
	    }

	    i=write_student_record(usnm);
	    if(i==0)
	    {
	     return 0;
	    }
	    else return 1;
	   }

  case 27: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case RIGHT_ARROW: goto place8;

  default: goto place7;
 }
}

// For Cancel Option
place8:
{
 gotoxy(43,23);
 ch=getch();
 switch(ch)
 {
  case 9 : goto place1;

  case 8 : goto place8;

  case 13: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case 27: {
	    i=exit_create_record();
	    if(i==1)
	    {
	     return 1;
	    }
	    else
	    {
	     return 0;
	    }
	   }

  case LEFT_ARROW: goto place7;

  default: goto place8;
 }
}
}


/*==========================================================================
  ==========================================================================*/


int Student::show_record(int i)
{
gotoxy(2,i);
cout<<id;
gotoxy(14,i);
cout<<name;
gotoxy(69,i);
cout<<standard;
gotoxy(76,i);
cout<<section;
return i;
}

/*==========================================================================
  ==========================================================================*/


int records( char usnm[], int bgcolor, int txtcolor)
{
start:
clrscr();
char ch=0; int i=0, special_bit=0, row=4, or_row=4;
int ctr=0, rec=0;
char temp_usnm[]={"\0"}, temp_dir0[100]={"\0"}, temp_dir1[100]={"\0"};

strcpy(temp_usnm,usnm);
strcpy(temp_dir0, "C:/SMS/USERS/");
strcat(temp_dir0,temp_usnm);
strcpy(temp_dir1,temp_dir0);
strcat(temp_dir1,"/Records.sms");


window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(8,25);
cprintf("CTRL+C");
gotoxy(26,25);
cprintf("DELETE");
gotoxy(44,25);
cprintf("ENTER");
gotoxy(59,25);
cprintf("CTRL+S");
textcolor(0);
gotoxy(14,25);
cprintf("-Create");
gotoxy(32,25);
cprintf("-Delete");
gotoxy(49,25);
cprintf("-View");
gotoxy(65,25);
cprintf("-Search");
window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
_setcursortype(_NOCURSOR);
clrscr();



fstream file;
file.open(temp_dir1, ios::binary | ios::in | ios::nocreate);

if(!file)
{
gotoxy(30,11);
cout<<"No Records To Show!!";
file.close();
_setcursortype(_NOCURSOR);
goto loop;
}

else
{
gotoxy(36,1);
cout<<"Records";
gotoxy(2,3);
cout<<"ID";
gotoxy(14,3);
cout<<"Name";
gotoxy(69,3);
cout<<"Class";
gotoxy(76,3);
cout<<"Sec.";
gotoxy(1,4);
special_bit=1;
i=0;

while(file)
{
++i;
file.read((char*)&temp_record, sizeof(temp_record));
}
--i;
ctr=i;
file.close();

file.open(temp_dir1, ios::binary | ios::in | ios::nocreate);
delay(500);
while(i)
{
--i;
file.read((char*)&temp_record, sizeof(temp_record));
row=temp_record.show_record(or_row);
or_row=row;
++or_row;
delay(100);
if(i==20)
{
 break;
}
}
}
file.close();

loop:
i=4;
ctr+=3;
do
{
 cout<<" ";
 gotoxy(1,i);
 cout<<char(175)<<"\b";
 ch=getch();

 switch(ch)
 {
  case CTRL_C : // Load Create File Function
		{
		 create_student_record(usnm,bgcolor,txtcolor);
		 goto start;
		}

  case CTRL_S : // Load Search Function
		{
		 search ( temp_dir1, bgcolor, txtcolor );
		 goto start;
		}

  case CTRL_E : // Load Edit Record Function
		if(special_bit)
		{
		 rec=i-3;
		 modify_record(temp_dir1);
		 goto start;
		}
		break;


  case UP_ARROW: // Move To Previous Field
		 if((i>4)&&special_bit)
		 {
		  --i;
		 }
		 break;

  case DOWN_ARROW: // Move To Next Field
		   if(special_bit&&(i<ctr))
		   {
		    ++i;
		   }
		   break;

  case ENTER : // Activate The Current Record
	       if(special_bit)
	       {
		Student rec_i;
		rec=i-3;
		rec_i.show_details(temp_dir1, rec, bgcolor, txtcolor);
		goto start;
	       }
	       break;

  case DELETE : // Delete The Current Record
		if(special_bit)
		{
		 rec=i-3;
		 delete_record(temp_dir0, temp_dir1, rec);
		 goto start;
		}
		break;

  case ESC : // End Function
	     remove("C:/SMS/PROGRAM/temp.tmp");
	     return 0;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int create_student_record(char usnm[], int bgcolor, int txtcolor)
{
record.delet();
start:
int i=0;
window(1,1,80,25);
textbackground(7);
textcolor(4);
_setcursortype(_NORMALCURSOR);
clrscr();
gotoxy(3,25);
cout<<"ESC";
gotoxy(15,25);
cout<<"TAB";
gotoxy(30,25);
cout<<"ENTER";
gotoxy(63,25);
cout<<"^";
textcolor(0);
gotoxy(7,25);
cprintf("-Cancel");
gotoxy(18,25);
cprintf("-Next Field");
gotoxy(35,25);
cprintf("-Input & Move to Next Field");
gotoxy(64,25);
cprintf("-Optional Field");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
i=record.create_record(usnm);
if(i==1)
{
goto start;
}
return 1;
}


/*==========================================================================
  ==========================================================================*/


int validate_sname( char name[])
{
 int ctr=0;
 for(int i=0; i<strlen(name); ++i)
 {
  ctr=isalpha(name[i]);
  if ((ctr==0)&&(name[i]!=char(32)))
  {
   invalid_sname();
   return 1;
  }
 }
 return 0;
}

/*==========================================================================
  ==========================================================================*/


int validate_standard( char standard[])
{
 int ctr=0;
 for(int i=0; i<strlen(standard); ++i)
 {
  ctr=isalnum(standard[i]);
  if ((ctr==0)&&(standard[i]!=char(32))&&(standard[i]!=('-'))&&(standard[i]!=('_')))
  {
   invalid_standard();
   return 1;
  }
 }
 return 0;
}


/*==========================================================================
  ==========================================================================*/


int validate_section( char section[])
{
 int ctr=0;
 for(int i=0; i<strlen(section); ++i)
 {
  ctr=isalnum(section[i]);
  if ((ctr==0)&&(section[i]!=char(32))&&(section[i]!=('-'))&&(section[i]!=('_')))
  {
   invalid_section();
   return 1;
  }
 }
 return 0;
}


/*==========================================================================
  ==========================================================================*/


int validate_percentage( char percentage[])
{
 int ctr=0, count=0;
 for(int i=0; i<strlen(percentage); ++i)
 {
  ctr=isdigit(percentage[i]);
  if ((ctr==0)&&(percentage[i]!=('.')))
  {
   invalid_percentage();
   return 1;
  }
  if(percentage[i]=='.')
  {
  ++count;
  }
 }
 if((count>1)||(count<1))
 {
  invalid_percentage();
  return 1;
 }
 return 0;
}


/*==========================================================================
  ==========================================================================*/


void max_char_id( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Max. Allowed : 10 Characters");
textattr(18);
cout<<setw(1)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void max_char_sname( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Max. Allowed : 100 Characters");
textattr(18);
cout<<setw(0)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void max_char_standard( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(20);
cprintf("Max. Allowed : 5 Characters");
textattr(18);
cout<<setw(2)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void max_char_comment( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(0)<<"";
textattr(20);
cprintf("Max. Allowed : 1024 Characters");
textattr(18);
cout<<setw(0)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void invalid_sname( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Invalid Name!");
textattr(18);
cout<<setw(9)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void invalid_standard( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(6)<<"";
textattr(20);
cprintf("Invalid Standard!");
textattr(18);
cout<<setw(7)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void invalid_section( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(7)<<"";
textattr(20);
cprintf("Invalid Section!");
textattr(18);
cout<<setw(7)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


void invalid_percentage( void )
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(5)<<"";
textattr(20);
cprintf("Invalid Percentage!");
textattr(18);
cout<<setw(6)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(8,4);
cout<<"% Format : XX.XX";
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}


/*==========================================================================
  ==========================================================================*/


int exit_create_record()
{
char a;

// Interface Presentation
_setcursortype(_SOLIDCURSOR);
window(26,8,53,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<26; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(6)<<"";
textattr(30);
cprintf("Cancel Record?");
textattr(18);
cout<<setw(6)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Yes");
textattr(18);
cout<<setw(4)<<""<<"No"<<setw(9)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(26)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<26; ++i) cout<<char(205);
cout<<char(188);

// Interface Working
gotoxy(10,6);
sound(500);
delay(150);
nosound();
sound(5000);
delay(100);
nosound();
i=10;
do
{
 gotoxy(i,6);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case LEFT_ARROW: {
		    if (i!=10)
		    {
		     i-=7;
		    }
		   } break;

  case RIGHT_ARROW: {
		     if(i!=17)
		     {
		      i+=7;
		     }
		    } break;

  case 9  : {
	     if (i!=10)
	     {
	      i-=7;
	     }
	     if(i!=17)
	     {
	      i+=7;
	     }
	    } break;

  case 13 : {
	     switch(i)
	     {
	      case 10 : {
			 sound(5000);
			 delay(120);
			 nosound();
			 sound(400);
			 delay(100);
			 nosound();
			 return 0;
			}
	      case 17 : break;
	     }
	    } break;
  case 27 : break;
 }
 if ((a==27)||((a==13)&&(i==17)))  // IF Exit is Not Confirmed
 {
  break;
 }
}while(1);
return 1;
}


/*==========================================================================
  ==========================================================================*/


int write_student_record(char usnm[])
{
char last='y';  char temp_usnm[]={"\0"};
strcpy(temp_usnm, usnm);
char tmp_rec[20]={"\0"}, org_rec[20]={"\0"};
char dir_write[100]={"C:/SMS/USERS/"};
char dir_write1[100]={"C:/SMS/USERS/"};
strcat(dir_write, usnm);
strcat(dir_write1, temp_usnm);
strcat(dir_write,"/records.sms");
strcat(dir_write1,"/temp.tmp");
fstream ifile, ofile;
ifile.open(dir_write, ios::in);
ofile.open(dir_write1, ios::binary|ios::out|ios::trunc);
strcpy(org_rec, record.ret_id());
while(ifile.read((char*)&temp_record, sizeof(temp_record)))
{
 int i=0;
 strcpy(tmp_rec, "\0");
 strcpy(tmp_rec, temp_record.ret_id());
 while(org_rec[i]==tmp_rec[i])
 {
  ++i;
 }

 if(org_rec[i]<tmp_rec[i])
 {
  ofile.write((char*)&record, sizeof(record));
  ofile.write((char*)&temp_record, sizeof(temp_record));
  last='n';
  break;
 }
 else
  ofile.write((char*)&temp_record, sizeof(temp_record));
}

if(last=='y')
{
 ofile.write((char*)&record, sizeof(record));
}
else
{
 while(ifile.read((char*)&temp_record, sizeof(temp_record)))
 ofile.write((char*)&temp_record, sizeof(temp_record));
}
ifile.close();
ofile.close();
remove(dir_write);
rename(dir_write1,dir_write);
return 0;
}


/*==========================================================================
  ==========================================================================*/


int confirm_replace()
{
char a;

// Interface Presentation
_setcursortype(_SOLIDCURSOR);
window(26,8,53,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<26; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(1)<<"";
textattr(30);
cprintf("Confirm Replace Previous?");
textattr(18);
cout<<setw(0)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(8)<<"";
textattr(20);
cprintf("Yes");
textattr(18);
cout<<setw(4)<<""<<"No"<<setw(9)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(26)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(26)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<26; ++i) cout<<char(205);
cout<<char(188);

// Interface Working
gotoxy(10,6);
sound(500);
delay(150);
nosound();
sound(5000);
delay(100);
nosound();
i=10;
do
{
 gotoxy(i,6);
 a=getch();
 if(a==0x00)           // Checks If First Character is 0 of Hexadecimal Value
 a=getch();
 switch(a)
 {

  case LEFT_ARROW: {
		    if (i!=10)
		    {
		     i-=7;
		    }
		   } break;

  case RIGHT_ARROW: {
		     if(i!=17)
		     {
		      i+=7;
		     }
		    } break;

  case 9  : {
	     if (i!=10)
	     {
	      i-=7;
	     }
	     if(i!=17)
	     {
	      i+=7;
	     }
	    } break;

  case 13 : {
	     switch(i)
	     {
	      case 10 : {
			 sound(5000);
			 delay(120);
			 nosound();
			 sound(400);
			 delay(100);
			 nosound();
			 return 1;
			}
	      case 17 : break;
	     }
	    } break;
  case 27 : break;
 }
 if ((a==27)||((a==13)&&(i==17)))  // IF Replace is Not Confirmed
 {
  break;
 }
}while(1);
return 0;
}


/*==========================================================================
  ==========================================================================*/

// FUNCTION FOR DATA DELETION

void delete_record(char temp_dir0[],char temp_dir1[], int id_count)
{
Student temp;
strcat(temp_dir0,"/temp.tmp");
fstream ifile, ofile;
ifile.open(temp_dir1, ios::binary|ios::in);
ofile.open(temp_dir0, ios::binary|ios::out|ios::trunc);
--id_count;
while(id_count)
{
 --id_count;
 ifile.read((char*)&temp, sizeof(temp));
 ofile.write((char*)&temp, sizeof(temp));
}
ifile.read((char*)&temp, sizeof(temp));
while(ifile)
{
++id_count;
ifile.read((char*)&temp, sizeof(temp));
//ofile.write((char*)&temp, sizeof(temp));
}
--id_count;
for(int count=0; count<id_count; ++count)
ifile.seekp(-sizeof(temp), ios::cur);
while(id_count)
{
--id_count;
ifile.read((char*)&temp, sizeof(temp));
ofile.write((char*)&temp, sizeof(temp));
}
ifile.close();
ofile.close();
remove(temp_dir1);
rename(temp_dir0, temp_dir1);
}


/*==========================================================================
  ==========================================================================*/


int search ( char temp_dir1[], int bgcolor, int txtcolor )
{
window(25,8,56,16);
textbackground(1);
textcolor(15);
clrscr();

cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
for( i=2; i<9; ++i)
{
gotoxy(1,i);
cout<<char(186)<<setw(30)<<""<<char(186);
}
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);

gotoxy(8,3);
cout<<"Select Search Tool";
gotoxy(9,4);
cout<<"ID";
gotoxy(9,5);
cout<<"Name";
gotoxy(9,6);
cout<<"Class/Standard";
gotoxy(9,7);
cout<<"Section ";
i=4;
unsigned char ch=0;
_setcursortype(_NOCURSOR);
do{
cout<<"\b \b";
gotoxy(8,i);
textattr(146);
cprintf("%c",175);
ch=getch();
 switch(ch)
 {
 case LEFT_ARROW : break;

 case RIGHT_ARROW : break;

 case UP_ARROW : {
		  if(i>4)
		  --i;
		 } break;

 case DOWN_ARROW : {
		    if(i<7)
		    ++i;
		   }break;

 case ENTER : // Activate Search
	      {
	       switch(i)
	       {
		case 4 : // Search With ID
			 search_id(temp_dir1, bgcolor, txtcolor);
			 return 0;
		case 5 : // Search With NAME
			 search_name(temp_dir1, bgcolor, txtcolor);
			 return 0;
		case 6 : // Search With STANDARD
			 search_standard(temp_dir1, bgcolor, txtcolor);
			 return 0;
		case 7 : // Search With SECTION
			 search_section(temp_dir1, bgcolor, txtcolor);
			 return 0;
	       }
	      }
	      break;

 case ESC : return 1;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int search_id( char temp_dir1[], int bgcolor, int txtcolor)
{
int ctr=0;

start:
_setcursortype(_NORMALCURSOR);
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(6,25);
cout<<"ENTER";
gotoxy(51,25);
cout<<"ESC";
textcolor(0);
gotoxy(11,25);
cprintf("-Confirm Search/View Record Details");
gotoxy(54,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
char a[10]={"\0"}, b[10]={"\0"};
int i=0;
cout<<"Enter Search ID : ";

fstream file;

int z=19;
do
{

 gotoxy(z,1);
 a[i]=getch();

 if(a[i]==ESC) { return 0; }
 if(a[i]==ENTER)
 {
  int y=4;
  gotoxy(1,y);
  break;
 }

 if(a[i]==BCKSPC)
 {
  if(i>0)
  {
   cout<<"\b \b";
   a[i]='\0';
   goto start;
  }
 }

 file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::trunc);
 file.close();
 if((a[i]!=BCKSPC)&&(a[i]!=ESC)&&(a[i]!=ENTER))
 {
  int count=0;
  cout<<a[i];
  int y=4;
  file.open(temp_dir1, ios::binary|ios::in);
  for(int p=4; p<25; ++p)
  {
   gotoxy(1,p);
   clreol();
  }
  while(file.read((char*)&temp_record, sizeof(temp_record)))
  {
   int temp=0;
   strcpy(b, temp_record.ret_id());
   if(i>0)
   {
    for(int k=0; k<i; ++k)
    {
     if(b[k]==a[k])
     {
      ++temp;
     }
    }
   }
   if ((b[i]==a[i])&&(temp==i))
   {
    ++count;
    fstream temp_file;
    temp_file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::app);
    temp_file.write((char*)&temp_record, sizeof(temp_record));
    temp_file.close();
   }
  }
  file.close();
  if(!count)
  {
   gotoxy(32,5);
   cout<<"No Record Found";
  }
  else
  {
   file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
   y=4;
   while(count)
   {
    --count;
    int x=0;
    file.read((char*)&temp_record, sizeof(temp_record));
    x=temp_record.show_record(y);
    y=x;
    ++y;
   }
   file.close();
  }
  ++i;
  ++z;
 }
}while(1);

ctr=0;
file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
while(file)
{
++ctr;
file.read((char*)&temp_record, sizeof(temp_record));
}
file.close();
--ctr;

_setcursortype(_NOCURSOR);
char ch=0;
int special_bit=1, rec=0;
i=4;
ctr+=3;
do
{
 cout<<" ";
 gotoxy(1,i);
 cout<<char(175)<<"\b";
 ch=getch();

 switch(ch)
 {
  case UP_ARROW: // Move To Previous Field
		 if((i>4)&&special_bit)
		 {
		  --i;
		 }
		 break;

  case DOWN_ARROW: // Move To Next Field
		   if(special_bit&&(i<ctr))
		   {
		    ++i;
		   }
		   break;

  case ENTER : // Activate The Current Record
	       if(special_bit)
	       {
		Student rec_i;
		rec=i-3;
		rec_i.show_search_details(rec, bgcolor, txtcolor);
		goto start;
	       }
	       break;

  case DELETE : break;

  case ESC : // End Function
	     return 0;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int search_name( char temp_dir1[], int bgcolor, int txtcolor)
{
int ctr=0;

start:
_setcursortype(_NORMALCURSOR);
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(6,25);
cout<<"ENTER";
gotoxy(51,25);
cout<<"ESC";
textcolor(0);
gotoxy(11,25);
cprintf("-Confirm Search/View Record Details");
gotoxy(54,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
char a[50]={"\0"}, b[50]={"\0"};
int i=0;
cout<<"Enter Search Name : ";

fstream file;

int z=21;
do
{

 gotoxy(z,1);
 a[i]=getch();

 if(a[i]==ESC) { return 0; }
 if(a[i]==ENTER)
 {
  int y=4;
  gotoxy(1,y);
  break;
 }

 if(a[i]==BCKSPC)
 {
  if(i>0)
  {
   cout<<"\b \b";
   a[i]='\0';
   goto start;
  }
 }

 file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::trunc);
 file.close();
 if((a[i]!=BCKSPC)&&(a[i]!=ESC)&&(a[i]!=ENTER))
 {
  int count=0;
  cout<<a[i];
  int y=4;
  file.open(temp_dir1, ios::binary|ios::in);
  for(int p=4; p<25; ++p)
  {
   gotoxy(1,p);
   clreol();
  }
  while(file.read((char*)&temp_record, sizeof(temp_record)))
  {
   int temp=0;
   strcpy(b, temp_record.ret_nm());
   if(i>0)
   {
    for(int k=0; k<i; ++k)
    {
     if(b[k]==a[k])
     {
      ++temp;
     }
    }
   }
   if ((b[i]==a[i])&&(temp==i))
   {
    ++count;
    fstream temp_file;
    temp_file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::app);
    temp_file.write((char*)&temp_record, sizeof(temp_record));
    temp_file.close();
   }
  }
  file.close();
  if(!count)
  {
   gotoxy(32,5);
   cout<<"No Record Found";
  }
  else
  {
   file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
   y=4;
   while(count)
   {
    --count;
    int x=0;
    file.read((char*)&temp_record, sizeof(temp_record));
    x=temp_record.show_record(y);
    y=x;
    ++y;
   }
   file.close();
  }
  ++i;
  ++z;
 }
}while(1);

ctr=0;
file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
while(file)
{
++ctr;
file.read((char*)&temp_record, sizeof(temp_record));
}
file.close();
--ctr;

_setcursortype(_NOCURSOR);
char ch=0;
int special_bit=1, rec=0;
i=4;
ctr+=3;
do
{
 cout<<" ";
 gotoxy(1,i);
 cout<<char(175)<<"\b";
 ch=getch();

 switch(ch)
 {
  case UP_ARROW: // Move To Previous Field
		 if((i>4)&&special_bit)
		 {
		  --i;
		 }
		 break;

  case DOWN_ARROW: // Move To Next Field
		   if(special_bit&&(i<ctr))
		   {
		    ++i;
		   }
		   break;

  case ENTER : // Activate The Current Record
	       if(special_bit)
	       {
		Student rec_i;
		rec=i-3;
		rec_i.show_search_details(rec, bgcolor, txtcolor);
		goto start;
	       }
	       break;

  case DELETE : break;

  case ESC : // End Function
	     return 0;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int search_standard( char temp_dir1[], int bgcolor, int txtcolor)
{
int ctr=0;

start:
_setcursortype(_NORMALCURSOR);
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(6,25);
cout<<"ENTER";
gotoxy(51,25);
cout<<"ESC";
textcolor(0);
gotoxy(11,25);
cprintf("-Confirm Search/View Record Details");
gotoxy(54,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
char a[50]={"\0"}, b[50]={"\0"};
int i=0;
cout<<"Enter Search Standard : ";

fstream file;

int z=25;
do
{

 gotoxy(z,1);
 a[i]=getch();

 if(a[i]==ESC) { return 0; }
 if(a[i]==ENTER)
 {
  int y=4;
  gotoxy(1,y);
  break;
 }

 if(a[i]==BCKSPC)
 {
  if(i>0)
  {
   cout<<"\b \b";
   a[i]='\0';
   goto start;
  }
 }

 file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::trunc);
 file.close();
 if((a[i]!=BCKSPC)&&(a[i]!=ESC)&&(a[i]!=ENTER))
 {
  int count=0;
  cout<<a[i];
  int y=4;
  file.open(temp_dir1, ios::binary|ios::in);
  for(int p=4; p<25; ++p)
  {
   gotoxy(1,p);
   clreol();
  }
  while(file.read((char*)&temp_record, sizeof(temp_record)))
  {
   int temp=0;
   strcpy(b, temp_record.ret_standard());
   if(i>0)
   {
    for(int k=0; k<i; ++k)
    {
     if(b[k]==a[k])
     {
      ++temp;
     }
    }
   }
   if ((b[i]==a[i])&&(temp==i))
   {
    ++count;
    fstream temp_file;
    temp_file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::app);
    temp_file.write((char*)&temp_record, sizeof(temp_record));
    temp_file.close();
   }
  }
  file.close();
  if(!count)
  {
   gotoxy(32,5);
   cout<<"No Record Found";
  }
  else
  {
   file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
   y=4;
   while(count)
   {
    --count;
    int x=0;
    file.read((char*)&temp_record, sizeof(temp_record));
    x=temp_record.show_record(y);
    y=x;
    ++y;
   }
   file.close();
  }
  ++i;
  ++z;
 }
}while(1);

ctr=0;
file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
while(file)
{
++ctr;
file.read((char*)&temp_record, sizeof(temp_record));
}
file.close();
--ctr;

_setcursortype(_NOCURSOR);
int special_bit=1, rec=0;
char ch=0;
i=4;
ctr+=3;
do
{
 cout<<" ";
 gotoxy(1,i);
 cout<<char(175)<<"\b";
 ch=getch();

 switch(ch)
 {
  case UP_ARROW: // Move To Previous Field
		 if((i>4)&&special_bit)
		 {
		  --i;
		 }
		 break;

  case DOWN_ARROW: // Move To Next Field
		   if(special_bit&&(i<ctr))
		   {
		    ++i;
		   }
		   break;

  case ENTER : // Activate The Current Record
	       if(special_bit)
	       {
		Student rec_i;
		rec=i-3;
		rec_i.show_search_details(rec, bgcolor, txtcolor);
		goto start;
	       }
	       break;

  case DELETE : break;

  case ESC : // End Function
	     return 0;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int search_section( char temp_dir1[], int bgcolor, int txtcolor)
{
int ctr=0;

start:
_setcursortype(_NORMALCURSOR);
window(1,1,80,25);
textbackground(7);
textcolor(4);
clrscr();
gotoxy(6,25);
cout<<"ENTER";
gotoxy(51,25);
cout<<"ESC";
textcolor(0);
gotoxy(11,25);
cprintf("-Confirm Search/View Record Details");
gotoxy(54,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
clrscr();
char a[50]={"\0"}, b[50]={"\0"};
int i=0;
cout<<"Enter Search Section : ";

fstream file;

int z=24;
do
{

 gotoxy(z,1);
 a[i]=getch();

 if(a[i]==ESC) { return 0; }
 if(a[i]==ENTER)
 {
  int y=4;
  gotoxy(1,y);
  break;
 }

 if(a[i]==BCKSPC)
 {
  if(i>0)
  {
   cout<<"\b \b";
   a[i]='\0';
   goto start;
  }
 }

 file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::trunc);
 file.close();
 if((a[i]!=BCKSPC)&&(a[i]!=ESC)&&(a[i]!=ENTER))
 {
  int count=0;
  cout<<a[i];
  int y=4;
  file.open(temp_dir1, ios::binary|ios::in);
  for(int p=4; p<25; ++p)
  {
   gotoxy(1,p);
   clreol();
  }
  while(file.read((char*)&temp_record, sizeof(temp_record)))
  {
   int temp=0;
   strcpy(b, temp_record.ret_section());
   if(i>0)
   {
    for(int k=0; k<i; ++k)
    {
     if(b[k]==a[k])
     {
      ++temp;
     }
    }
   }
   if ((b[i]==a[i])&&(temp==i))
   {
    ++count;
    fstream temp_file;
    temp_file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::app);
    temp_file.write((char*)&temp_record, sizeof(temp_record));
    temp_file.close();
   }
  }
  file.close();
  if(!count)
  {
   gotoxy(32,5);
   cout<<"No Record Found";
  }
  else
  {
   file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
   y=4;
   while(count)
   {
    --count;
    int x=0;
    file.read((char*)&temp_record, sizeof(temp_record));
    x=temp_record.show_record(y);
    y=x;
    ++y;
   }
   file.close();
  }
  ++i;
  ++z;
 }
}while(1);

ctr=0;
file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
while(file)
{
++ctr;
file.read((char*)&temp_record, sizeof(temp_record));
}
file.close();
--ctr;

_setcursortype(_NOCURSOR);
int special_bit=1, rec=0;
char ch=0;
i=4;
ctr+=3;
do
{
 cout<<" ";
 gotoxy(1,i);
 cout<<char(175)<<"\b";
 ch=getch();

 switch(ch)
 {
  case UP_ARROW: // Move To Previous Field
		 if((i>4)&&special_bit)
		 {
		  --i;
		 }
		 break;

  case DOWN_ARROW: // Move To Next Field
		   if(special_bit&&(i<ctr))
		   {
		    ++i;
		   }
		   break;

  case ENTER : // Activate The Current Record
	       if(special_bit)
	       {
		Student rec_i;
		rec=i-3;
		rec_i.show_search_details(rec, bgcolor, txtcolor);
		goto start;
	       }
	       break;

  case DELETE : break;

  case ESC : // End Function
	     return 0;
 }
}while(1);
}


/*==========================================================================
  ==========================================================================*/


int Student::show_search_details(int id_count, int bgcolor, int txtcolor )
{
char ch=0;
window(1,1,80,25);
textbackground(7);
textcolor(5);
clrscr();
gotoxy(10,25);
cout<<"EDITING DISABLED";
textcolor(4);
gotoxy(34,25);
cprintf("ESC");
textcolor(0);
gotoxy(37,25);
cprintf("-Back");

window(1,1,80,24);
textbackground(bgcolor);
textcolor(txtcolor);
_setcursortype(_NOCURSOR);
clrscr();
fstream file;
file.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::in);
--id_count;
while(id_count)
{
--id_count;
file.read((char*)&record, sizeof(record));
}
file.read((char*)&record, sizeof(record));
file.close();
gotoxy(30,1);
cout<<char(2)<<char(1)<<" RECORD DETAILS "<<char(1)<<char(2);
gotoxy(2,2);
cout<<"ID             : "<<record.ret_id();
delay(150);
gotoxy(2,4);
cout<<"Name           : "<<record.ret_nm();
delay(150);
gotoxy(2,6);
cout<<"Class/Standard : "<<record.ret_standard();
delay(150);
gotoxy(2,8);
cout<<"Section        : "<<record.ret_section();
delay(200);
gotoxy(2,10);
cout<<"Comment        : "<<record.ret_comment();
ch=0;
do{
ch=getch();
switch(ch)
{
 case ESC : return 0;
}
}while(1);
}


/*==========================================================================
  =========================================================================*/


void modify_record(char temp_dir1[])
{
record.delet();
record.mod_record( temp_dir1);
}


/*==========================================================================
  =========================================================================*/


int write_modified_student_record(char temp_dir1[])
{
fstream ifile, ofile;
ifile.open(temp_dir1, ios::binary|ios::in);
ofile.open("C:/SMS/PROGRAM/temp.tmp", ios::binary|ios::out|ios::app);

while(ifile.read((char*)&temp_record, sizeof(temp_record)))
{
 if(!strcmp(temp_record.ret_id(), record.ret_id()))
 {
  ofile.write((char*)&record, sizeof(record));
 }
 else
 {
  ofile.write((char*)&temp_record, sizeof(temp_record));
 }
}
ifile.close();
ofile.close();
remove(temp_dir1);
rename("C:/SMS/PROGRAM/temp.tmp",temp_dir1);
return 0;
}


/*==========================================================================
  ==========================================================================*/


void rec_field_missing()
{
sound(500);
delay(100);
nosound();
sound(5000);
delay(50);
nosound();
_setcursortype(_NOCURSOR);
window(25,8,56,16);
textbackground(1);
textcolor(2);
clrscr();
cout<<char(201);
for (int i=0; i<30; ++i) cout<<char(205);
cout<<char(187);
gotoxy(1,2);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,3);
cout<<char(186)<<setw(3)<<"";
textattr(20);
cprintf("Compulsory Field Missing!");
textattr(18);
cout<<setw(2)<<""<<char(186);
gotoxy(1,4);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,5);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,6);
cout<<char(186)<<setw(1)<<"";
textattr(154);
cprintf("Press Any Key To Continue... ");
textattr(26);
cout<<setw(0)<<""<<char(186);
gotoxy(1,7);
cout<<char(186)<<setw(30)<<"";
cout<<char(186);
gotoxy(1,8);
cout<<char(186)<<setw(30)<<""<<char(186);
gotoxy(1,9);
cout<<char(200);
for (i=0; i<30; ++i) cout<<char(205);
cout<<char(188);
getch();
}

}

// END OF FUNCTION DEFINATIONS

#endif		/* __RECORDS_H*/
