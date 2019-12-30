#include <iostream>
#include <math.h>

using namespace std;

int binary_search (int arr[], int size, int num);
void insertion_sort(int arr[], int n);

int main()
{
    int num, res;
    int arr[] = {4, 5, 2, -48, -23, 12, 34, 524, 21};
    cout<<"Please enter a value to search for: ";
    cin>>num;
    cout<<endl;
    insertion_sort(arr, 9);
    for (int i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
        cout<<arr[i]<<"\t";
    res = binary_search(arr, 9, num);
    cout<<res<<endl;
    if (res != -1)
        cout<<"Your value was found at index # "<<res<<endl;
    else
        cout<<"Your value was not found"<<endl;

    return 0;
}


int binary_search (int arr[], int size, int num)
{
    int found = 0,
        high = size,
        mid = 0,
        low = 0;
    while ((!found) && (low <= high))
    {
        mid = (high + low) /2;

        cout<<"\nhigh = "<<high<<"\t mid= "<<mid<<"\t low= "<<low<<endl;
        if (num > arr[mid])
        {
            low = mid +1;  //go right
            cout<<"inside go right: \nhigh = "<<high<<"\t mid= "<<mid<<"\t low= "<<low<<endl;
        }
        else if (num < arr[mid])
        {
            high = mid -1; //go left
            cout<<"inside go left: \nhigh = "<<high<<"\t mid= "<<mid<<"\t low= "<<low<<endl;
        }
        else
            found = 1;
    }
    if (found)
        return mid+1;
    else
        return -1;

}


void insertion_sort(int arr[], int n)
{
    int value;
    for(int i = 1; i<n; i++)
    {
        value = arr[i];
        int j= i-1;
        while ( (j >= 0) && (arr[j] > value))
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j+1] = value;
    }

}
