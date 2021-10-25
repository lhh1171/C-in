#include <stdio.h>
#include "list.h"
int main() {
    List *h;
    int d,m,p;

    //建表并打印链表
    h=creat_list();
    printf("\n------------------------------------------------\n");
    print(h);
    getchar();

    //插入并打印
    printf("\nEnter the posion and value, which you want insert!\n");
    scanf("%d%d",&m, &p);
    h=insert_node(h,m, p);
    print(h);
    printf("\n------------------------------------------------\n");

    //删除并打印
    printf("Enter the data which you would delete it.\n");
    scanf("%d",&d);
    getchar();
    h=delete_node(h,d);
    print(h);
    printf("\n------------------------------------------------\n");
    getchar();
    return 0;
}
