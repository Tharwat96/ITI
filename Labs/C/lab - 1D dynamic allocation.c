#include <conio.h>
#include <stdio.h>
#include <alloc.h>

void insert(int* n, int s);
void view(int* n, int s);
int sum(int* n, int s);
float avg(int* n, int s);
void search(int* n, int s, int v);



int main()
{
   int size, c, f=1, srch;
   int* ptr;
   printf("Please input how many numbers you need: \n");
   scanf("%d", &size);
	ptr = (int*)malloc(size*sizeof(int));
   if(ptr!=NULL)
   {
      while(f==1)
      {
   		printf("\nPlease select what you need to do: \n");
      	printf("\n1- Insert numbers  2- View	3- Sum numbers");
      	printf("	 4- Avg of numbers  5- Search for an element index");
         printf(" 6- exit\n");
         scanf("%d", &c);
         switch (c)
         {
         	case 1:
            	insert(ptr, size);
               break;
            case 2:
            	view(ptr, size);
               break;
            case 3:
            	printf("sum= %d", sum(ptr, size));
            	break;
            case 4:
            	printf("avg= %f", avg(ptr, size));
            	break;
            case 5:
            	printf("Please enter the value to search for: \n");
               scanf("%d", srch);
               search(ptr, size, srch);
            	break;
            case 6:
            	f=0;
         }
   	}

      free(ptr);
   }

	return 0;
}
void insert(int* n, int s)
{
	int i;
	printf("\nPlease insert your numbers\n");
      for(i=0; i<s; i++)
      {
      	printf("\nPlease enter #%d in your numbers: ", i+1);
      	scanf("%d", &n[i]);
      }


}
void view(int* n, int s)
{     int i;
      printf("\nYour numbers are: ");
      for(i=0; i<s; i++)
      {
      	printf("%d  ", n[i]);
      }
      getch();



}



int sum(int* n, int s)
{
   int i, sum=0;
	for(i=0; i<s; i++)
       sum += n[i];

   return sum;
}


float avg(int* n, int s)
{
   int i;
   float sum=0, a=0;
	for(i=0; i<s; i++)
   {
   sum += n[i];
   printf("\nn[i]: %d\n", n[i]);
   printf("sum= %d\n", sum);
   }
   a = sum/s;

   return a;
}

void search(int* n1, int s1, int v)
{
	int i, index=0;
   for(i=0; i<s1; i++)
   {
   	printf("test 1");
   	if(v==n1[i])
      {
      	printf("%d", i);
			printf("test 1");

      }
      else
      	printf("not found");
   }


}
