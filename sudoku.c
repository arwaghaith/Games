//task 1

#include <stdio.h>
#include <stdlib.h>


int find(int arr[][100],int row,int col)
{
    int i,j,res,s1=0,s2=0;
    for(i=0; i<row; i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&arr[i][j]);

    }
    for(i=0; i<row; i++)
    {
        s1=s1+arr[i][i];
    }
    for(i=0,j=col-1; i<row; i++,j--)
    {
        s2=s2+arr[j][i];
    }
    res=s1-s2;

    return res;

}
   void print_zigzag(int arr[][100],int row,int col)
   {
       int i,j;
       for(i=0;i<row;i++)
       {

       if(i%2==0)
       {
           for(j=0;j<col;j++)
            printf("%d ",arr[i][j]);
           printf("\n");
       }
       else
       {
           for(j=col-1;j>=0;j--)
            printf("%d ",arr[i][j]);
           printf("\n");
       }

       }
   }


int main()
{
    int arr[100][100],r;
    int row,col;
    scanf("%d %d",&row,&col);
    while(row!=col)
    {
    printf("enter the number of rows and columns again\n");
    scanf("%d %d",&row,&col);
    }
    r=find(arr,row,col);
    if(r)
        printf("the sum of the two diagonals are not equal\n");
    else
    printf("the sum of the two diagonals are equal\n");
    print_zigzag(arr,row,col);

    return 0;

}

//task2
#include <stdio.h>
#include <stdlib.h>


void scan_arr(int arr[][5],int size)
{
    int i,j,x=4,y=3;
    arr[x][y]='*';
    for(i=0; i<size; i++)
    {
        if(i<x)
        {
            for(j=0; j<size; j++)
            {
                if(j<y)
                    arr[i][j]='x';
                              else if(j==y)
                                  arr[i][j]='d';
                    else
                        arr[i][j]='y';
            }
        }
        else if(i==x)
        {
            for(j=0; j<size; j++)
            {
                if(j<y)
                    arr[i][j]='r';
                if(j>y)
                    arr[i][j]='l';

            }

        }
        else
        {
            for(j=0; j<size; j++)
            {
                if(j<y)
                    arr[i][j]='z';
                              else if(j==y)
                                  arr[i][j]='u';
                    else
                        arr[i][j]='f';
            }
        }

    }

}
print_arr(int arr[][5],int size)
{
    int x,y;
    for(x=0;x<size;x++)
    {

        for(y=0;y<5;y++)
            printf("%c ",arr[x][y]);
        printf("\n");
    }

}
void find_star(int arr[][5],int size,int*x,int*y)
{
    int middle1=(size-1)/2,middle2=(5-1)/2,flag=0,i_f=0,i_l=size-1,j_f=0,j_l=5-1;
    while(flag<1)
    {


    if(arr[middle1][middle2]=='*')
    {
        flag=1;
        *x=middle1;
        *y=middle2;
    }
    else if (arr[middle1][middle2]=='y')
    {
        i_f=middle1+1;
        j_l=middle2-1;
        middle1=(i_f+i_l)/2;
        middle2=(j_f+j_l)/2;

    }
    else if (arr[middle1][middle2]=='x')
    {
        i_f=middle1+1;
        j_f=middle2+1;
middle1=(i_f+i_l)/2;
        middle2=(j_f+j_l)/2;
    }
     else if (arr[middle1][middle2]=='z')
    {
        i_l=middle1-1;
        j_f=middle2+1;
                middle1=(i_f+i_l)/2;
        middle2=(j_f+j_l)/2;

    }
    else if (arr[middle1][middle2]=='f')
    {
        i_l=middle1-1;
        j_l=middle2-1;
        middle1=(i_f+i_l)/2;
        middle2=(j_f+j_l)/2;


    }
    else if (arr[middle1][middle2]=='r')
    {

        j_f=middle2+1;
        middle2=(j_f+j_l)/2;


    }
    else if (arr[middle1][middle2]=='l')
    {

        j_l=middle2-1;
        middle2=(j_f+j_l)/2;

    }
    else if (arr[middle1][middle2]=='d')
    {

       i_f=middle1+1;
middle1=(i_f+i_l)/2;


    }
    else if (arr[middle1][middle2]=='u')
    {

       i_l=middle1-1;
middle1=(i_f+i_l)/2;


    }
    }

}

int main()
{
    int x=0,y=0;
    int arr[5][5];
    scan_arr(arr,5);
    print_arr(arr,5);
    find_star(arr,5,&x,&y);
    printf("the array is found in row %d column %d\n",x,y);

    return 0;
}
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

