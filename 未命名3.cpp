#include<stdio.h>
#include<stdlib.h> 
#define maxsize 7
static int lb_lenth=0;
typedef struct lnode	//��������Ľڵ� 
{
	 char data;
	 struct lnode *next;
}lb;
void insert_lb(lb *root,char data)	//ʵ������ڵ�Ĳ��� 
{
	lb *temp,*temp1;
	temp=(lb*)malloc(sizeof(lb));
	temp->next=NULL;
	temp->data=data;
	temp1=root;
	if (temp1->next==NULL)
	{
		temp1->next=temp;
		lb_lenth++;
		return;
	}
	else
	{
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;	
			}
			temp1->next=temp;
			lb_lenth=lb_lenth+1;
			return;	
		
	}
}
void display_lb(lb *root) //��ӡ�����������ͷ��ʼ����β 
{
	int i;
	lb *temp=root;
	for (i=1;i<=lb_lenth;i++)
	{
		printf("this the no.%d:%c\n",i,temp->data);
		temp=temp->next;
	}
}
char search_num(lb *root,int i)	//����i��ֵ������Ӧ����1����ֵ 
{
	char return_char;
	int j;
	lb *temp;
	temp=root;
	if(i==1)
	{
		return temp->data;
	}
	else
	{
		for(j=1;j<i;j++)
		{
			temp=temp->next;			
		}
		return temp->data;
	}		
}
void change(lb *root,lb *root1,int i)	//������1�Ľ�����򸳸�����2�������µ����� 
{
	int j;
	lb *temp=root;
	lb *temp1=root1;
	lb *temp2[i-1];
	for(j=0;j<i-1;j++)
	{
		temp2[j]=(lb*)malloc(sizeof(lb));
		temp2[j]->next=NULL;
	}
	for (j=i;j>=1;j--)
	{
			temp1->data=search_num(temp,j);
			if(j==1)
			{
				return;
			}
			else
			{
			
			temp1->next=temp2[j-2];
			temp1=temp1->next;
			}
	}
}
int main()		//������ 
{
	int max_i;
	void insert_lb(lb *root,char data);
	void display_lb(lb *root); 
	void change(lb *root,lb *root1,int i);
	char search_num(lb *root,int i);
	lb *root;	//����������������1������2 
	lb *root1;
	root1=(lb*)malloc(sizeof(lb));
	root=(lb*)malloc(sizeof(lb));
	root1->next=NULL;
	root->next=NULL;
	int i=1;
	char input_num;
	while(i<=maxsize)	//������1���г�ʼ�� 
	{
		printf("please input insert char ;");
		scanf("%c",&input_num);
		setbuf(stdin, NULL);
		if (i==1)
		{
			root->data=input_num;
			lb_lenth++;
		}
		else
		{
		
			insert_lb(root,input_num);
		
		}	
		printf("lb_lenth:%d\n",lb_lenth);
		i++;
	}
	display_lb(root);
	change(root,root1,maxsize);
	printf("this is after change\n");
	display_lb(root1);
}

