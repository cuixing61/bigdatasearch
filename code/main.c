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
	char buf[BUF_SIZE];	//��ȡ�ļ����ݻ��� 
	char buf1[BUF_SIZE];
	char* ret;		//�ļ���ȡ����ֵ 
	char* ret1;
	
	SIZE=0;			//Ĭ�ϴ�С0
	fp=NULL;		//�ļ������ʼ��ΪNULL
	fp1=NULL;
	fpw=NULL;		
	
	struct node *trieTree = (struct node *)calloc(1, sizeof(struct node));//����һ���� 
	
	
	/*---------------���ļ�-------------------*/ 
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

	
	/*----��127���ļ��ŵ��ַ����У������ֵ���-----*/ 
	do
	{
		ret=NULL;
		memset(buf,0,BUF_SIZE);			//void *memset(void *s, int ch, size_t n);��buf����bufsize��ֵ��0���沢����bf 
		ret=fgets(buf, BUF_SIZE-1, fp);//char *fgets(char *buf, int bufsize, FILE *stream);
		if(ret==NULL)
		{
			//�ж��Ƿ��ȡ���ļ���β 
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
	memset(buf,0,BUF_SIZE);	//����ʹ����ɺ�Ҫ���� 
	fclose(fp);
	/*-----��98���ļ��ŵ�buf1�ﲢ����ƥ��-----*/
	do
	{
		ret1=NULL;
		memset(buf1,0,BUF_SIZE);			//void *memset(void *s, int ch, size_t n);��buf����bufsize��ֵ��0���沢����bf 
		ret1=fgets(buf1, BUF_SIZE-1, fp1);//char *fgets(char *buf, int bufsize, FILE *stream);
		if(ret1==NULL)
		{
			//�ж��Ƿ��ȡ���ļ���β 
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
    memset(buf1,0,BUF_SIZE);	//����ʹ����ɺ�Ҫ���� 
  
	fclose(fp1);
	fclose(fpw);
	release(trieTree);

 	 return 0;

}
