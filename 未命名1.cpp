#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	char buffer[1024*1024];		//������������
	char one_buffer[1]; 
	int last_f=0; 			//�����ļ��ܹ��ָ��1m�������ֽ�λ�ã�	 
	int last_s;				//����ļ�ʣ���С����1M�����������ʣ������ֽڣ�
	char *a[6]={"e:\\cxtest\\testtfboy(1).mp3","e:\\cxtest\\testtfboy(2).mp3","e:\\cxtest\\testtfboy(3).mp3",	
				"e:\\cxtest\\testtfboy(4).mp3","e:\\cxtest\\testtfboy(5).mp3","e:\\cxtest\\testtfboy(6).mp3"}; //����ָ���ļ��� 
	FILE *f=fopen("e:\\tfboy.mp3","rb");	//�򿪷ָ��ļ��������� 
   	printf("begin spilt the file tfboy.mp3");
   	printf("sizeof char%d\n",sizeof(buffer));
	if(ferror(f))		//�����ʧ�ܣ����� 
   	{
   		printf("can not open the file tfboy.mp3 successful");		
	}
	else 
	{
		for (i=0;i<6;i++)
		{
			FILE *f1=fopen(a[i],"wb");
			if(fread(buffer,sizeof(buffer),1,f)==0)	//�����ȡ1M�ֽ�ʧ�ܣ�����������ʣ������ֽڣ���ʣ��Ĳ���д���ļ��� 
   			{
   				printf("can not create the file tfboy.mp3 successful\n");
				printf("i am here %d\n",ftell(f));
				printf("i am here %d\n",last_f);
				fseek(f,last_f,SEEK_SET);
				printf("i am here %d\n",ftell(f));
				printf("last_s %d\n",last_f);
				while(fread(one_buffer,sizeof(one_buffer),1,f)!=0)
				{
					fseek(f,-1,SEEK_CUR);	
					fread(one_buffer,sizeof(one_buffer),1,f);
					fwrite(one_buffer,sizeof(one_buffer),1,f1);
					
				}	
				fclose(f1);
				printf("i am here %d\n",ftell(f));
			}		
			else	//����ɹ������ȡĿ���ļ�1M�ֽڣ�������д���ļ�������ӡ���ֽ����ļ���λ�ã� 
			{
				fseek(f,-(1024*1024),SEEK_CUR);
				fread(buffer,sizeof(buffer),1,f);
				fwrite(buffer,sizeof(buffer),1,f1);
				printf("i am here %d\n",ftell(f));
				fclose(f1);	
				last_f=ftell(f); 
			}
		}
	}
	printf("begin zonghe the file tfboy.mp3");	//��ʼ�ϲ��ļ��� 
	fclose(f);
	FILE *f2=fopen("e:\\tfboyzonghe.mp3","wb");	//�򿪺ϲ���Ŀ���ļ������� 
	for (i=0;i<6;i++)
		{
			FILE *f1=fopen(a[i],"rb");
			if (fread(buffer,sizeof(buffer),1,f1)!=0)	//����ɹ���ȡ��1M�ֽڣ�����д��zonghe�ļ�� 
			{
				fseek(f1,-(1024*1024),SEEK_CUR);
				fread(buffer,sizeof(buffer),1,f1);
				fwrite(buffer,sizeof(buffer),1,f2);
				fclose(f1);
			}
			else 									//������ɹ���һ���ֽ�һ���ֽ�д�룻 
			{
				fseek(f1,0,SEEK_SET);
				printf("i am here%d\n",ftell(f1)); 
				while(fread(one_buffer,sizeof(one_buffer),1,f1)!=0)
				{
					
					fseek(f1,-1,SEEK_CUR);
					fread(one_buffer,1,1,f1);
					fwrite(one_buffer,1,1,f2);
						
				}
				fclose(f1);		//�ر������� 
			}
		}
		fclose(f2);		//�ر������� 
} 

