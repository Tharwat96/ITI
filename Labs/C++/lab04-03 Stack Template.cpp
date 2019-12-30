#include <iostream>
#include <math.h>

using namespace std;

template <class D>
class Stack
{
    int tos;
    int sz;
    D* st;

public:
    Stack<D>(int sz = 10)
    {
        this->sz = sz;
        tos =0;
        st = new D[sz];
        cout<<"stack constructor called"<<endl;
        count++;
    }
    ~Stack()
    {
        cout<<"destructor called"<<endl;
        count--;
    }
    void print();
    void push(D);
    D pop();
    static int count;
};

template <class D>
void Stack<D>::print()
{
    for(int i=0; i < this->tos; i++)
    {
        cout<<this->st[i]<<endl;
    }
}
template <class D>
int Stack<D>::count =0;

template <class D>
void Stack<D>::push(D n)
{
    if(this->tos==this->sz)
        cout<<"Stack is full"<<endl;
    else
    {
        this->st[this->tos]=n;
        cout<<tos;
        this->tos++;
    }
}

template <class D>
D Stack<D>::pop()
{
    cout<<tos;
    if(this->tos==0)
        return -1;
    else
    {
        this->tos--;
        return this->*st[this->tos];

    }
}

int main()
{
    int sz, val;
    cout<<"Please enter the size of the stack int"<<endl;
    cin>>sz;
    Stack<int> s1=Stack<int>(sz);

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


    string sz1, val1;

    cout<<"Please enter the size of the stack string"<<endl;
    cin>>sz1;
    Stack<string> s2;

    cout<<"Please enter a value to push"<<endl;
    cin>>val1;
    s2.push(val1);
    cout<<"Please enter another value to push"<<endl;
    cin>>val1;
    s2.push(val1);
    cout<<"Printing the stack contents: ";
    s2.print();
    cout<<"First pop: "<<s2.pop()<<endl;
    cout<<"Second pop: "<<s2.pop()<<endl;
    cout<<"Third pop: "<<s2.pop()<<endl;

    return 0;
}
