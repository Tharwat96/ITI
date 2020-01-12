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

    Complex operator + (const Complex &n);  //plus operator overload for multiple complexes
    Complex operator - (const Complex &n);  //minus operator overload for multiple complexes
    Complex operator + (float);   //plus operator overload for adding 1 complex to float
    Complex operator - (float);   //minus operator overload for subtracting 1 complex to float
    friend Complex operator + (float, Complex); //plus operator overload for adding float LHto complex RH
    friend Complex operator - (float, Complex); //minus operator overload for subtracting float LHto complex RH
    int operator == (Complex);  //overloading operator == for Complex class
    void operator += (const Complex n); //overloading += operator for complexes
    void operator -= (const Complex n); //overloading -= operator for complexes
    Complex operator++();      //prefix increment overload
    Complex operator++(int);      //postfix increment overload
    Complex operator--();      //prefix decrement overload
    Complex operator--(int);      //postfix decrement overload
    operator float();       //casting float for complex



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
Complex Complex::operator + (const Complex &n) //overloading + operator for complexes
{
    Complex tmp;
    tmp.real = this->real + n.real;
    tmp.imag = this->imag + n.imag;
    return tmp;
}

Complex Complex::operator - (const Complex &n) //overloading - operator for complexes
{
    Complex tmp;
    tmp.real = this->real - n.real;
    tmp.imag = this->imag - n.imag;
    return tmp;
}

Complex Complex::operator + (float n) //overloading + operator for adding one complex to float
{
    Complex tmp;
    tmp.real = this->real + n;
    tmp.imag = imag;
    return tmp;
}

Complex Complex::operator - (float n) //overloading - operator for subtracting one complex to float
{
    Complex tmp;
    tmp.real = this->real - n;
    tmp.imag = imag;
    return tmp;
}

int Complex::operator == (Complex c)    //overloading == operator for complex
{
    int com=0;
    if(this->real == c.real && this->imag == c.imag)
        com=1;

    return com;
}

void Complex::operator += (const Complex n) //overloading += operator for complexes
{
    this->real = this->real + n.real;
    this->imag = this->imag + n.imag;
}

void Complex::operator -= (const Complex n) //overloading -= operator for complexes
{
    this->real = this->real - n.real;
    this->imag = this->imag - n.imag;
}

Complex Complex::operator++()      //prefix increment overload
{
    this->real+1;
    return *this;
}

Complex Complex::operator--()      //prefix decrement overload
{
    this->real-1;
    return *this;
}

Complex Complex::operator++(int)         //postfix increment overload
{
    Complex tmp;
    tmp.real = this->real+1;
    tmp.imag = this->imag;
    return tmp;
}

Complex Complex::operator--(int)         //postfix decrement overload
{
    Complex tmp;
    tmp.real = this->real-1;
    tmp.imag = this->imag;
    return tmp;
}

Complex::operator float()       //casting float for complex
{
    return real;
}

int main()
{
    Complex myComp1, myComp2, testComp, resultComp;
    float rnum1, rnum2, inum1, inum2;
    cout<<"\nPlease type a real number for first var: ";
    cin>>rnum1;
    myComp1.setReal(rnum1);
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
    cout<<"Summing the value of myComp1 and myComp2: "<<endl;
    testComp = myComp1 + myComp2;
    testComp.print();

    /*cout<<"Subtracting the value of myComp1 and myComp2: "<<endl;
    testComp = myComp1 - myComp2;
    testComp.print();*/

    /*cout<<"Summing the value of myComp1 and float(5): "<<endl;
    testComp = myComp1 + 5;
    testComp.print(); */

    /*cout<<"Subtracting the value of myComp1 and float(5): "<<endl;
    testComp = myComp1 - 5;
    testComp.print();*/

    /*cout<<"Summing the value of float(5) and myComp1: "<<endl;
    testComp = 5 + myComp1;
    testComp.print();*/

    /*cout<<"Subtracting the value of float(5) and myComp1: "<<endl;
    testComp = 5 - myComp1;
    testComp.print();*/

    /*cout<<"evaluating myComp1 and myComp2: "<<endl;
    if(myComp1==myComp2)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;*/


    //testComp.print();


    /*myComp1+=myComp2;
    cout<<"Adding the value of myComp2 to myComp1: ";
    myComp1.print();*/


    cout<<"casting the value of myComp1: "<<(float)myComp1<<endl;



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


Complex operator + (float n, Complex c) //plus operator overload for adding float LH to complex RH
{
    Complex tmp;
    tmp.real = n + c.real;
    tmp.imag = c.imag;
    return tmp;
}
Complex operator - (float n, Complex c) //minus operator overload for subtracting float LH to complex RH
{
    Complex tmp;
    tmp.real = n - c.real;
    tmp.imag = c.imag;
    return tmp;
}
