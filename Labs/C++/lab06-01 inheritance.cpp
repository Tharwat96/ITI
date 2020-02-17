#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

class Base
{
    int a;
protected:
    int b;
public:
    Base()
    {
        a=b=0;
    }
    Base(int n)
    {
        a=b=n;
    }
    Base(int x, int y)
    {
        a = x;
        b = y;
    }
    void setA(int x)
    {
        a = x;
    }
    void setB(int y)
    {
        b = y;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int product()
    {
        return a*b;
    }
};

class Derived : public Base
{
private:
    int c;
public:
    Derived() : Base()
    {
        c = 0;
    }
    Derived(int n) : Base(n)
    {
        c = n;
    }
    Derived(int x, int y, int z): Base(x,y)
    {
        c = z;
    }
    void setC(int z)
    {
        c = z;
    }
    int getC()
    {
        return c;
    }
    int product()
    {
        return Base::product()*c;
    }
};

class SecondDerived : public Derived
{
private:
    int d;
public:
    SecondDerived() : Derived()
    {
        d = 0;
    }
    SecondDerived(int n) : Derived(n)
    {
        d = n;
    }
    SecondDerived(int x, int y, int m, int z) : Derived(x,y,m)
    {
        d = z;
    }
    void setD(int z)
    {
        d = z;
    }
    int getD()
    {
        return d;
    }
    int product()
    {
        return Derived::product() * d;
    }
};

int main()
{

    SecondDerived obj1(4,3,5,3);
    cout<<obj1.product()<<endl;
    return 0;
}
