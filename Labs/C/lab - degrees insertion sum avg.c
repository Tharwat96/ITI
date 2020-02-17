#include <stdio.h>
#include <conio.h>

void setDegrees(int d[][4]);
void viewDegrees(int d[][4]);
void sumDegrees(int d[][4], int s[]);
void avgDeg(int d[][4], float a[]);

int main()
{
    int deg[3][4];
    int sum[3]={0};
    float avg[4]={0};
    int c, f=0;
    while (f==0)
    {
    	clrscr();
		printf("Please select your choice:\n");
		printf("\n\n1- Insert student degrees   2- View the degrees		3- Sum of degrees  4- Average of degrees    5- Exit\n");
		scanf("%d", &c);

		switch(c)
		{
			case 1:
				setDegrees(deg);
				break;
			case 2:
				viewDegrees(deg);
            getch();
				break;
			case 3:
				sumDegrees(deg, sum);
            getch();
				break;
         case 4:
         	avgDeg(deg, avg);
            getch();
         	break;
			case 5:
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
        }

        printf("\nThe sum of grades for student %d is: %d \n", i+1, s[i]);

    }

}


void avgDeg(int d[][4], float a[])
{
    int i, j;
    for(i=0; i<3; i++)
    {
      a[i] = 0;
        for(j=0; j<4; j++)
        {
            a[i] += d[i][j];
        }
        a[i] = a[i] / 4;
        printf("\nThe avg of grades for student %d is: %f \n", i+1, a[i]);

    }

}
