#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 16
int a[n];
int main()
{
	srand((unsigned)time(NULL));
	int i;
	int kpf(int i,int j);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
		printf("%d\t",a[i]);
	}
	printf("\n");
	kpf(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
 
}
void kpf(int i,int j)
{
		
		int key=a[i];
		int ii=i;
		int jj=j;
		int temp=0;
		while(ii<jj)	
		{
			while(a[jj]>=key&&jj>ii)
			{
				jj--;					
			}
			temp=a[jj];
			a[jj]=a[ii];
			a[ii]=temp;
			while(a[ii]<=key&&ii<jj)
			{
				ii++;
			}
			temp=a[ii];
			a[ii]=a[jj];	// 
			a[jj]=temp;
			
		}
		if(i<j)//注意当ii=j时，可能访问越界。//用此条件筛选 
		{	
			kpf(i,ii-1);
			kpf(ii+1,j);
		}
	
} 
