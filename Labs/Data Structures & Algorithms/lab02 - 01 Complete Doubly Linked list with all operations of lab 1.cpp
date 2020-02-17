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


void LinkedList::sortAll()      //USING INSERTION SORT
{
    if(!pStart)     //Empty list
        return;
    Employee *pTemp = pStart->pNext;
    int tempCode = pTemp->getCode();
    if(pTemp && !pTemp->pNext) //only list
        return;
    else
    {
        for(int i = 1; pTemp!=NULL; i++)
        {
            int j = i-1;
            while( (j >= 0) && (tempCode < pTemp->getCode()) )
            {
                if(pTemp == pStart && pTemp != pEnd)    //first list and not alone
                {

                }
                else if( (pTemp != pStart) && (pTemp == pEnd) )    //last list and not alone
                {

                }
                else     // in the middle
                {

                }
                j = j-1;
            }

        }
    }
}

    /*for(int i = 1; i<size; i++)
    {
        //setting temp values
        idValue = employees[i].getID();
        nameValue = employees[i].getName();
        int j= i-1;
        while ( (j >= 0) && (idValue < employees[j].getID()))   //find optimal place for current temp
        {
            employees[j+1].setID(employees[j].getID());
            employees[j+1].setName(employees[j].getName());
            j = j-1;
        }
        employees[j+1].setID(idValue);
        employees[j+1].setName(nameValue);

    }*/







int main()
{
    int del;
    Employee e1(5, "tharwat", 3500, 15);
    e1.printEmployee();
    Employee e2(7, "mina", 4000, 12);
    e2.printEmployee();
    Employee e3(2, "mostafa", 6500, 15);
    e3.printEmployee();
    cout<<"------------------LINKED LIST---------------"<<endl;
    LinkedList list;
    list.addList(&e1);
    list.insertList(&e2);
    list.insertList(&e3);
    list.displayAll();
    cout<<"------------------Delete item---------------"<<endl;
    cout<<"Enter an ID to delete from list"<<endl;
    cin>>del;
    if(list.deleteList(del) == 1)
        cout<<"DELETED!"<<endl;
    else
        cout<<"Could not be deleted, not found"<<endl;
    list.displayAll();


    cout<<"------------------FREE LINKED LIST---------------"<<endl;
    list.freeList();
    list.displayAll();

    return 0;
}



