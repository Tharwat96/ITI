#include <conio.h>
#include <stdio.h>
#include <alloc.h>


int main()
{
	int i,j, size;
	int* ptr[3];
   printf("please enter the size needed: \n");
   scanf("%d", &size);
   for(i=0; i<3; i++)
   {
   	ptr[i] = (int*)malloc(5*sizeof(int));
   }
   for(i=0; i<3; i++)
   {
   	printf("\nPlease enter #%d set of numbers: ", i+1);
   	for(j=0; j<5; j++)
      {
         printf(" ");
			scanf("%d", &ptr[i][j]);
         printf("\n just entered: %d \n", ptr[i][j]);
      }
   }
   for(i=0; i<3; i++)
   {

      for(j=0; j<5; j++)
      {
   	printf("\n %d", ptr[i][j]);
      }
   }
   getch();
	return 0;
}

