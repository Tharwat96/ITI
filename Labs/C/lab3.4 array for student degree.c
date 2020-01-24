#include <stdio.h>
#include <stdlib.h>
#define size 5
void setDegrees(int d[]);
void viewDegrees(int d[]);
int sumDegrees(int d[]);

int main()
{
    int deg[size];
    int c, f=0;
    while (f==0)
    {
        printf("Please select your choice:");
        printf("\n\n1- Insert student degrees   2- View the degrees     3- Sum of degrees   4- Search for a a degree index 5- Exit\n");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                setDegrees(deg);
                break;
            case 2:
                viewDegrees(deg);
                break;
            case 3:
                printf("\nThe sum of all grades is: %d\n\n", sumDegrees(deg));
                break;
            case 4:

                break;
            case 5:
                f=1;
                break;
        }

    }



    return 0;
}

void setDegrees(int d[])
{
    int i;
    printf("Please type the students degrees: ");
    for (i=0; i<=size; i++)
    {
        printf("Degree #%d\n", i);
        scanf("%d", &d[i]);
    }
}

void viewDegrees(int d[])
{
    int i;
    printf("These are the degrees entered for the student.");
    for(i=0; i<size; i++)
    {
        printf("The degree for the subject#%d is:  %d\n\n", i, d[i]);
    }
}


int sumDegrees(int d[])
{
    int i, sum=0;
    for(i=0; i<size; i++)
    {
        sum += d[i];
    }
    return sum;
}

