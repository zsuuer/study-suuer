#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	unsigned int x;
	int y1,y2,y3,y4;
	int flag=1;
	unsigned int i=1;
	printf("input seed");
	scanf("%d",&x);
	srand(x);
	y1=rand()%7;y2=rand()%7;
	y3=y1+y2;
	printf("%d\t%d\t%d\n",y1,y2,y3);
	while(flag)
	{
	
		if(i==1)
		{
			if(y3==7||y3==11)
			{
				printf("win!");
				i++;
				flag=0;
				
			}
			else if(y3==2||y3==3||y3==12)
			{
				printf("lose!")	;
				i++;
				flag=0;
			}
			else
			{
				y4=y3;
				i++;
			}
		}	
		else
		{
			srand(i);
			y1=rand()%7;	y2=rand()%7;
			y3=y1+y2;
			printf("%d\t%d\t%d\t%d\n",y1,y2,y3,y4);
			if(y3==7)
			{
				printf("lose!")	;
				flag=0;	
			}
			else if(y3==y4)
			{
				printf("win!");
				flag=0;	
			}
			else
			{
				y4=y3;
				i++;
			}
		}
			
	}
	printf("%d",i);
}
	


 
