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
    void push(int);
    int pop();
    void print();
    static int count;
    Stack& operator = (const Stack& s);
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

Stack& Stack::operator =(const Stack &c)
{
    this->tos = c.tos;
    this->sz = c.sz;
    delete[] this->st;
    this->st = new int[this->sz];
    for (int i = 0; i<tos; i++)
        this->st[i] = c.st[i];
    return *this;
}

int main()
{
    int sz, val;
    cout<<"Please enter the size of the stack (s1): "<<endl;
    cin>>sz;
    Stack s1=Stack(sz);
    Stack s2(5);
    cout<<"Please enter a value to push to s1: "<<endl;
    cin>>val;
    s1.push(val);
    cout<<"Please enter another value to push to s1: "<<endl;
    cin>>val;
    s1.push(val);
    cout<<"Printing the s1 stack contents: "<<endl;
    s1.print();

    cout<<"Copying s1 contents to s2.."<<endl;
    s2=s1;

    cout<<"Printing the s2 stack contents: "<<endl;
    s2.print();

    cout<<"First pop: "<<s1.pop()<<endl;
    cout<<"Second pop: "<<s1.pop()<<endl;
    cout<<"Third pop: "<<s1.pop()<<endl;

    return 0;
}
