#include <iostream>
#include <math.h>

using namespace std;

/*-----------EMPLOYEE_CLASS-------------*/

class Employee
{
    string name;
    float salary;
    float oTime;        //overtime
    int code;
public:
    Employee *pNext;
    Employee *pPrevious;
    Employee()
    {
        code = 0;
        name = "no name";
        salary = oTime = 0;
        pNext = NULL;
        pPrevious = NULL;
    }
    Employee(int c, string n, float s, float o)
    {
        code = c;
        name = n;
        salary = s;
        oTime = o;
        pNext = NULL;
        pPrevious = NULL;
    }
    //setters and getters
    void printEmployee();
    int getCode();

};

void Employee::printEmployee()
{
    cout<<"Name: "<<this->name<<endl;
    cout<<"Salary: "<<this->salary<<endl;
    cout<<"Over Time: "<<this->oTime<<endl;
    cout<<"Code: "<<this->code<<endl;

}

int Employee::getCode()
{
    return this->code;
}


/*-----------LINKED_LIST_CLASS-------------*/
class LinkedList
{
protected:
    Employee *pStart;
    Employee *pEnd;
public:
    LinkedList()
    {
        pStart=pEnd=NULL;
    }
    ~LinkedList()
    {
        freeList();
    }
    //setters and getters
    void addList(Employee *pItem);
    void insertList(Employee *pItem);
    Employee* searchList(int Code);
    void freeList();
    void displayAll();
    void sortAll();
    int deleteList(int code);

};

void LinkedList::addList(Employee *pItem)
{
    if(!pStart)     //case of empty linked list
    {
        pItem->pNext = pItem->pPrevious = NULL;
        pStart = pEnd = pItem;
    }
    else    //if there are current lists in the linked list
    {
        pEnd->pNext = pItem;
        pItem->pPrevious = pEnd;
        pItem->pNext = NULL;
        pEnd = pItem;
    }
}

void LinkedList::insertList(Employee *pItem)
{
    Employee *pTemp;
    if(pStart == NULL)      //empty list
        addList(pItem);
    else
    {
        pTemp = pStart;
        while(pTemp && pTemp->getCode() < pItem->getCode())     //finds optimal location    or NULL if it fits last
            pTemp = pTemp->pNext;
        if(!pTemp)          //if it fits last it will be NULL, add to last
            addList(pItem);
        else if(pTemp == pStart)        //first node
        {
            pItem->pNext = pStart;
            pItem->pPrevious = NULL;
            pStart->pPrevious = pItem;
            pStart = pItem;
        }
        else    //in the middle
        {
            pItem->pNext=pTemp;
            pItem->pPrevious = pTemp->pPrevious;
            pTemp->pPrevious = pItem;
            pItem->pPrevious->pNext = pItem;
        }
    }
}

Employee* LinkedList::searchList(int key)
{
    Employee *pItem = NULL;
    pItem = pStart;     //start from first node
    while(pItem && pItem->getCode() != key)
        pItem = pItem->pNext;
    return pItem;
}

void LinkedList::freeList()
{
    Employee *pItem;
    pItem = pStart;
    while(pItem)
    {
        pItem->pPrevious=pItem->pNext=NULL;
        pItem = pItem->pNext;
    }
    pStart=pEnd=NULL;
}

void LinkedList::displayAll()
{
    Employee *pItem;
    pItem = pStart;
    while(pItem)
    {
        pItem->printEmployee();
        pItem = pItem->pNext;
    }
}

int LinkedList::deleteList(int code)
{
    Employee *pItem;
    int retFlag = 1;
    pItem = searchList(code);
    if(!pItem)
        retFlag = 0;    // not found
    else        //found
    {
        if(pStart == pEnd)
        {
            pStart = pEnd = NULL;
        }
        else if(pItem == pStart)    //case of first node
        {
            pStart = pStart->pNext;
            pStart->pPrevious = NULL;
        }
        else if(pItem == pEnd)    //case of first node
        {
            pEnd = pEnd->pPrevious;
            pEnd->pNext = NULL;
        }
        else    //case of intermediate node
        {
            pItem->pPrevious->pNext = pItem->pNext;
            pItem->pNext->pPrevious = pItem->pPrevious;
        }
            delete pItem;
    }
    return retFlag;
}

/*-----------QUEUE_CLASS as a linked list-------------*/
class Stack:private LinkedList
{
public:
    Stack():LinkedList(){};
    void push(Employee *e)
    {
        LinkedList::addList(e);
    }
    Employee* pop()     //1- go to the end; 2- go step back; 3- remove it
    {
        Employee *pNode;
        pNode = pEnd;
        if(pEnd)
        {
            if(pStart == pEnd)
                pStart = pEnd = NULL;
        }
        else
        {
            pEnd = pEnd->pPrevious;
            pEnd->pNext = NULL;
        }
    }

    Employee* searchStack(int Code)
    {
        return searchList(Code);
    }

    void freeStack()
    {
        freeList();
    }
    void displayAll()
    {
        LinkedList::displayAll();
    }

    int deleteStack(int code)
    {
        return deleteList(code);
    }


};


int main()
{
    Employee e1(5, "tharwat", 3500, 15);
    Employee e2(7, "mina", 4000, 12);
    Employee e3(2, "mostafa", 6500, 15);
    cout<<"------------------Stack---------------"<<endl;
    Stack s1;
    s1.push(&e1);
    s1.push(&e2);
    s1.push(&e3);
    s1.displayAll();
    cout<<"------------------pop Stack---------------"<<endl;
    s1.pop();
    s1.displayAll();

    return 0;
}



