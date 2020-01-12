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


class Line
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

class Rect
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

class Circle
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

void Picture::paint()
{
    int i;
    setcolor(RED);

    for(i=0; i<cNum; i++)
        pCircles[i].draw();

    setcolor(5);

    for(i=0; i<rNum; i++)
        pRects[i].draw();

    setcolor(BLUE);

    for(i=0; i<lNum; i++)
        pLines[i].draw();
}

int main()
{
    int gdrive = DETECT, gmode, errorCode;
    initgraph(&gdrive, &gmode, "");
    errorCode = graphresult();



    Picture pic;
    setcolor(RED);
    Circle cArr[1]={Circle(300,200,40)};
    Rect rArr[3]={Rect(285,230,315,370), Rect(135,195,275,220), Rect(42,50,50,30)};
    Line lArr[5]={Line(50, 70, 50, 40), Line(40,50,70,40), Line(40,50,70,40), Line(40,50,70,40), Line(40,50,70,40)};

    pic.setCircles(1, cArr);
    pic.setRects(3, rArr);
    pic.setLines(5, lArr);

    pic.paint();
    getch();
    return 0;
}
