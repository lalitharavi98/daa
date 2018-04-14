#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b,int c);
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
	printf("EDIT DISTANCE=%d\n",E[len1][len2]);
	i=len1;j=len2;
	int k=0;
	char change[50];
	while(i>0 || j>0)
	{
		
		if(edge[i][j]==0)
		{
			change[k]='n';
			i=i-1;
			j=j-1;
		}
		else
		{
			int x=min(E[i-1][j],E[i][j-1],E[i-1][j-1]);
			if(x==E[i-1][j])
			{
				change[k]='d';
				
				i=i-1;
				
			}
			else if(x==E[i-1][j-1])
			{
				change[k]='s';
				
				i=i-1;
				j=j-1;
			}
			else
			{
				change[k]='i';
				
				j=j-1;
			
			}

		}
		k++;
	}

	int len=k;

	int m;
	i=0;
	for(i=len-1;i>=0;i--)
	{
		printf("%c  ",change[i]);
	}
	printf("\n");
	i=0;
	for(m=len-1;m>=0;m--)
	{	
		if(change[m]=='n')
		{
			printf("%c  ",str1[i]);
			i++;	
		}
		else if(change[m]=='s')
		{
			printf("%c  ",str1[i]);
			i++;
		}
		else if(change[m]=='i')
		{
			printf("_  ");
		}
		else
		{
			printf("%c  ",str1[i]);
			i++;
		}
		
	}
	printf("\n\n");
	i=0;
	for(m=len-1;m>=0;m--)
	{	
		if(change[m]=='n')
		{
			printf("%c  ",str2[i]);
			i++;	
		}
		else if(change[m]=='s')
		{
			printf("%c  ",str2[i]);
			i++;
		}
		else if(change[m]=='i')
		{
			printf("%c  ",str1[i]);
			i++;
		}
		else
		{
			printf("_  ");
			
		}
		
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
