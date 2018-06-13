#include<stdio.h>
int count=0;
int main()
{
	printf("result hanio");
	void hanio(int n,char x,char y,char z);
	void move(char x,int n,char z);
	char x='x',y='y',z='z';
	int n;
	printf("input how big hanio i");
	scanf("%d",&n);
	hanio(n,x,y,z);
}
void move(char x,int n,char z)
{
	count++;
	printf("the no.%dmove %d from %c to %c\n ",count,n,x,z);
}
void hanio(int n,char x,char y,char z)
{
	if(n==1)
	{
		move(x,1,z);
	}
	else
	{
		hanio(n-1,x,z,y);	//以z为辅助塔，将n以上的圆盘搬到y塔 
		move(x,n,z);	//把x塔最后一个圆盘搬到z塔； 
		hanio(n-1,y,x,z);//把y塔上的n-1个圆盘搬到z塔，以x塔为辅助塔； 
	}
}

