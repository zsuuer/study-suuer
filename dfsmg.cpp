#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define n 5 
typedef struct mgg
	{

		int data;
		int lj;
	}mg;
mg a[n][n];
int v[n][n]={0};
int fx[4]={1,-1,1,-1};
int count=1;
int main()
{
	int i,j;
	int temp[n][n]={{0,0,1,1},{0,0,0,0},{0,1,0,0},{0,0,0,0}};
	void dfs(int x,int y);	
	int judge();
	int clearlj();
	srand((unsigned int)time(NULL));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			//a[i][j].data=rand()%2;			//随机生成迷宫 
			a[i][j].data=temp[i][j];		//可以自己设计迷宫 
			a[i][j].lj=0;
			if(i==(n-1)&&j==(n-1))
			a[n-1][n-1].data=0;
			printf("%d\t",a[i][j].data);
			 
		}
		printf("\n");
	}
	printf("\n");
	if(!a[0][0].data)				//入口，如果有多个函数要改动下，这里直接写两个可以走的方向，应该参照dfs函数中的写法； 
	{
		v[0][0]=1;
		a[0][0].lj=count;
		if(!a[0][1].data)
		{
				
			v[0][1]=1;
			a[0][1].lj=++count;
			dfs(0,1);
			a[0][1].lj=--count;
			v[0][1]=0;
		}
		printf("\n");
		clearlj();		//在这里记得清零； 
		v[0][0]=1;
		a[0][0].lj=count;
		if(!a[1][0].data)
		{
			v[1][0]=1;
			a[1][0].lj=++count;
			dfs(1,0);
			a[1][0].lj=--count;
			v[1][0]=0;
							
		}
		printf("it did not exit");
	}										
	else
	{
		printf("the start is error.");
	}
	
	
} 
int clearlj()
{
	int i,j;
	count=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			v[i][j]=0;
			a[i][j].lj=0;		
		}
	}
}
int judge()
{
	int i,j;
	if(v[n-1][n-1]==1)
	{
		printf("\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d\t",a[i][j].lj);					
			}		
			printf("\n");
		}	
		return 1;
		
		
		
	}	
	
}
void dfs(int x,int y)
{
	int i;
	
	if(judge()==1)
	{
		return;
	}
	
	
	for(i=0;i<4;i++)	//在这里有很多for循环。即遍历所有存在的结点，当到达出口时，会退回上一步，继续新的寻找，因为这一条循环已经做过		
	{
		if(i<=1)
		{
			if(x+fx[i]<n&&x+fx[i]>=0)
			{
				if(!a[x+fx[i]][y].data&&v[x+fx[i]][y]==0)
				{
				
					v[x+fx[i]][y]=1;
					a[x+fx[i]][y].lj=++count;
					dfs(x+fx[i],y);
					a[x+fx[i]][y].lj=0;
					count--; 
					v[x+fx[i]][y]=0;
				}
			}
		}
		if(i>1)
		{
			if(y+fx[i]<n&&y+fx[i]>=0)
			{
				if(!a[x][y+fx[i]].data&&v[x][y+fx[i]]==0)
				{
				
					v[x][y+fx[i]]=1;
					a[x][y+fx[i]].lj=++count;
					dfs(x,y+fx[i]);
					a[x][y+fx[i]].lj=0;
					count--; 
					v[x][y+fx[i]]=0;
				}
			}
		}
		
	}

	
}
 
