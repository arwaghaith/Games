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
