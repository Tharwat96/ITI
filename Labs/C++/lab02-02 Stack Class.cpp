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
    cout<<"Please enter the size of the stack"<<endl;
    cin>>sz;
    Stack s1=Stack(sz);
    cout<<"Please enter a value to push"<<endl;
    cin>>val;
    s1.push(val);
    cout<<"Please enter another value to push"<<endl;
    cin>>val;
    s1.push(val);
    cout<<"Printing the stack contents: ";
    s1.print();
    cout<<"First pop: "<<s1.pop()<<endl;
    cout<<"Second pop: "<<s1.pop()<<endl;
    cout<<"Third pop: "<<s1.pop()<<endl;

    return 0;
}
