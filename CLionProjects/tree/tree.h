//
// Created by lqc on 2021/11/5.
//
# include <stdio.h>
# include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
}Tree;

/* 按先序遍历的次序生成二叉树 */
Tree *pre_creat_tree(Tree *t)
{
    int d;
    scanf("%d",&d);
    getchar();
    if ( d==0 ) t =NULL;
    else
    {
        t = (Tree *) malloc ( sizeof (Tree) );
        t->data = d;
        t->lchild=pre_creat_tree(t->lchild);
        t->rchild=pre_creat_tree(t->rchild);
    }
    return(t);
}

/* 先序遍历二叉树 */
void pre_traverse(Tree *t)
{
    if ( t )
    {
        printf("%d   ",t->data);
        pre_traverse(t->lchild);
        pre_traverse(t->rchild);
    }
}

//中序遍历
void InOrder_traverse(Tree *t)
{

    if (t){
        InOrder_traverse(t->lchild);
        printf("%d  ",t->data);
        InOrder_traverse(t->rchild);
    }
}

//后序遍历
void PostOrder_traverse(Tree *t)
{
    if ( t )
    {
        PostOrder_traverse(t->lchild);
        PostOrder_traverse(t->rchild);
        printf("%d   ",t->data);
    }
}