#include<stdio.h>
#include<stdlib.h>
#define p_num 8
#define p_k 6
int count=0;
int main()
{
	int begin_k=0;
	int a[p_num]={0};
	int flag=1,i,ii,k=0;
	printf("start\ninput the begin_k\n"); 
	scanf("%d",&begin_k);
	i=begin_k;
	do
	{
	
		if(i<p_num)
		{ 
			if(!a[i])
			{
				k++;
				if(k==p_k)
				{	
					a[i]=1;
					count++;
					k=0;
					printf("the no.%d,value is %d\n",count,i);
					for(ii=0;ii<p_num;ii++)
					{
						if(!a[ii])
						printf("%d\t",ii);	
					}	
					printf("\n");		
				}
				
			}
			i++;
			
		}
		else
		{
			i=0;	
		} 
		
		
		
	}while(flag);
		
} 
