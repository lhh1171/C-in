#include <stdio.h>
#define SQUARE(X) X*X
#define PR(x)  printf("the result is %d.\n",x)
/*反斜杠可以可以让宏定义换行*/
#define XXX  "jjjjjjjjjjjjjjjjj\
zzzzzz"
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
    return 0;
}