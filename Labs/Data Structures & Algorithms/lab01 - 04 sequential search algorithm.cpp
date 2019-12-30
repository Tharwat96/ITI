#include <iostream>
#include <math.h>

using namespace std;

int sequential_search (int arr[], int size, int num);

int main()
{
    int num, res;
    int arr[] = {4, 5, 2, -48, -23, 12, 34, 524, 21};
    cout<<"Please enter a value to search for: ";
    cin>>num;
    cout<<endl;
    res = sequential_search(arr, 9, num);
    cout<<res<<endl;
    if (res != -1)
        cout<<"Your value was found at index # "<<res<<endl;
    else
        cout<<"Your value was not found"<<endl;

    return 0;
}


int sequential_search (int arr[], int size, int num)
{

    //cout<<"sizeof= "<<sizeof(arr)/4<<endl;

    cout<<"size= "<<size<<endl;

    int i = 0, found = 0;
    while((!found) && (i<size))
    {
        if (num == arr[i])
        {
            found = 1;
            cout<<"found ="<<found<<endl;
        }
        else
            i++;
    }
    if (found)
        return i;
    else
        return -1;
}
