#include <iostream>
#include <math.h>

using namespace std;

void swap(int &n1, int &n2);
void selection_sort(int arr[], int length);

int main()
{
    int arr[] = {4, 5, 2, 48, 23, 12, 234, 523, 21};
    selection_sort(arr, sizeof(arr)/4);
    for(int i=0; i<sizeof(arr)/4; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

void selection_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<(n-1); i++)
    {
        int min = i;    // assume that the first element is the min at the beginning
        for(j=(i+1); j<n ; j++)
            if(arr[j] < arr[min])
                min = j;
        if (i != min)
            swap(arr[i], arr[min]);

    }
}

void swap(int &n1, int &n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
