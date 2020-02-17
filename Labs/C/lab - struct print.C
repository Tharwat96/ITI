#include <stdio.h>
#include <conio.h>

struct emp
{
	int id;
   char name[30];
   int salary;

};

printStructEmp(struct emp e);

int main()
{
	struct emp e1={14, "tester", 3000};
   printStructEmp(e1);
   getch();
	return 0;
}


printStructEmp(struct emp e)
{
	printf("ID: %d, Name: %s, Salary: %d", e.id, e.name, e.salary);

}


