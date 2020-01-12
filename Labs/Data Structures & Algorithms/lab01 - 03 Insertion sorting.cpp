#include <iostream>
#include <math.h>

using namespace std;

void swap(int &n1, int &n2);
void insertion_sort(int arr[], int n);

int main()
{
    int arr[] = {4, 5, 2, -48, -23, 12, 34, 524, 21};
    insertion_sort(arr, sizeof(arr)/4);
    for(int i=0; i<sizeof(arr)/4; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
//insertion sort
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

void swap(int &n1, int &n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
