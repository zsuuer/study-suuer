#include<stdio.h>
#define swap(x,y,t) t=x;x=y;y=t
f(int i,int n,int *a,long *k,long*k1) 
{
	int j,temp;
	int count=0;
	if(i==n)
	{
		for(j=0;j<=n;j++)
		{
			printf("%4d",a[j]);
			if(a[j]==(j+1))
			{
				count++;
			}
			
		}
		(*k)++;
		if(count==0)
		{
			(*k1)++;
		}
		printf("\n");
	}
	else
	{
		for (j=i;j<=n;j++)
		{
		
			swap(a[i],a[j],temp);
			f(i+1,n,a,k,k1);
			swap(a[i],a[j],temp);
		}
	}
}
int main()
{
	int x=5;
	int i;
	long k=0;
	long k1=0;
	int a[100]={1,2,3,4,5};
	int most_count=0;
	f(0,x-1,a,&k,&k1);
	printf("this is possibility  %d/%d\n ",k1,k);
	
}
