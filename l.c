#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b,int c);
struct solution
	{
		char change;
		int left;
		int right;
	}soln[50];
int main()
{
	char str1[100];
	char str2[100];
	printf("Enter the first string:");
	scanf("%s",str1);
	printf("enter the second string:");
	scanf("%s",str2);

	int len1=strlen(str1);
	int len2=strlen(str2);
	int E[len1+1][len2+1];
	int i,j;
	int edge[len1+1][len2+1];
	
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			if(i==0)
			{
				E[i][j]=j;
				edge[i][j]=j;
				
			}
			else if(j==0)
			{
				E[i][j]=i;
				edge[i][j]=i;

			}
			else if(str1[i-1]==str2[j-1])
			{
				E[i][j]=E[i-1][j-1];
				edge[i][j]=0;
			}
			else
			{
				E[i][j]=1+min(E[i-1][j],E[i][j-1],E[i-1][j-1]);
				edge[i][j]=1;
			}
		}
	}
	printf("%d",E[len1][len2]);
	i=len1;j=len2;
	int k=0;
	while(i>0 || j>0)
	{
		
		if(edge[i][j]==0)
		{
			soln[k].change='n';
			soln[k].left=i-1;
			soln[k].right=j-1;
			i=i-1;
			j=j-1;
		}
		else
		{
			int x=min(E[i-1][j],E[i][j-1],E[i-1][j-1]);
			if(x==E[i-1][j])
			{
				soln[k].change='d';
				soln[k].left=i-1;
				soln[k].right=j;
				i=i-1;
				
			}
			else if(x==E[i-1][j-1])
			{
				soln[k].change='s';
				soln[k].left=i-1;
				soln[k].right=j-1;
				i=i-1;
				j=j-1;
			}
			else
			{
				soln[k].change='i';
				soln[k].left=i;
				soln[k].right=j-1;
				j=j-1;
			
			}

		}
		k++;
	}
	int len=k;
	printf("\nlength=%d\n",len);
	for(i=len;i>=0;i--)
	{
		printf("%c ",soln[i].change);
	}


	return 0;
}
int min(int a,int b,int c)
{
	if(a>b)
	{
		if(b>c)
			return c;
		else
			return b;
	}
	else if(a<c)
		return a;
	else return c;
}