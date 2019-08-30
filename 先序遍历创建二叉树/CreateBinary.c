#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>


typedef int element;
typedef struct Tree{
        struct Tree *lchild,*rchild;
        char data;
}*pTree,pNode;

//char str[]="ABD#E##FG###CI##H##";
char str[]="ABDH#K###E##CFI###G#J##";
element index=0;
//Init a empty tree
element Init_tree(pTree *T)
        {
           *T=NULL;
           printf("init a empty tree\n");
        }

//build a tree
void Creat_tree(pNode **T)
        {
           char num;
           num=str[index++];
           pTree P=NULL;
           //P=*T;
           if(num=='#')
                *T=NULL;
           else
             {
              // if(!(*T))
                // exit(OVERFLOW);
               (*T)=(pTree)malloc(sizeof(pNode));
               //memset(*T,0,sizeof(pNode));
               (*T)->data=num;
               Creat_tree(&(*T)->lchild);
               Creat_tree(&(*T)->rchild);
             }
        }

//pro order traversal
element Pro_trav(pTree T)
        {
           if(T==NULL)
                return ;
           printf("pro order traversal data:%c\n",T->data);
           Pro_trav(T->lchild);
           Pro_trav(T->rchild);
        }

//midle order traversal
element Mid_trav(pTree T)
        {
           if(T==NULL)
                return;
           Mid_trav(T->lchild);
           printf("mid order traversal data:%c\n",T->data);
           Mid_trav(T->rchild);
        }

//after traversal
element Aft_trav(pTree T)
        {
           if(T==NULL)
                return;
           Aft_trav(T->lchild);
           Aft_trav(T->rchild);
           printf("after order traversal data:%c\n",T->data);
        }

element main()
        {
           pTree T;
           T=(pTree)malloc(sizeof(struct Tree));
           //Init_tree(&T);
           printf("before is ok\n");
           Creat_tree(&T);
           Pro_trav(T);
           Mid_trav(T);
           Aft_trav(T);
           return 0;
        }