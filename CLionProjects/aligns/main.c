#include <stdio.h>

int main() {
    double dx;
    char ca;
    char cx;
    double dz;
    double cb;
    char _Alignas(double) cz;
    printf("char alignment:   %zd\n",_Alignof(char));
    printf("double alignment: %zd\n",_Alignof(double ));
    /*在我们的系统中，double的对齐值是8，在16进制数只有8和0可以被整除，char是1可以为任意值*/
    printf("&dx: %p\n",&dx);
    printf("&ca: %p\n",&ca);
    printf("&cx: %p\n",&cx);
    printf("&dz: %p\n",&dz);
    printf("&cb: %p\n",&cb);
    printf("&cz: %p\n",&cz);
    return 0;
}
