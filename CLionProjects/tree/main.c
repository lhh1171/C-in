#include <stdio.h>
#include "tree.h"

int main() {
    Tree *t=NULL;
    t=pre_creat_tree(t);

    printf("\n**********先序遍历***********\n");
    pre_traverse(t);

    printf("\n**********中序遍历***********\n");
    InOrder_traverse(t);

    printf("\n**********后序遍历***********\n");
    PostOrder_traverse(t);

    printf("\n*****************************\n");

    printf("\n");
}
