#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
   char fname[20], lname[20], fullName[40];
   printf("Please insert your first name for merger: \n");
   scanf("%s", &fname);
   printf("Please insert your last name for merger: \n");
   scanf("%s", &lname);
   strcpy(fullName,fname);
   strcat(fullName, " ");
   strcat(fullName, lname);
   printf("Your name is: %s", fullName);


	getch();
	return 0;
}