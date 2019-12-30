#include <iostream>
#include <math.h>

using namespace std;

class Employee
{
    string name;
    int id;

public:
    Employee()
    {
        name = "";
        id = -1;
    }
    void setName(string name);
    string getName();
    void setID(int id);
    int getID();


};

void Employee::setName(string name)
{
    this->name = name;
}

string Employee::getName()
{
    return this->name;
}

void Employee::setID(int id)
{
    this->id = id;
}
int Employee::getID()
{
    return this->id;
}

int sequential_search (Employee employees[], int size, string name);

void insertion_sort(Employee employees[], int size);


int main()
{
    int res;
    string name;
    Employee arr[4];
    arr[0].setID(5);
    arr[0].setName("tharwat");
    arr[1].setID(15);
    arr[1].setName("eslam");
    arr[2].setID(16);
    arr[2].setName("mina");
    arr[3].setID(4);
    arr[3].setName("mostafa");

    cout<<"-----Before sort-------"<<endl;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        cout<<"ID: "<<arr[i].getID()<<"\tName: "<<arr[i].getName()<<endl;

    insertion_sort(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"------After sort------"<<endl;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        cout<<"ID: "<<arr[i].getID()<<"\tName: "<<arr[i].getName()<<endl;

    cout<<"Please enter a name to search for: ";
    cin>>name;
    cout<<endl;
    res = sequential_search(arr, sizeof(arr)/sizeof(arr[0]),name);
    if (res != -1)
        cout<<"Your name has an ID of: "<<res<<endl;
    else
        cout<<"Your name was not found"<<endl;
    arr[3].getCode();
    return 0;
}


int sequential_search (Employee employees[], int size, string name)
{
    int i = 0, found = 0;
    while((!found) && (i<size))
    {
        if (name == employees[i].getName())
        {
            found = 1;
        }
        else
            i++;
    }
    if (found)
        return employees[i].getID();
    else
        return -1;
}

void insertion_sort(Employee employees[], int size)
{
    int idValue;
    string nameValue;
    for(int i = 1; i<size; i++)
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

    }

}
