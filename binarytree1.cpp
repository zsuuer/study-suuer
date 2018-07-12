#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_num 8
int dispt[max_num][max_num]={0};
int disx=0;
typedef struct node{
	int value;
	struct node *left;
	struct node *right;
		
}nd;
nd *int_root(int root_num)
{
	nd *root;
	root=(nd*)malloc(sizeof(nd));
	root->value=root_num;
	dispt[0][0]=root_num;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void insert_nd(nd *p,int num)
{
	
	nd *temp;
	temp=(nd*)malloc(sizeof(nd));
	temp->value=num;
	temp->left=NULL;
	temp->right=NULL;
	while(temp!=p->left&&temp!=p->right)
	{
		while(num<=p->value)
		{
			if(p->left==NULL)
			{
				p->left=temp;
				return;
			}
			else
			{
				p=p->left;
				
			}
		}
		while(num>p->value)
		{
			if(p->right==NULL)
			{
				p->right=temp;				
				
				return;
			}
			else
			{
				p=p->right;	
			
			}
		}
	
	}
	
	
} 
void print_s(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t");
	}
}
void print_nd1(nd *p)
{
	if(p==NULL)
	{
		disx--;
		return;
	}
	disx++;
	int y=0;
	print_nd1(p->left);
	disx++;
	print_nd1(p->right);
	while(dispt[disx][y]!=0)
	{
		y++;
	}
	dispt[disx][y]=p->value;
	disx--;
	
}
void print_nd(nd *p,int level)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		 
		print_nd(p->left,level+1);
		print_s(level);
		printf("%d\n",p->value);
		print_nd(p->right,level+1);

	}
}
void recyle(nd *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		recyle(p->left);
		recyle(p->right);
		free(p);
	} 
}
int main()
{
	nd *int_root(int root_num);
	void print_nd(nd *p,int level);
	void print_nd1(nd *p);
	void recyle(nd *p);	
	void print_s(int n);
	void insert_nd(nd *p,int num);
	int num,i=0;
	nd *root;
	int x,y;
	srand((unsigned int)time(NULL));
	for(i=0;i<=max_num;i++)
	{
		num=rand()%30;
		if(i==0)
		{
			root=int_root(num);	
		}
		else
		{
			insert_nd(root,num);	
		}	
	}
	print_nd(root,0);
	print_nd1(root);
	dispt[0][1]=0;
	for(x=0;x<max_num;x++)
	{
		for(y=0;y<max_num;y++)
		{
			if(dispt[x][y]!=0)
			printf("%d\t",dispt[x][y]);
		}
		printf("\n");
	}
	recyle(root);	
} 
