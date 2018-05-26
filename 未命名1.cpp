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
	while(flag)		//��ʼ��arcs���󣬼�����ͼ���ڽӾ��� 
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
	for (i=0;i<graphnum;i++)	//��ӡarcs���� 
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
	for(v_start=0;v_start<graphnum;v_start++)	// ����ͼ�е�ÿ���ڵ㣬���ĳ���ڵ㵽�����ڵ�����·���;����ĵ� 
	{
		printf("this is about the v%d\n",v_start);
		d[v_start]=0;
		t[v_start]=1;
		for (i=0;i<graphnum;i++)		//��ʼ��d����������ס���·���ĳ��� 
		{
			if(arcs[v_start][i]||i==v_start)		
			{	
				d[i]=arcs[v_start][i];		
			}
			else
			{
				d[i]=255;
				
			}
			for(j=0;j<graphnum;j++) 	//��ʼ��pracs����������¼���·��
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
		for (i=0;i<graphnum;i++)	//��ӡ���·������ 
		{					
			printf("this the v%d:%d\t",i,d[i]);				
		}
		printf("\nthis is shortest path\n");
		for (i=0;i<graphnum;i++)		//��ӡvx�ڵ㵽�����ڵ����·�������Ľڵ㣬��i��j��Ϊ1������i���ڵ����·���о���j�ڵ� ����֮��û�� 
		 
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
void dijkstra(int a[graphnum][graphnum],int *d,int *t,int p[graphnum][graphnum])//����dijkstra�㷨 
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
