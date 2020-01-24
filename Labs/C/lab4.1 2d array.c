#include <stdio.h>
#include <stdlib.h>

void setDegrees(int d[][4]);
void viewDegrees(int d[][4]);
void sumDegrees(int d[][4], int s[]);

int main()
{
   int deg[3][4],sum[3]={0}, avg[4]={0};
    int c, f=0;
    while (f==0)
    {
        printf("Please select your choice:\n");
        printf("\n\n1- Insert student degrees   2- View the degrees     3- Sum of degrees  4- Average of degrees    5- Exit\n");
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
                sumDegrees(deg, sum);
                break;
            case 4:
                f=1;
                break;
        }

    }



    return 0;
}

void setDegrees(int d[][4])
{
    int i,j;
    printf("Please type the students degrees: \n");
    for (i=0; i<3; i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Student #%d Subject #%d\n", i+1, j);
            scanf("%d", &d[i][j]);
        }
    }
}

void viewDegrees(int d[][4])
{
    int i,j;
    printf("These are the degrees entered for the student.");
    for(i=0; i<3; i++)
    {
        for(j=0;j<4;j++)
        {
            printf("The degree of student #%d and subject#%d is:  %d\n\n", i+1, j, d[i][j]);
        }
    }
}


void sumDegrees(int d[][4], int s[])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            s[i] += d[i][j];
            printf("\n\nthis is a test for evaluating the sum array i: %d j: %d sum: %d", i, j, s[i]);
        }
        
        printf("\nThe sum of grades for student %d is: %d \n", i+1, s[i]);

    }
    
}


