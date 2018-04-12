
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,max;
	int n;
	printf("enter the number of charachters in the sequence:");
	scanf("%d",&n);
	int a[n];
	printf("enter the sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*int n=8;
	int a[8]={5,2,8,6,3,6,9,7};*/
	int Lsmemo[n];
	Lsmemo[0]=0;
	int pred[n];
	int j;
	for(i=1;i<n;i++)
	{
		max=0;
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				if((Lsmemo[j]+1)>max)
				{
					max=Lsmemo[j]+1;
					pred[i]=j;
				}
			}
		}
		Lsmemo[i]=max;

	}
	int imax=0;
	for(i=0;i<n;i++)
	{
		if(Lsmemo[i]>imax)
		{
			imax=i;
		}
	}
	printf("the number of elements in the longest subsequence is:")
	printf("%d\n",Lsmemo[imax]+1);
	printf("the longest subsequence:\n");
	int n1=Lsmemo[imax]+1;
	int ls[n1];
	ls[n1-1]=a[imax];
	j=n1-2;
	int k=pred[imax];

	while(j>=0)
	{
		ls[j]=a[k];
		k=pred[k];
		j--;
	}
	for(i=0;i<max+1;i++)
	{
		printf("%d	",ls[i]);
	}

	return 0;
}
