//
// Created by lqc on 2021/10/25.
//

#include "stdio.h"
#include "stdlib.h"
typedef struct list
{
    int data;
    struct list *next;
}List;

int n;//结点总数

//尾插法建立单链表
List *creat_list()
{
    int x;
    List *h;
    List *p,*r;

    //输入32767，输入结束
    printf("Enter the data, enter 32767 as the end!\n");
    scanf("%d",&x);
    h= NULL;
    n=0;
    while( x != 32767 )
    {
        n=n+1;
        p=(List *) malloc (sizeof(List));
        p->data=x;

        if (h==NULL) h=p;
        else r->next=p;
        r=p;
        scanf("%d",&x);
    }
    p->next=NULL;
    return(h);
}

//线性表的插入,将结点插入第pos个位置
List *insert_node( List *h, int pos, int value )
{
    List *s,*p;
    int i;
    s = h;
    if ( pos <= 0 )
    {
        printf("The position is illegal !\n");
        exit(0);
    }
    else
    {	//新结点
        p = (List *) malloc (sizeof(List));
        p->data = value;
        p->next = NULL;

        //开始插入新结点
        if ( pos > n )  //插入链表的尾部
        {
            while ( s->next )  s = s->next;//找最后一个结点
            s->next = p;

        }
        else
        {
            if ( pos <= 1 )//插入到第一个位置
            {
                p->next = h;
                h = p;
            }
            else
            {
                for ( i = 1; i < pos-1; ++i )//找第 POS-1 个结点
                    s = s->next;
                p->next = s->next;
                s->next = p;
            }
        }
        n++;
    }
    return(h);

}
//删除值为 value 的结点
List *delete_node( List *h, int value )
{
    List *s,*p;
    s = h;

    //找删除结点

    //找到了要删除的结点,删除
    if ( value==s->data){

    }else printf("Can't find the node. Please check the enter!\n");

    return(h);
}

void print(List *h)
{
    List *s = h;
    while (s)
    {
        printf("%d  ",s->data);
        s = s->next;
    }
}
