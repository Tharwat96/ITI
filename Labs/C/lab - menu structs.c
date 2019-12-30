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
   int i, pos=0, f=1, size, index, srchid, srchflg=-1;
   char srchname[20];
   char btn;
	char menu[5][20]= {"add", "display", "search by id", "search by name", "exit"};
   struct emp* e;
   e=(struct emp*)malloc(size*sizeof(struct emp));
   printf("Please type required number of employees (size of array): ");
   scanf("%d", &size);
   for(i=0; i<size; i++)
   	e[i].id=-1;		//assigning default value of id
   getch();
   do
   {
   	clrscr();
   	for(i=0; i<5; i++)
   	{

   		gotoxy(10, 10+i);
	      if (i==pos)
         {
         	textattr(0xc0);
         	cprintf("%s", menu[i]);
         }
   	   else
         	printf("%s", menu[i]);
	      	textattr(0x07);


   	}
      btn = getch();
      switch (btn)
      {
         case NULL:
         	btn = getch();
            if(btn == 72)      //up arrow
            {
            	if (pos==0)
               	pos=4;
               else
               	pos--;
            }
            if (btn == 80)		//down arrow
         	{
            	if(pos==4)
               	pos = 0;
               else
               	pos++;
            }
         	break;

         case 13:    //enter key
           	clrscr();
            switch (pos)
            {
            	case 0:		//add
                  printf("Please enter the index to insert in: ");
                  scanf("%d", &index);
            		if(e[index].id != -1 || index >= size)
                  {
                  	if(index>=size)
                     {
                     	printf("Entered index is out of entered size limit!\n");
                        break;
                     }
							printf("there is entered data in this index\npress Y to confirm override or N to go back to main menu");
                     if(getch()==121) //Y key
                        e[index]=getStructEmpData();
                     else
                     	break;
						}
                  else
                  {
                  	 e[index]=getStructEmpData();
                      break;
                  }
               	break;
            	case 1:		//display
               	for(i=0; i<size; i++)
                  {
                  	if(e[i].id != -1)
								printf("\nID: %d\nName: %s\nSalary: %d\n", e[i].id, e[i].name, e[i].salary);
                  }
                  getch();
               	break;
               case 2:		//search by id
               	printf("Please enter the id to search for: ");
                  scanf("%d", &srchid);
                  srchflg=-1;
                  for(i=0; i<size; i++)
                  {
                  	if(srchid==e[i].id)
								printf("\nID: %d\nName: %s\nSalary: %d\n", e[i].id, e[i].name, e[i].salary);
                        printf("%d", srchflg);
                        srchflg=0;
                  }
                  if(srchflg!=0)
                     	printf("No data found\n");
                  getch;
               	break;
               case 3:		//search by name
                  printf("Please enter a name to search for: ");
                  gets(srchname);
                  for(i=0; i<size; i++)
                  {
                     if(e[i].id!=-1)
                  		if(strcmp(srchname, e[i].name) == 0)
                     		printf("ID: %d\nName: %s\nSalary: %d\n", e[i].id, e[i].name, e[i].salary);

                  }
               	break;
            	case 4:		//exit
               	f=0;
                  break;
            }
            getch();
            break;
         case 27: 	//esc key
         	f=0;

      }
   }while(f==1);
   if(f==0)
   	free(e);
	return 0;
}

/*void cprint(char m[p][])
{
	textattr(0x70);
	cprintf("%s", menu[p]);
}*/


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

