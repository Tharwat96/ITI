#include <stdio.h>
#include <conio.h>

struct emp
{
	int id;
   char name[30];
   int salary;

};

struct emp getStructEmpData();


int main()
{
   int i, size;
   struct emp* e;
	printf("Please enter how many employees you have (size of array): ");
   scanf("%d", &size);
   e=(struct emp*)malloc(size*sizeof(struct emp));
   printf("\nPlease enter the data needed for current user as follows: \n");
   for(i=0; i<size; i++)
   {
   	e[i]=getStructEmpData();
   }
   for(i=0; i<size; i++)
   {
   	printStructEmp(e[i]);
   }
   free(e);
   getch();
	return 0;
}


printStructEmp(struct emp e)
{
	printf("ID: %d\nName: %s\nSalary: %d\n", e.id, e.name, e.salary);

}

struct emp getStructEmpData()
{
	struct emp e;
   printf("\nPlease type the id of current employee: ");
   flushall();
	scanf("%d", &e.id);
   printf("\nPlease type the name of current employee: ");
	flushall();
	scanf("%s", e.name);
	printf("\nPlease type the salary of current employee: ");
   flushall();
	scanf("%d", &e.salary);
   return e;

}