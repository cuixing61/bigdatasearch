#ifndef _INSERT_SEARCH
#define _INSERT_SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

struct node

{
	
    struct node *children[ALPHABETS];
	
 	int occurrences;
};


//int IsGB(char *pText);												//�ж��ַ����͵ĺ��������֣�Ӣ����ĸ������ַ��� ,����ֵ������ 
void insertWord(struct node *trieTree, char *word, int index);		//����ĺ��� 
void searchWord(struct node *treeNode, char *word,FILE*fpw);		//�����ĺ��� 
void release(struct node * now);										//�ͷ��ڴ�ĺ��� 

#endif
