int main()
{
   	int i, col, row, size, totalSize;
    clrscr();
    printf("Please enter your box size: ");
    scanf("%d", &size);
    totalSize=size*size;
    for(i=0; i<=totalSize; i++)
    {
        if(i==1)
        {
            row=1;
            col=(size+1)/2;
        }
        else if((i-1)%size==0)
        {
            row++;
        }
        else 
        {
            col--;
            row--;
        if(row==0)
            row=size;
        else if(col==0)
                col=size;
        }
        gotoxy(col+5,row+3);
        printf("%d", i);
        
    }
    getch();
    return 0;
}