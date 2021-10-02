#include <stdio.h>

extern float nextone();
extern float lastone();
int testa=10;
int main() {
    int i,j=testa;
    for (int i = 1; i <6 ; ++i) {
        printf("%f\n",nextone());
        printf("%f\n",lastone());
//        std::cout<<j<<"&"<<i<<std::endl;
//        std::cout<<nextone()<<"&"<<lastone()<<std::endl;
    }
}