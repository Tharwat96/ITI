#include <stdio.h>
#include <stdlib.h>

int factorial (int num);


int main()
{
    int n;
    int x = 6;
    int res;
    printf("Please enter a number to get its factorial: ");
    scanf("%d", &n);
    res = fctrial(n);
    printf("%d", res);

    return 0;
}


    int fctrial (int m)
    {
        int i;
        for (i=m-1; i>1; i--)
        {
            m = m * i;
        }
        return m;
    }
