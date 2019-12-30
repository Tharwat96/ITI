#include <stdio.h>
#include <conio.h>

int main()
{
   int i,c=0;
   char name[20];
	printf("Please enter your name to count its letters: \n");
   scanf("%s", &name);
   for (i=0; i<20; i++)
   {
		if(name[i]!='\0')
      	c++;
      else
      	break;
   }
   printf("\nYour name is %d char long", c);
   getch();
	return 0;
}