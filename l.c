#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b?a:b)
int main()
{
    /*int D[4][4]={
        {0,5,999,10},
        {999,0,3,999},
        {999,999,0,1},
        {999,999,999,0}
    };*/
    int i,j,n;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    int D[n][n];
    printf("enter the adjacency weight matrix:");
    for(i=0;i<n;i++)
    {
        printf("vertex %d:\n",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&D[i][j]);
        }
    }
    /*int D[6][6]={
        {0,999,999,999,-1,999},
        {1,0,999,2,999,999},
        {999,2,0,999,999,-8},
        {-4,999,999,0,3,999},
        {999,7,999,999,0,999},
        {999,5,10,999,999,0}
    };*/

    /*int D[3][3]={
        {0,5,999},
        {999,0,2},
        {999,999,0} 
    };*/
    int k;
    int x;
    for(k=1;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                x=(D[i][k]+D[k][j]);
                D[i][j]=min(D[i][j],x);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(D[i][j]>900)
            {
                printf("INF     ");
            }
            else
            {    
            printf("%d     ",D[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
