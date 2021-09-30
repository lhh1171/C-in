#include <stdio.h>

inline static long quare(int n){
    return n*n;
}
//内联函数有编译系统进行处理，带参宏由预处理系统进行处理
int main()
{
    int n;
    long m;
    printf("please input a number:");
    scanf("%d",&n);
//    std::cout<<"please input a number:";
//    std::cin>>n;//输入
    for (int i = 1; i <=n ; ++i) {
        m=quare(i);
        printf("%d的平方值是:%ld\n",i,m);
    }
//    std::cout<<n<<"的平方值是:"<<m<<std::endl;
    return 0;
}
//gcc不能编译.cpp文件