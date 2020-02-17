#include <stdio.h>
#include <conio.h>

int main()
{
   int i, n, p=0;
	printf("Please enter a number to test if prime or not: ");
   scanf("%d", &n);
   for(i=n; i>0; i--)
   {
   	if(n%i==0)
      {
         p++;
      }
   }
   if (p==2)
   	printf("the number entered is a prime number");
   else
   	printf("the number entered is not a prime number p= %d", n);
   getch();       
	return 0;
}