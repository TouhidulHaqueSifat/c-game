#include<stdio.h>
#include<stdbool.h>
int iswin(int arr[][4],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(arr[i][1]==arr[i][2]&&arr[i][2]==arr[i][3]&&arr[i][1]!=-1)
            return arr[i][1];
    }
    for(int j=1;j<=n;j++)
    {
        if(arr[1][j]==arr[2][j]&&arr[2][j]==arr[3][j]&&arr[1][j]!=-1)
            return arr[1][j];
    }
    if(arr[1][1]==arr[2][2]&&arr[2][2]==arr[3][3]&&arr[1][1]!=-1)
    {
        return arr[1][1];
    }
    if(arr[3][1]==arr[2][2]&&arr[2][2]==arr[1][3]&&arr[3][1]!=-1)
    {
        return arr[3][1];
    }
    return -1;
}
void printcell(int arr[][4],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++ )
        {
            if(arr[i][j]==-1)
            {
                printf(" ");

            }
            if(arr[i][j]==1)
            {
                printf("X");
            }
            if(arr[i][j]==2)
            {
                printf("O");
            }
            if(j<n) printf("\t|\t");
        }

        printf("\n");
        if(i<3) printf("-------------------------------------");

        printf("\n");


    }
}
int main()
{
    int n=3,i,j;
    int arr[4][4];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++ )
        {
            arr[i][j]=-1;

        }
    }
    bool player1=true;
    bool player2=false;
    while(true)
    {
        printcell(arr,n);
        if(player1==true)
        {

            int r,c;
            Flag1:
            printf("Player 1 turn (X),Enter Row and Column : ");
            scanf("%d %d",&r,&c);
            if(arr[r][c]!=-1)
            {
                printf("Invalid!!  Enter Again Row and Column \n");
                goto Flag1;
            }
            arr[r][c]=1;
            player1=false;
            player2=true;
        }
        else
        {
            int r,c;
            Flag2:
            printf("Player 2 turn (O),Enter Row and column : ");
            scanf("%d %d",&r,&c);
            if(arr[r][c]!=-1)
            {
                printf("Invalid!! Enter Again Row and Column\n");
                goto Flag2;
            }
            arr[r][c]=2;
            player2=false;
            player1=true;
        }
        if(iswin(arr,n)==1)
        {
            printf("Player 1 won!!\n");
            printcell(arr,n);
            break;
        }
        else if(iswin(arr,n)==2)
        {

            printcell(arr,n);
            printf("player 2 won!!\n\n");
            break;
        }
        /*else if(iswin(arr,n)==-1)
        {
            printf("Match draw!!");
            printcell(arr,n);
            break;
        }*/
    }


    return 0;

}
