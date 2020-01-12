#include <iostream>
#include <math.h>

using namespace std;

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
        delete[] st;
        cout<<"destructor called"<<endl;
        count--;
    }
    friend void viewContentVal (Stack s);
    friend void viewContentValCop (Stack s);
    friend void viewContentRef (Stack &s);

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

/*void viewContentVal (Stack s)
{
    int top = s.tos;
    while (top!=0)
        cout<<s.st[--top]<<endl;

}*/

void viewContentValCop (Stack s)
{

    int tos = s.tos;
    int sz = s.sz;
    int* st = new int [sz];
    for(int i = 0; i<tos ; i++)
        st[i] = s.st[i];
    while (tos!=0)
        cout<<st[--tos]<<endl;
    //count++;

}


void viewContentRef (Stack &s)
{
    int top = s.tos;
    while (top!=0)
        cout<<s.st[--top]<<endl;

}


int main()
{
    int sz;
    cout<<"Please enter the size of the stack"<<endl;
    cin>>sz;
    Stack s1=Stack(sz);
    s1.push(8);
    s1.push(6);
    s1.push(9);
    //cout<<"using view content by value: "<<endl;
    //viewContentVal(s1);

    //cout<<"using view content by value copying: "<<endl;
    //viewContentValCop(s1);

    cout<<"using view content by reference: "<<endl;
    viewContentRef(s1);
    s1.print();
    cout<<s1.pop()<<endl;
    s1.print();


    return 0;
}


