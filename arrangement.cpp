#include<stdio.h>
int main()
{
	int a[100];
	int k=0;
	int m=9;
	int n=4;
	a[0]=n;
	int f1(long int h,int *s);
	int f3(int *sz);
	int f(int m,int n,int *a,int *b);
	f(m,n,a,&k);
}
int f1(long int h,int *s)
{
	int h1=0;
	int h2=0;
	while(h)
	{
		h1=h%10;
		h=h/10;
		if(h1==s[1]||h1==s[2]||h1==s[3]||h1==s[4])
		{
			continue;			
			
		}
		else
		{
			return 0;
		}
		
		
		
		
	}
	return 1;	
	
}
f3(int *sz)
{
	int x,y;
	long int z1,z2;
	for (x=100;x<=777;x++)
	{
		if(f1(x,sz)==1)
		{
			for(y=10;y<=77;y++)
			{
				if(f1(y,sz)==1)
				{
					z1=x*(y/10);
					z2=x*(y%10);
					if(f1(x*y,sz)&&f1(z1,sz)&&f1(z2,sz))
					{
						printf("this is choosed number%4d,%4d,%4d,%4d",sz[1],sz[2],sz[3],sz[4]);
						printf("this is result cs%4d bcs %4d\n",x,y);	
					}			
				}
			}
			
		}
		
		
	}
		
	
}
f(int m,int n,int *a,int *b)
{
	
	int i,j;
	for (i=m;i>=n;i--)
	{
		a[n]=i;
		if(n>1)
		{
			f(i-1,n-1,a,b);
		}
		else
		{
			f3(a);
			for (j=a[0];j>0;j--)
			{
			
			printf("%4d",a[j]);
			
			}
			(*b)++;
			printf("\n");
		}
	} 
}
#test
