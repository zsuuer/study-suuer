#include<stdio.h>
#include<stdlib.h>
#define dzlength 100
#define dzinch 10
typedef struct
{
	int *base;
	int *top;
	int length;	
}dz;
int main()
{
	dz *x;
	x=(dz*)malloc(sizeof(dz));
	printf("%d",sizeof(dz));
	void initdz(dz *x);
	
	void pushdz(dz *x,int e);
	void getdz(dz *x);
	void popdz(dz *x); 

	int flag,i=1;
	initdz(x);	
}
void initdz(dz *x)
{
	x->base=(int *)malloc(100*sizeof(int));
	if(!x->base)
	{
		printf("error\n");
	}
	x->top=x->base;
	printf("ok\n");
	x->length=dzlength;		
} 
void pushdz(dz *x,int e)
{
	if((x->top-x->base)>=x->length)
	{
		x->base=(int *)realloc(x->base,(x->length+dzinch)*sizeof(int));
		if(!x->base) printf("error");
		x->top=x->base+x->length;
		x->length=x->length+dzinch;
	}
	*(x->top)++=e;
}
void getdz(dz *x)
{
	int e;
	if(x->top==x->base) printf("error\n");
	e=*(x->top-1);
	printf("%d\n",e);
}
void popdz(dz *x)
{
	int e;
	if(x->top==x->base) printf("error\n");
	e=*--x->top;
	printf("delete %d\n",e);
}
#only a test

