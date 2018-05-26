#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	char buffer[1024*1024];		//创建缓冲区；
	char one_buffer[1]; 
	int last_f=0; 			//定义文件能够分割成1m的最后的字节位置；	 
	int last_s;				//如果文件剩余大小不足1M，则算出具体剩余多少字节；
	char *a[6]={"e:\\cxtest\\testtfboy(1).mp3","e:\\cxtest\\testtfboy(2).mp3","e:\\cxtest\\testtfboy(3).mp3",	
				"e:\\cxtest\\testtfboy(4).mp3","e:\\cxtest\\testtfboy(5).mp3","e:\\cxtest\\testtfboy(6).mp3"}; //定义分割的文件名 
	FILE *f=fopen("e:\\tfboy.mp3","rb");	//打开分割文件的数据流 
   	printf("begin spilt the file tfboy.mp3");
   	printf("sizeof char%d\n",sizeof(buffer));
	if(ferror(f))		//如果打开失败，报错； 
   	{
   		printf("can not open the file tfboy.mp3 successful");		
	}
	else 
	{
		for (i=0;i<6;i++)
		{
			FILE *f1=fopen(a[i],"wb");
			if(fread(buffer,sizeof(buffer),1,f)==0)	//如果读取1M字节失败，报错，并计算剩余多少字节，将剩余的部分写入文件； 
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
			else	//如果成功，则读取目标文件1M字节，并将其写入文件；并打印出字节在文件的位置； 
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
	printf("begin zonghe the file tfboy.mp3");	//开始合并文件； 
	fclose(f);
	FILE *f2=fopen("e:\\tfboyzonghe.mp3","wb");	//打开合并后目标文件数据流 
	for (i=0;i<6;i++)
		{
			FILE *f1=fopen(a[i],"rb");
			if (fread(buffer,sizeof(buffer),1,f1)!=0)	//如果成功读取到1M字节，将其写入zonghe文件里； 
			{
				fseek(f1,-(1024*1024),SEEK_CUR);
				fread(buffer,sizeof(buffer),1,f1);
				fwrite(buffer,sizeof(buffer),1,f2);
				fclose(f1);
			}
			else 									//如果不成功，一个字节一个字节写入； 
			{
				fseek(f1,0,SEEK_SET);
				printf("i am here%d\n",ftell(f1)); 
				while(fread(one_buffer,sizeof(one_buffer),1,f1)!=0)
				{
					
					fseek(f1,-1,SEEK_CUR);
					fread(one_buffer,1,1,f1);
					fwrite(one_buffer,1,1,f2);
						
				}
				fclose(f1);		//关闭数据流 
			}
		}
		fclose(f2);		//关闭数据流 
} 

