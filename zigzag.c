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
