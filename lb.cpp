#include<stdio.h>
#include<stdlib.h> 
typedef int delem;
static int lb_lenth=1;
typedef struct lnode
{
	 delem data;
	 struct lnode *next;
}lb;
lb *init_lb(delem data)
{
	lb *root;
	root=(lb*)malloc(sizeof(lb));
	root->next=NULL;
	root->data=data;
	
	return root;	
} 

void insert_lb(lb *root,delem data,unsigned int i)
{
	int j=1;
	lb *temp,*temp1;
	temp=(lb*)malloc(sizeof(lb));
	temp->next=NULL;
	temp->data=data;
	temp1=root;
	if (temp1->next==NULL)
	{
		if(i==1)
		{
			temp1->next=temp;
			lb_lenth=lb_lenth+1;
			return ;
		}
		else
		{
			printf("fail to insert\n");
			free(temp);
			return ;
		}
	}
	else
	{
		if(i<=lb_lenth)
		{
		
			while(i<=lb_lenth&&j!=i)
			{
				temp1=temp1->next;
				j++;	
			}
			temp->next=temp1->next;
			temp1->next=temp;
			lb_lenth=lb_lenth+1;	
		}
		else
		{
			printf("fail to insert\n"); 
			free(temp);
			return  ;
		}
	
	}
}
void search_lb(lb *root,int num)
{
	int i=1;
	lb *temp=root;
	while(num!=temp->data&&temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(temp->next==NULL)
	{
		printf("it is not in here\n");
	}
	else
	{
		printf("it is no.%d\n",i);
	}
	
}
void display_lb(lb *root)
{
	int i;
	lb *temp=root;
	for (i=1;i<=lb_lenth;i++)
	{
		printf("this the no.%d:%d\n",i,temp->data);
		temp=temp->next;
	}
}
int main()
{
	int max_i;
	lb *init_lb(delem data);
	void insert_lb(lb *root,delem data,unsigned int i);
	void search_lb(lb *root,int num);
	void display_lb(lb *root);
	lb *root;
	root=init_lb(3);
	int input_num=1;
	unsigned int insert_i=1;	
	while(input_num!=0)
	{
		insert_lb(root,input_num,insert_i);
		printf("lb_lenth:%d\n",lb_lenth);
		printf("please input insert num and insert i;");
		scanf("%d%d",&input_num,&insert_i);
		
	}
	display_lb(root);
	search_lb(root,10);
}

