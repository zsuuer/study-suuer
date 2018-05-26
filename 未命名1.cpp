#include<stdio.h>
#include<stdlib.h>
#define graphnum 6
int main()
{
	int i,j,num,v_start,flag=1;
	int d[graphnum]={0};
	int t[graphnum]={0};
	int arcs[graphnum][graphnum]={0};
	int parcs[graphnum][graphnum]={0};
	void dijkstra(int a[graphnum][graphnum],int *d,int *t,int p[graphnum][graphnum]);

	printf("input arch ifo\n");
	while(flag)		//初始化arcs矩阵，即无向图的邻接矩阵 
	{
		scanf("%d%d%d",&i,&j,&num);
		if(i<0||i>=graphnum||j<0||j>=graphnum||num<0)
		{
			printf("illegal input\n");
			flag=0;
		}
		else
		{
			
			arcs[i][j]=num;	
			arcs[j][i]=num;
		} 
		
	}	
	for (i=0;i<graphnum;i++)	//打印arcs矩阵 
	{
		
			for(j=0;j<graphnum;j++) 
			{			
				printf("%d\t",arcs[i][j]);
				if(j==graphnum-1)
				{
					printf("\n");	
				}				
			}
				
	}
	printf("input source v, value must from 0 to %d \n",graphnum-1);
	for(v_start=0;v_start<graphnum;v_start++)	// 遍历图中的每个节点，求出某个节点到其他节点的最短路径和经过的点 
	{
		printf("this is about the v%d\n",v_start);
		d[v_start]=0;
		t[v_start]=1;
		for (i=0;i<graphnum;i++)		//初始化d矩阵，用来记住最短路径的长度 
		{
			if(arcs[v_start][i]||i==v_start)		
			{	
				d[i]=arcs[v_start][i];		
			}
			else
			{
				d[i]=255;
				
			}
			for(j=0;j<graphnum;j++) 	//初始化pracs矩阵用来记录最短路径
			{			
				parcs[i][j]=0;						
			}
			if(d[i]<255)
			{
				parcs[i][v_start]=1;
				parcs[i][i]=1;			 
			}
					
		}
		dijkstra(arcs,d,t,parcs);
		printf("this is shortest path length\n");
		for (i=0;i<graphnum;i++)	//打印最短路径长度 
		{					
			printf("this the v%d:%d\t",i,d[i]);				
		}
		printf("\nthis is shortest path\n");
		for (i=0;i<graphnum;i++)		//打印vx节点到其他节点最短路径经过的节点，第i行j列为1代表到第i个节点最短路径有经过j节点 ，反之则没有 
		 
		{					
			for(j=0;j<graphnum;j++) 	
			{			
				printf("%d\t",parcs[i][j]);
				if(j==graphnum-1)
				{
					printf("\n");	
				}					
			}
							
		}
		for (i=0;i<graphnum;i++)
		{
			t[i]=0;
		}
	}
	
}
void dijkstra(int a[graphnum][graphnum],int *d,int *t,int p[graphnum][graphnum])//利用dijkstra算法 
{
	int i,j,k,h;
	int min=255;
	int min_num;
	for (i=1;i<graphnum;i++)
	{
		min=255;
		for (j=1;j<graphnum;j++) 
		{
		  
			 if(t[j]==0&&d[j]<min)
			 {
			 	min_num=j;
				min=d[j];	
			 }
		}	
		if(min_num>=0&&min_num<graphnum)
		{
		
			t[min_num]=1;
			for(k=0;k<graphnum;k++)
			{
				if(a[min_num][k])
				{
					if((a[min_num][k]+min<d[k])&&t[k]==0)
					{
						d[k]=a[min_num][k]+min;
						for (h=0;h<graphnum;h++)
						{
							p[k][h]=p[min_num][h];
						}
						p[k][k]=1;
					}
				}
			}
		}
	}
}
