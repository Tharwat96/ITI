#include <stdio.h>
#include <stdlib.h>

int power (int m, int b);


int main()
{
    int b, p;
    int res;
    printf("Please enter a number to get its exponent: ");
    scanf("%d", &b);
    printf("Please enter the power: ");
    scanf("%d", &p);

    res = power(b, p);
    printf("%d", res);

    return 0;
}


    int power (int m, int p)
    {
        int i, res=1;
        for (i=0; i < p; i++)
        {
            res *= m;
        }
        return res;
    }
