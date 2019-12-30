#include <stdio.h>
#include <conio.h>

void move(int* ch);

int main()
{

	int i, f=1, pos=0;
   char ch;
	char name[20]={" "};
   clrscr();

   do
   {
   	clrscr();
   	for(i=0; i<20; i++)
      {
         if(name[i]!="\0")
         {
      	gotoxy(10+pos,10);
         textattr(0x90);
			cprintf("%c", name[i]);
         textattr(0x07);
         }
         else
         	return;
      }
		ch=getch();
		switch (ch)
      {
      	case 77:		//right arrow
				if(pos>=0 && pos <20)
            	pos++;
            else if(pos == 19)
            	pos=0;

         	break;
      	case 75:		//left arrow
				if(pos>0 && pos <20)
            pos--;
            
         	break;


      }
   }while(f==1);
	return 0;
}

void move(int* c)
{
	switch (*c)
      {
      	case 77:		//right arrow
            printf("You just pressed right arrow");
            getch();
         	break;
      	case 75:		//left arrow
            printf("You just pressed left arrow");
            getch();
         	break;


      }
      getch();
}
