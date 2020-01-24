#include <stdio.h>
#include <stdlib.h>

int calc(float n1, float n2, int op);

int main()
{
    float n1, n2, result;
    int op;
    printf("Please type the first number: ");
    scanf("%f", &n1);
    printf("Please type the second number: ");
    scanf("%f", &n2);
    printf("Please type the type of calculation needed: ");
    printf("\n1 - Add    2- Subtract     3- Multiply       4- Divide\n");
    scanf("%d", &op);
    printf("\n\nYour result = %f", calc(n1, n2, op));
    return 0;
}


int calc(float n1, float n2, int op)
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