/*------------------------------------baisc.c�ļ���ŵ��Ǹ��ֺ���------------------------------------*/ 

#include<stdlib.h>
#include"insert_search.h"





 
/****��Ԫ�ز�������****/ 
void insertWord(struct node *trieTree, char *word, int index)

{

    struct node *traverse = trieTree;

	while (*word != '\0')								//û���ﵥ�ʽ�β�����ѭ�� 
	{
	
			if (traverse->children[*word+255] == NULL)
			{ 

                traverse->children[*word+255] = (struct node *)calloc(1, sizeof(struct node));

            }
            
            traverse = traverse->children[*word+255];
			++word;										//����ƶ�һλ
	
	}
	traverse->occurrences=index;
}


/****����Ԫ��****/ 
void searchWord(struct node *treeNode, char *word,FILE*fpw)

{
	char *tem_word=word;

    while (1)								//�����ҵ���null������ѭ�� 

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
	 if (*word == '\0'&&treeNode->occurrences!= 0 )			//�����ʱwordҲ��ͷ�˾�֤���ҵ��� 

    {

        printf("Word found\n");
        fputs(tem_word,fpw);
        fputs("yes\n",fpw);
        


    }

    else							//�������û�ҵ� 

    {

        printf("Word not found\n");
         fputs(tem_word,fpw);
        fputs("no\n",fpw);

	}

}

/****�ͷ��ڴ�ĺ���****/ 
void release(struct node * now)
{
	int i;
	
	if (now == NULL) 					//�ж�Ϊ�շ��أ��Ǻ�ϰ�ߡ�
	{
		
		return;
	}
	for(i=0;i<ALPHABETS;i++)			//���õݹ��㷨�����ͷ��ڴ���� 
		if(now->children[i])
		{
			release(now->children[i]);
		}
		
	free(now);
} 
