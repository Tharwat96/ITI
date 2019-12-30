#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void setX(int);
    void setY(int);

    int getX();
    int getY();

};

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int x)
{
    this->y = y;
}

int Point::getX()
{
    return this->x;
}
int Point::getY()
{
    return this->y;
}

class Shape
{
    int color;
};

class Line : public Shape
{
    Point start;
    Point end;

public:
    Line() : start(), end()
    { cout << "At line Constructor";     }

    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
    { cout << "At line Constructor";    }

    void draw()
    {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape
{
    Point ul;
    Point lr;

public:
    Rect() : ul(), lr()
    { cout << "At Rect Constructor";     }

    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2)
    { cout << "At Rect Constructor";    }

    void draw()
    {
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle : public Shape
{
    Point center;
    int radius;

public:
    Circle() : center()
    {
        radius = 0;
        cout << "At Rect Constructor";
    }

    Circle(int x, int y, int r) : center(x, y)
    {
        radius = r;
        cout << "At Rect Constructor";
    }


    void draw()
    {
        circle(center.getX(), center.getY(), radius);
    }
};


class Picture
{
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
public:
    Picture()
    {
        cNum=0;
        rNum=0;
        lNum=0;
        pCircles = NULL;
        pRects = NULL;
        pLines = NULL;
    }

    Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
    {
        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircles = pC;
        pRects = pR;
        pLines = pL;
    }
    void paint();
    void setCircles(int, Circle*);
    void setRects(int, Rect*);
    void setLines(int, Line*);
};

void Picture::setCircles(int s, Circle *arr)
{
    this->cNum = s;
    this->pCircles = arr;
}

void Picture::setRects(int s, Rect *arr)
{
    this->rNum = s;
    this->pRects = arr;
}

void Picture::setLines(int s, Line *arr)
{
    this->lNum = s;
    this->pLines = arr;
}

/*void Picture::paint()
{
    int i;
    setcolor(WHITE);        //red light
    pCircles[0].draw();
    //setfillstyle(SOLID_FILL,RED);
    //floodfill(285,135,WHITE);


    setcolor(WHITE);
    pCircles[1].draw();
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(285,186,WHITE);

    setcolor(WHITE);
    pCircles[2].draw();
    //setfillstyle(SOLID_FILL,GREEN);
    //floodfill(285,242,WHITE);

    setcolor(5);

    for(i=0; i<rNum; i++)
        pRects[i].draw();

    setcolor(BLUE);

    for(i=0; i<lNum; i++)
        pLines[i].draw();
}*/

int main()
{
    int i,j,k;
    //int gdrive = DETECT, gmode, errorCode;
    //initgraph(&gdrive, &gmode, "");
    //errorCode = graphresult();



    /*Picture pic;
    for(i=0; i<1000; i++)
    {
        cleardevice();
        Circle cArr[3]={Circle(280-i,130,25), Circle(280-i,185,25), Circle(280-i,241,25)};
        Rect rArr[3]={Rect(245-i,100,315-i,270)};
        Line lArr[5]={Line(315-i, 270, 315-i, 390)};

        pic.setCircles(3, cArr);
        pic.setRects(3, rArr);
        pic.setLines(5, lArr);

        pic.paint();
        delay(20);

    }*/


    getch();
    return 0;
}
