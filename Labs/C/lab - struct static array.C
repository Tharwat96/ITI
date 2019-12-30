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
   int i;
	struct emp e[2];
   printf("Please enter the data needed for current user as follows: \n");
   for(i=0; i<2; i++)
   {
   	e[i]=getStructEmpData();
   }
   for(i=0; i<2; i++)
   {
   	printStructEmp(e[i]);
   }
   getch();
	return 0;
}


printStructEmp(struct emp e)
{
	printf("ID: %d, Name: %s, Salary: %d", e.id, e.name, e.salary);

}

struct emp getStructEmpData()
{
	struct emp e;
   printf("\nPlease type the id of current employee: ");
	scanf("%d", &e.id);
   printf("\nPlease type the name of current employee: ");
	scanf("%s", e.name);
	printf("\nPlease type the salary of current employee: ");
	scanf("%d", &e.salary);
   return e;

}