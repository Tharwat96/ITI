#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

class GeoShape
{
protected:
    float dim1;
    float dim2;

public:
    GeoShape()
    {
        dim1 = dim2 = 0;
    }
    GeoShape(float x)
    {
        dim1 = dim2 = x;
    }
    GeoShape(float x, float y)
    {
        dim1 = x;
        dim2 = y;
    }
    void setDim1(float x)
    {
        dim1 = x;
    }
    void setDim2(float y)
    {
        dim2 = y;
    }
    float getDim1()
    {
        return dim1;
    }
    float getDim2()
    {
        return dim2;
    }
    virtual float calculateArea() = 0;

};

class Triangle : public GeoShape
{
public:
    Triangle(float b, float h) : GeoShape(b,h){}

    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Circle : public GeoShape
{

public:
    Circle(float r) : GeoShape(r) {}

    void setRadius(float r)
    {
        dim1 = dim2 = r;
    }

    float getRadius()
    {
        return dim1;
    }

    float calculateArea()
    {
        return 22.0/7 * dim1 * dim2;
    }
};

class Rect : public GeoShape
{
public:
    Rect(float x, float y) : GeoShape(x, y) {}

    float calculateArea()
    {
        return dim1 * dim2;
    }
};

class Square : public Rect
{
public:
    Square(float x) : Rect(x, x) {}

    void setSquareDim(float x)
    {
        dim1 = dim2 = x;
    }

    float getSquareDim()
    {
        return dim1;
    }

    float calculateArea()
    {
        return Rect::calculateArea();
    }

};

float sumOfAreas(int num_of_shapes, GeoShape **arr);

int main()
{
    Square s2(5);
    GeoShape **ptr;
    ptr = new GeoShape*[4];
    ptr[0] = new Circle(5);
    ptr[1] = new Rect(5, 10);
    ptr[2] = new Square(5);
    ptr[3] = new Triangle(3, 6);
    cout << "The area of all objects: " << sumOfAreas(4, ptr) << endl;
    cout<<s2.getSquareDim()<<endl;
    return 0;
}


float sumOfAreas(int num_of_shapes, GeoShape **arr)
{
    int sum=0;
    for(int i = 0; i<num_of_shapes; i++)
    {
        sum += arr[i]->calculateArea();
    }
    return sum;
}
