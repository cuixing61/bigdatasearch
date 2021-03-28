/*------------------------------------baisc.c文件里放的是各种函数------------------------------------*/ 

#include<stdlib.h>
#include"insert_search.h"





 
/****把元素插入树中****/ 
void insertWord(struct node *trieTree, char *word, int index)

{

    struct node *traverse = trieTree;

	while (*word != '\0')								//没到达单词结尾则进行循环 
	{
	
			if (traverse->children[*word+255] == NULL)
			{ 

                traverse->children[*word+255] = (struct node *)calloc(1, sizeof(struct node));

            }
            
            traverse = traverse->children[*word+255];
			++word;										//向后移动一位
	
	}
	traverse->occurrences=index;
}


/****搜索元素****/ 
void searchWord(struct node *treeNode, char *word,FILE*fpw)

{
	char *tem_word=word;

    while (1)								//树查找到了null就跳出循环 

    {


            if (treeNode->children[*word+255] != NULL)

            {

                treeNode = treeNode->children[*word+255];
				++word;

            }

            else

            {

                break;

            }

      

    }
	 if (*word == '\0'&&treeNode->occurrences!= 0 )			//如果此时word也到头了就证明找到了 

    {

        printf("Word found\n");
        fputs(tem_word,fpw);
        fputs("yes\n",fpw);
        


    }

    else							//否则就是没找到 

    {

        printf("Word not found\n");
         fputs(tem_word,fpw);
        fputs("no\n",fpw);

	}

}

/****释放内存的函数****/ 
void release(struct node * now)
{
	int i;
	
	if (now == NULL) 					//判断为空返回，是好习惯。
	{
		
		return;
	}
	for(i=0;i<ALPHABETS;i++)			//利用递归算法进行释放内存操作 
		if(now->children[i])
		{
			release(now->children[i]);
		}
		
	free(now);
} 
