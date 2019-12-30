#include <iostream>
#include <math.h>
using namespace std;

void swapValue(int a, int b);
void swapAdress(int *a, int* b);
void swapReference(int& a, int& b);

int main()
{
    int first=2, second=4;
    int* firstAdd, secondAdd;
    firstAdd=&first;
    //secondAdd=&second;

    cout<<"\nValue before any swapping: "<<first<<" "<<second<<endl;
    swapValue(first, second);
    cout<<"\nValues after swap by value: "<<first<<" "<<second<<endl;
    swapAdress(firstAdd, &second); //had to call address directly instead of using a variable?
    cout<<"\nValues after swap by address: "<<first<<" "<<second<<endl;
    swapReference(first, second); // will be returned to original since it got swapped before already

    cout<<"\nValues after swap by reference: "<<first<<" "<<second<<endl;



    return 0;
}


void swapValue(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;

}

void swapAdress(int* a, int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;

}

void swapReference(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;

}
