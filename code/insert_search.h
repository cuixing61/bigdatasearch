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


//int IsGB(char *pText);												//判断字符类型的函数（汉字，英文字母，半角字符等 ,返回值表类型 
void insertWord(struct node *trieTree, char *word, int index);		//插入的函数 
void searchWord(struct node *treeNode, char *word,FILE*fpw);		//搜索的函数 
void release(struct node * now);										//释放内存的函数 

#endif
