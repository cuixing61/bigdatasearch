#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include"insert_search.h"


int main()

{
	

    int n, i;
    int count; 
	int SIZE;
	
	FILE *fp, *fp1,*fpw;
	char buf[BUF_SIZE];	//读取文件内容缓冲 
	char buf1[BUF_SIZE];
	char* ret;		//文件读取返回值 
	char* ret1;
	
	SIZE=0;			//默认大小0
	fp=NULL;		//文件句柄初始化为NULL
	fp1=NULL;
	fpw=NULL;		
	
	struct node *trieTree = (struct node *)calloc(1, sizeof(struct node));//定义一个树 
	
	
	/*---------------打开文件-------------------*/ 
	if((fp=fopen("C:\\cuixing\\127w.txt", "r")) == NULL)
	{
    	printf("The 127 file can not be opened.\n");
    	return 1; 
	}
	if((fp1=fopen("C:\\cuixing\\98w_gb.txt", "r")) == NULL)
	{
    	printf("The 98 file can not be opened.\n");
    	return 2; 
	}
	if((fpw=fopen("C:\\cuixing\\out.txt", "w")) == NULL)
	{
    	printf("The out file can not be opened.\n");
    	return 3; 
	}
	printf("success open\n");

	
	/*----把127的文件放到字符串中，建立字典树-----*/ 
	do
	{
		ret=NULL;
		memset(buf,0,BUF_SIZE);			//void *memset(void *s, int ch, size_t n);将buf后面bufsize个值用0代替并返回bf 
		ret=fgets(buf, BUF_SIZE-1, fp);//char *fgets(char *buf, int bufsize, FILE *stream);
		if(ret==NULL)
		{
			//判断是否读取到文件结尾 
			if(feof(fp)) printf("finish read the file! read %d lines!\n", SIZE);//int feof(FILE *stream);
			else printf("something error!\n");
			break;
		}
		else
		{
		//	printf("read [%s] from files\n", buf);
			insertWord(trieTree, buf, strlen(buf));
			SIZE++;
		}
		
	} while (1);
	printf("success build\n");
	SIZE=0;
	memset(buf,0,BUF_SIZE);	//缓冲使用完成后要清理 
	fclose(fp);
	/*-----把98的文件放到buf1里并进行匹配-----*/
	do
	{
		ret1=NULL;
		memset(buf1,0,BUF_SIZE);			//void *memset(void *s, int ch, size_t n);将buf后面bufsize个值用0代替并返回bf 
		ret1=fgets(buf1, BUF_SIZE-1, fp1);//char *fgets(char *buf, int bufsize, FILE *stream);
		if(ret1==NULL)
		{
			//判断是否读取到文件结尾 
			if(feof(fp1)) printf("finish read the file! read %d lines!\n", SIZE);//int feof(FILE *stream);
			else printf("something error!\n");
			break;
		}
		else
		{
			printf("[%s]\n", buf1);
			searchWord(trieTree, buf1,fpw);
			SIZE++;
		}
	} while (1); 
    memset(buf1,0,BUF_SIZE);	//缓冲使用完成后要清理 
  
	fclose(fp1);
	fclose(fpw);
	release(trieTree);

 	 return 0;

}
