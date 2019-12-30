#include <stdio.h>
#include <conio.h>

int main()


{
	int i, j;
   int n[4]={0}, r[4]={0};
   printf("\nPlease enter your desired numbers to reverse\n");
   for(i=0; i<4; i++)
   	scanf("%d", &n[i]);

   for(i=0, j=3; i<4; i++, j--)
		r[j]=n[i];

   printf("Your reversed numbers: ");
   for(j=0; j<4; j++)
   	printf("%d ", r[j]);
   getch();
	return 0;
}