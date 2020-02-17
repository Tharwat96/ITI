#include <stdio.h>
#include <conio.h>

void swap(int* first, int* second);

int main()
{
   int n1, n2;
   clrscr();
   printf("\nInsert your first number: \n");
   scanf("%d", &n1);
   printf("\nInsert your second number: \n");
   scanf("%d", &n2);
   swap(&n1, &n2);
   printf("\nNow the first number is: %d, and the second number is: %d\n", n1, n2);


	getch();
	return 0;
}


void swap(int* first, int* second)
{
	int temp;
   temp = *first;
   *first = *second;
   *second = temp;




}