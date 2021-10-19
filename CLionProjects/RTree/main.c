#include <stdio.h>
#include <stdbool.h>

struct RNOLeafNode{
    char * data;
    int keyTally;
    bool leaf;
    //x,y坐标
    int x;
    int y;
    //from<阶数
    int from[2];

};
struct RLeafNode{
    bool leaf;
    int x;
    int y;

    int from[2];
};

int main() {

    printf("Hello, World!\n");
    return 0;
}
