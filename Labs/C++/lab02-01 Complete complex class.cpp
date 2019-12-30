#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
	float real;
    float imag;
public:
    Complex()   //constructor definition
    {
        cout<<"Constructor was called :D"<<endl;
    }
    ~Complex()  //destructor definition
    {
        cout<<"object was destructed"<<endl;
    }
    void setReal(float);
    void setImag(float);
    void setComplex(float r, float i);
    float getReal();
    float getImag();
    void print();

};

void Complex::setReal(float i)
{
	real=i;
}

void Complex::setImag(float i)
{
	imag=i;
}

void Complex::setComplex(float r, float i)
{
    real = r;
    imag = i;
}

float Complex::getReal()
{
	return real;
}

float Complex::getImag()
{
	return imag;
}

void Complex::print()
{
    if(imag<0)
        cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
    else
        cout<<real<<" + "<<imag<<"i"<<endl;
}

Complex add(Complex c1, Complex c2);
Complex subtract(Complex c1, Complex c2);

int main()
{
    Complex myComp1, myComp2, resultComp;
    float rnum1, rnum2, inum1, inum2;
    cout<<"\nPlease type a real number for first var: ";
    cin>>rnum1;
    myComp1.setReal(rnum1);
    cout<<"\nthis is rnum1: "<<rnum1<<endl;

    cout<<"\nPlease type a real number for second var: ";
    cin>>rnum2;
    myComp2.setReal(rnum2);
    cout<<"\nPlease type an imaginary number for first var: ";
    cin>>inum1;
    myComp1.setImag(inum1);
    cout<<"\nPlease type an imaginary number for second var: ";
    cin>>inum2;
    myComp2.setImag(inum2);

    myComp1.print();
    myComp2.print();
    cout<<"will add the complex numbers on the next line"<<endl;
    resultComp = add(myComp1, myComp2);
    resultComp.print();
	return 0;
}

Complex add(Complex c1, Complex c2)
{
    Complex result;
    result.setReal(c1.getReal()+c2.getReal());
    result.setImag(c1.getImag()+c2.getImag());
    return result;
}

Complex subtract(Complex c1, Complex c2)
{
    Complex result;
    result.setReal(c1.getReal()-c2.getReal());
    result.setImag(c1.getImag()-c2.getImag());
    return result;
}
