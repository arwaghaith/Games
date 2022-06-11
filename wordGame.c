
//word game
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <strings.h>


static int flag1=0;
int flag3;
char str_arr2[10][10]=
{
    'z',	'y',	'x',	't',	'e',	'n',	'u',	'a',	'u',	'j',
    'n',	'd',	'r',	'e',	'a',	'd',	'o',	'g',	'p',	'w',
    'p',	'a',	'c',	'p',	'n',	'w',	's',	'y',	'v',	'a',
    'z',	'e',	'v',	'a',	'y',	'h',	'n',	'f',	'r',	'u',
    'w',	'r',	'e',	'r',	'r',	'g',	's',	'o',	'c',	'i',
    's',	's',	'k',	'k',	't',	'b',	'o',	'x',	'e',	's',
    'm',	'o',	'u',	's',	'e',	'w',	'b',	'g',	'y',	't',
    'v',	'p',	's',	'j',	'o',	'r',	'm',	'j',	's',	'y',
    'x',	'l',	'o',	'x',	'p',	'r',	'c',	'a',	't',	'o',
    'o',	'w',	'b',	't',	'z',	'j',	't',	'm',	't',	't'
};
typedef struct COORD
{
    int X;
    int Y;
    int size;

};
int Search_And_Get(char*str[],int size,char*selected,int*x,int*y)
{
    COORD pos= {-1,-1};
    if(search_in_lib(str,size,selected))
    {

        flag1++;
        if (search_by_line(&pos,selected))
        {
            *x=pos.X;
            *y=pos.Y;
            flag3=1;
            return 1;

        }

        else  if (search_by_col(&pos,selected))
        {
            *x=pos.X;
            *y=pos.Y;
            flag3=2;
            return 1;
        }

        else if (search_by_diag_down(&pos,selected))
        {
            *x=pos.X;
            *y=pos.Y;
            flag3=3;
            return 1;
        }

        else if(search_by_diag_up(&pos,selected))
        {
            *x=pos.X;
            *y=pos.Y;
            flag3=4;
            return 1;
        }




    }
    return 0;
}
int len_str(char*str)
{
    int i;
    for(i=0; str[i]; i++)
    {
    }
    return i;
}

//is it a correct word
int search_in_lib(char*str[],int size,char*selected)
{
    int flag2;

    for(int i=0; i<size; i++)
    {
        flag2=1;
        for(int j=0; selected[j]||str[i][j]; j++)
        {
            if(str[i][j]!=selected[j])
            {
                flag2=0;


                break;
            }



        }
        if(flag2==1)
            break;

    }

    if(flag2==1)
    {
        return 1;

    }
    else
        return 0;





}
//getting the location
int search_by_line(COORD*pos,char*selected)
{
    int lin_flag;

    int i,j,x=0;
    int c_flag=0;
    for(i=0; i<10; i++)
    {
        lin_flag=1;
        for(j=0; selected[x]&&str_arr2[i][j]&&j<10; j++)
        {
            if(selected[x]==str_arr2[i][j])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    lin_flag=1;

                }
                else
                {

                    x++;

                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                lin_flag=0;
            }



        }



        if(lin_flag==1&&x==len_str(selected))
        {
            pos->X=i;
            pos->Y=j+1-len_str(selected);
            flag3=1;



            return 1;
        }
    }


    return 0;

}
int search_by_col(COORD*pos,char*selected)
{
    int col_flag;

    int i,j,x=0;
    int c_flag=0;
    for(i=0; i<10; i++)
    {
        col_flag=1;
        for(j=0; selected[x]&&str_arr2[j][i]&&j<10; j++)
        {
            if(selected[x]==str_arr2[j][i])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    col_flag=1;

                }
                else
                {

                    x++;

                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                col_flag=0;
            }


        }


        if(col_flag==1&&x==len_str(selected))
        {
            pos->Y=i;
            pos->X=j+1-len_str(selected);

            flag3=2;


            return 1;
        }
    }


    return 0;

}


int search_by_diag_up(COORD*pos,char*selected)
{
    int diag_flag=0;

    int i,j,x=0,l;
    int c_flag=0;
    for(i=9; i>=0; i--)
    {
        diag_flag=1;
        l=i;
        for(j=0; selected[x]&&str_arr2[l][j]&&l>=0; j++,l--)
        {
            if(selected[x]==str_arr2[l][j])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    diag_flag=1;

                }
                else
                {

                    x++;

                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                diag_flag=0;
            }



        }


        if(diag_flag==1&&x==len_str(selected))
        {
            pos->Y=j+1-len_str(selected);
            pos->X=l-1+len_str(selected);

            flag3=3;


            return 1;
        }
    }

    diag_flag=0;

    x=0;
    c_flag=0;

    for(i=0; i<10; i++)
    {
        diag_flag=1;
        l=i;
        for(j=0; selected[x]&&str_arr2[l][j]&&l>=0; j++,l--)
        {
            if(selected[x]==str_arr2[l][j])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    diag_flag=1;
                }
                else
                {

                    x++;

                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                diag_flag=0;
            }



        }

        if(diag_flag==1&&x==len_str(selected))
        {
            pos->Y=j+1-len_str(selected);
            pos->X=l-1+len_str(selected);

            flag3=3;


            return 1;
        }
    }
}
int search_by_diag_down(COORD*pos,char*selected)
{
    int diag_flag=0;

    int i,j,x=0,l,m;
    int c_flag=0;
    for(i=9; i>=0; i--)
    {
        diag_flag=1;
        l=i;
        for(j=0; selected[x]&&str_arr2[l][j]&&l<10; j++,l++)
        {
            if(selected[x]==str_arr2[l][j])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    diag_flag=1;
                }
                else
                {

                    x++;
                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                diag_flag=0;
            }



        }

        if(diag_flag==1&&x==len_str(selected))
        {
            pos->Y=j+1-len_str(selected);
            pos->X=l+1-len_str(selected);

            flag3=4;

            return 1;
        }
    }
    diag_flag=0;

    c_flag=0;

    for(i=0; i<10; i++)
    {
        diag_flag=1;
        l=i;
        for(j=0; selected[x]&&str_arr2[l][j]&&l<10; j++,l++)
        {
            if(selected[x]==str_arr2[l][j])
            {


                if(c_flag==0)
                {
                    c_flag=1;
                    x++;
                    diag_flag=1;
                }
                else
                {

                    x++;

                    if(x==((len_str(selected))))
                        break;
                }
            }
            else
            {
                x=0;
                c_flag=0;
                diag_flag=0;
            }



        }


        if(diag_flag==1&&x==len_str(selected))
        {
            pos->Y=j+1-len_str(selected);
            pos->X=l+1-len_str(selected);

            flag3=4;


            return 1;
        }
    }


    return 0;
}
void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}


void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F)<<4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

void print2d(char str_arr2[][10],int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<10; j++)
            printf("%c ",str_arr2[i][j]);
        printf("\n");
    }
}
void scan_str(char*str)
{
    int i;
    scanf("%c",&str[0]);
    for(i=0; str[i]!='\n'; )
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}

//highlighting
void highlight_line(int x,int y, char*selected)
{
    int a=x;
    int b=y;


    for(int i=0; i<len_str(selected); i++)
    {
        gotoxy(b,a);
        SetColorAndBackground(30,0);
        printf("%c",selected[i]);
        b=b+2;
    }

}

void highlight_col(int x,int y, char*selected)
{
    int a=x;
    int b=y;


    for(int i=0; i<len_str(selected); i++)
    {
        gotoxy(b,a);
        SetColorAndBackground(30,0);
        printf("%c",selected[i]);

        a=a+1;
    }

}
highlight_ddown(int x,int y,char*selected)
{
    int a=x;
    int b=y;


    for(int i=0; i<len_str(selected); i++)
    {
        gotoxy(b,a);
        SetColorAndBackground(30,0);
        printf("%c",selected[i]);

        a=a+1;
        b=b+2;
    }
}
highlight_dup(int x,int y,char*selected)
{
    int a=x;
    int b=y;


    for(int i=0; i<len_str(selected); i++)
    {
        gotoxy(b,a);
        SetColorAndBackground(30,0);
        printf("%c",selected[i]);

        a=a-1;
        b=b+2;
    }

}

int main()
{
    int a=0;

    char*str[]= {"ten","read","dog","boxes","mouse","cat","park","fox","jam","sort","sob","pot","car","sew","pan","sea"};

    int size=(sizeof (str))/sizeof(char*);
    print2d(str_arr2,10);
    int k=0;
    int b=0,c=0;
    char selected[6]= {0};
    char**found=calloc(size,sizeof(char*));
    int x,y;
    gotoxy(45,0);
    printf("score");
     gotoxy(30,20);
    printf("word game");

    while(1)
    {



        gotoxy(0,13);
        printf("enter the word\n");
        gotoxy(0,14);
        printf("                               \n");
        gotoxy(0,14);
        scan_str(selected);
        if (search_in_lib(found, b,selected))
        {
            gotoxy(15,14);
            printf("                          ");
            SetColorAndBackground(20,0);
            gotoxy(15,14);
            printf("entered before\n");
            for(long long x=0; x<1000000000; x++);
            SetColorAndBackground(40,0);

        }
        else if(Search_And_Get(str,size,selected,&x,&y))
        {
            found[b]=calloc(len_str(selected),sizeof(char));
            for( c=0; selected[c]; c++)
            {
                found[b][c]=selected[c];

            }
            if(flag3==1)
                highlight_line(x,y*2,selected);
            else if (flag3==2)
                highlight_col(x,y*2,selected);
            else if (flag3==3)
                highlight_ddown(x,y*2,selected);
            else if (flag3==4)
                highlight_dup(x,y*2,selected);


            found[b][c]=0;
            b++;
            gotoxy(15,14);
            printf("                         ");
            SetColorAndBackground(10,0);
            gotoxy(15,14);
            printf("correct\n");
            for(long long  z=0; z<1000000000; z++);

            SetColorAndBackground(15,0);
            gotoxy(46,1);
            printf("%d/%d",flag1,size);

            gotoxy(58,a);
            SetColorAndBackground(30,0);
            printf("%s\n",selected);
            SetColorAndBackground(40,0);
            a++;
            gotoxy(y*4,x+2);
            SetColorAndBackground(30,0);
            for(long long  z=0; z<1000000000; z++);


        }
        else
        {
            gotoxy(15,14);
            printf("                    ");
            SetColorAndBackground(20,0);
            gotoxy(15,14);
            printf("wrong\n");
            for(long long x=0; x<1000000000; x++);
            SetColorAndBackground(40,0);
        }






        if(flag1==size)
        {

            gotoxy(30,21);
            SetColorAndBackground(10,0);
            printf("congratulations\n");
            break;
        }


    }

    return 0;


}

