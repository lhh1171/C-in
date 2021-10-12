#include <stdio.h>
#define SQUARE(X) X*X
#define PR(x)  printf("the result is %d.\n",x)
/*反斜杠可以可以让宏定义换行*/
#define XXX  "jjjjjjjjjjjjjjjjj\
zzzzzz"
#define XName(n) x##n
#define Print_XN(n) printf("x"#n"=%d\n",x##n)
int main() {
    printf("%s\n",XXX);
    /*c11可以，c99b不可*/
    int x=5;
    int z;
    printf("x=%d\n",x);
    z=SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PR(z);
    z=SQUARE(2);
    printf("Evaluating SQUARE(2):");

    int XName(1)=14;//相当于x1=14
    int XName(2)=20;//相当于x2=20
    int x3=20;
    Print_XN(1); //相当于打印x1
    Print_XN(2);
    Print_XN(3);
    return 0;
}