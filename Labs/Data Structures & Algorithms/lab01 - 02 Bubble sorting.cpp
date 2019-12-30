#include <iostream>
#include <math.h>

using namespace std;

void swap(int &n1, int &n2);
void bubble_sort(int arr[], int length);

int main()
{
    int arr[] = {4, 5, 2, 48, 23, 12, 34, 524, 21};
    bubble_sort(arr, sizeof(arr)/4);
    for(int i=0; i<sizeof(arr)/4; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
//bubble sort: stoppping condition is no more swapping
//if one swap done at any outer loop, a new loop is done
void bubble_sort(int arr[], int n)
{
    int swapped;    //flag to check if the array was sorted in an inner loop
    for(int i = 1; i < n; i++)
    {
        swapped = 0;
        for(int j=0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = 1;

            }
        }
    if(!swapped)
        break;

    }

}

void swap(int &n1, int &n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
