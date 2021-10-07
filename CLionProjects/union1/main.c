#include <stdio.h>
struct point{
    struct {
        int x;
        int y;
    };
//    union {
//        int x;
//        int y;
//    };
};
int main() {
    struct point pt;
    pt.x=10;
    printf("%d %d\n",pt.x,pt.y);
    pt.y=20;
    printf("%d %d",pt.x,pt.y);
    return 0;
}
