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
		hanio(n-1,x,z,y);	//��zΪ����������n���ϵ�Բ�̰ᵽy�� 
		move(x,n,z);	//��x�����һ��Բ�̰ᵽz���� 
		hanio(n-1,y,x,z);//��y���ϵ�n-1��Բ�̰ᵽz������x��Ϊ�������� 
	}
}

