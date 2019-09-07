#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dir.h>

void main()
{
   int cheack;
   char *dirname;
   clrscr();
   printf("Enter a directory path and name to be deleted (C:/name):");
   gets(dirname);
   system("dir/p");
 
   cheack = rmdir(dirname);
   if (!cheack)
      printf("Directory deleted\n");
   else
   {
              printf("Unable to remove directory\n");
            getch();
             exit(1);
   }
   getch();
}