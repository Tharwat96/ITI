#include <stdio.h>
#include <stdlib.h>
#define size 5
void getDegrees(int d[]);

int main()
{
    int deg[size];
    int c, y=0;
    while (y==0)
    {
        printf("test %d\n", y);

        printf("Please select your choice:");
        printf("\n\n1- Insert student degrees   2- View the degrees     3- Sum of degrees   4- Search for a a degree index 5- Exit\n");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                getDegrees(deg);
                printf("test %d\n", y);

                break;
            case 2:

            case 5:
                break;
        }

    }



    return 0;
}

void getDegrees(int d[])
{
    int i;
    printf("Please type the students degrees: ");
        for (i=0; i<=size; i++)
    {
        printf("Degree #%d\n", i);
        scanf("%d", &d[i]);
    }
}
