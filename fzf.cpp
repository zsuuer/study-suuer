#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
#define n 18
int a[16];
int main()
{
	srand((unsigned)time(NULL));
	int i,zmax,zmin; 
	int max1(int x,int y);
	int min1(int x,int y);
	void fzf(int i,int j,int *max,int *min);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
		printf("%d\t",a[i]);
	}
	fzf(0,n-1,&zmax,&zmin);
	printf("this is max%d\t",zmax);
	printf("this is min%d\t",zmin);
	
}
int max1(int x,int y)
{
	if(x>=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int min1(int x,int y)
{
	if(x>=y)
	{
		return y;
	}
	else
	{
		return x;
	}
}
void fzf(int i,int j,int *max,int *min)
{
	if(i==j)		//针对奇数数列 
	{
		*max=a[i];
		*min=a[j];
	}
	else if(i==j-1)			//针对偶数数列 
	{
		*max=max1(a[i],a[j]);
		*min=min1(a[i],a[j]);
	}
	else
	{
		int mid,fmax1,fmax2,fmin1,fmin2;	//每次子函数都创建了一个新的地址，地址在递归的过程一直不变； 
		mid=(i+j)/2;
		fzf(i,mid,&fmax1,&fmin1);			 
		fzf(mid+1,j,&fmax2,&fmin2);
		*max=max1(fmax1,fmax2);
		*min=min1(fmin1,fmin2);
		
	}
	
}
//分治法解题的一般步骤：
（1）分解，将要解决的问题划分成若干规模较小的同类问题；
（2）求解，当子问题划分得足够小时，用较简单的方法解决；
（3）合并，按原问题的要求，将子问题的解逐层合并构成原问题的解。注意分治法最后是可合并的。最重要需要满足条件
