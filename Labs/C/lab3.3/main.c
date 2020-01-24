#include <stdio.h>
#include <stdlib.h>

int calc(int n1, int n2, int op);

int main()
{
    int n1, n2, result, op;
    printf("Please type the first number: ");
    scanf("%d", &n1);
    printf("Please type the second number: ");
    scanf("%d", &n2);
    printf("Please type the type of calculation needed: ");
    printf("\n1 - Add    2- Subtract     3- Multiply       4- Divide");
    op = getch();
    printf("\n\nYour result = %d", calc(n1, n2, op));
    return 0;
}


int calc(int n1, int n2, int op)
{
    int result;
    switch(op){
        case '1':
            result = n1 + n2;
            break;
        case '2':
            result = n1 - n2;
            break;
        case '3':
            result = n1 * n2;
            break;
        case '4':
            result = n1 / n2;
            break;


    }
}
