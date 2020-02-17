#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
  GetStdHandle( STD_OUTPUT_HANDLE ),
  coord
    );
  }
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}



class Stack
{
    int tos;
    int sz;
    int* st;

public:
    Stack(int sz = 10)
    {
        this->sz = sz;
        tos =0;
        st = new int[sz];
        cout<<"stack constructor called"<<endl;
        count++;
    }
    ~Stack()
    {
        cout<<"destructor called"<<endl;
        count--;
    }
    void print();
    void push(int);
    int pop();
    static int count;
};
void Stack::print()
{
    for(int i=0; i < this->tos; i++)
    {
        cout<<this->st[i]<<endl;
    }
}
int Stack::count =0;
void Stack::push(int n)
{
    if(this->tos==this->sz)
        cout<<"Stack is full"<<endl;
    else
    {
        this->st[this->tos]=n;
        this->tos++;
    }
}

int Stack::pop()
{
    if(this->tos==0)
        return -1;
    else
    {
        this->tos--;
        return this->st[this->tos];

    }
}

int main()
{
    int sz, val;

    Stack s1;
    /*
    s1.push(5);
    s1.push(6);
    s1.print();
    cout<<s1.pop()<<endl;
    s1.print();*/

    int i, pos=0, f=1;
   char btn;
	char menu[3][10]= {"push", "pop", "print"};
   do
   {
   	system("cls");
   	for(i=0; i<3; i++)
   	{

   		gotoxy(10, 10+i);
	      if (i==pos)
         {
         	textattr(0xc0);
         	cout<<menu[i];
         }
   	   else
         	cout<<menu[i];
	      	textattr(0x07);


   	}
      btn = getch();
      switch (btn)
      {
         case -32:
         	btn = getch();
            if(btn == 72)      //up arrow
            {
            	if (pos==0)
               	pos=2;
               else
               	pos--;
            }
            if (btn == 80)		//down arrow
         	{
            	if(pos==2)
               	pos = 0;
               else
               	pos++;
            }
         	break;

         case 13:    //enter key
            system("cls");
            switch(pos)
            {
                case 0:     //push
                    system("cls");
                    cout<<"Please enter a value to push to stack"<<endl;
                    cin>>val;
                    s1.push(val);

                    break;
                case 1:     //pop
                    cout<<s1.pop();
                    break;
                case 2:     //print
                    s1.print();
                    break;
            }


            getch();
            break;

         case 27: 	//esc key
         	f=0;


      }
   }while(f==1);

    return 0;
}
