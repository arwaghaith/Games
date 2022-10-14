

//task 3
#include <stdio.h>
#include <stdlib.h>
int available(int arr[][9],int size,int row,int col)
{
    if (arr[row][col]==0)
        return 1;
    return 0;

}
int checked(int sod[][9],int size,int row,int col,int n)
{

    int i,j;
    for(j=0; j<9; j++)
    {
        if(sod[row][j]==n)
            return 0;
    }
    for(i=0; i<size; i++)
    {
        if(sod[i][col]==n)
            return 0;
    }
    for(i=row-(row%3); i<(row-(row%3)+3); i++)
    {
        for(j=col-(col%3); j<(col-(col%3)+3); j++)
        {
            if(sod[i][j]==n)
                return 0;
        }
    }




    return 1;
}
int finished(int sod[][9],int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {

        for(j=0; j<9; j++)
        {
            if (sod[i][j]==0)
                return 0;
        }
    }
    return 1;
}


int solve(int sod[][9],int size)
{
    int i,j,n,arr[9][9],x,y;
    for(x=0; x<size; x++)
    {
        for(y=0; y<9; y++)
            arr[x][y]=sod[x][y];
    }
    while(!(finished(sod,size)))
    {
        printf("enter the row and the column\n");
        scanf("%d%d",&i,&j);

        if(available(arr,size,i,j))
        {

            printf("enter row %d   col %d\n",i,j);
            scanf("%d",&n);
            while(n<1 ||n>9 )
            {
                printf("please enter a valid number\n");
                scanf("%d",&n);
            }

            if(checked(sod,size,i,j,n))
                sod[i][j]=n;
else
            {
                printf("wrong\n try again ");
            }
        }
            else
            {
                printf(" this number cannot be changed\n enter row   and col  again\n");
                scanf("%d %d",&i,&j);

            }





            if(finished(sod,size))
                return 1;
        }

        return 0;

    }


    void print_array2d(int arr[9][9],int r,int c)
    {
        int i,j;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                printf("%d ",arr[i][j]);
            printf("\n");
        }
    }

    int main()
    {
        int sod[9][9]= {{1,0,0,4,8,9,0,0,6},{7,3,0,0,0,0,0,4,0},{0,0,0,0,0,1,2,9,5},{0,0,7,1,2,0,6,0,0},{5,0,0,7,0,3,0,0,8},{0,0,6,0,9,5,7,0,0},{9,1,4,6,0,0,0,0,0},{0,2,0,0,0,0,0,3,7},{8,0,0,5,1,2,0,0,4}};
        print_array2d(sod,9,9);

        if(solve(sod,9))
            print_array2d(sod,9,9);
        else
            printf("error\n");

        return 0;
    }

