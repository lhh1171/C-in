#include <stdio.h>
#include "stdlib.h"
#define CNTL_z '\032' /*DOS文件文本的文件结尾标记*/
#define SLEN 81
int main() {
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s",file);
    if ((fp=fopen(file,"rb"))==NULL){
        printf("reverse can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    /*第一个参数：file指针，指向文件，fopen应该已经打开文件
     * 第二个参数：ofset偏移量，正（前移），负（后移），0（不动）
     * 第三个参数是模式：文件开始，当前，末尾*/
    fseek(fp,0L,SEEK_END);//把当前文件设置为句文件末尾0字节偏移量，把当前位置设置在文件末尾
    last=ftell(fp);//返回当前位置
    for ( count = 1L; count <=last ; ++count) {
        fseek(fp,-count,SEEK_END);
        /*在文件处理中，通过getc()函数，我们从输入文件流中获取下一个字符，并递增文件位置指针*/
        ch=getc(fp);
        if (ch!=CNTL_z&&ch!='\r')/*MS-DOs文件*/
            putchar(ch);/*通过putchar获取指定数字的图形：
            比如putchar(97);会输出英语字母a，标明ASCII码97对应小写字母a 。*/
    }
    //倒着读
    putchar('\n');
    fclose(fp);
    return 0;
}
