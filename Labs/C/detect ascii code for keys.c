#include <stdio.h>
#include <conio.h>

int main()
{
	char ch;
   int i=0;
   while(i=1)
   {
   	printf("Enter a character to test for ascii code: \n");
      ch = getch();
   	if (ch == NULL)
   	{
   		ch = getch();
         printf("Extended key detected with ascii code of:  NULL|%d \n", ch);
   	}
      else
      {
         printf("Normal key detected with ascii code of: %d \n", ch);

      }
   }

	getch();
	return 0;
}
