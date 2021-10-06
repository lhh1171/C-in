#include <stdio.h>
#include "stdlib.h"
#define MAX 41

int main() {
    FILE *fp;
    char words[MAX];
    if ((fp=fopen("wordy","a+"))==NULL){
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    /*scanf("%[0-2]", name);				//等价于下一句
        fscanf(stdin, "%[0-2]", name);		//等价于上一句*/
    /*从一个流中执行格式化输入,fscanf遇到空格和换行时结束*/
    while ((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))
        fprintf(fp,"%s\n",words);
    /*fopen(file , "r") ; 读方式打开，写会报错！
    fopen(file , "w") ; 写方式打开，整个文件会被直接重新写，以前文件的数据全丢失。
    fopen( file , "a" ); 追加方式打开，写入数据时，是追加到文件尾，不会影响原文件中的数据
    fopen( file ,"r+");
    "r+" "a+" "w+" 等方式打开为读写模式，这时，写数据前，要先定位文件指针，
     如果想改动文件中的内容，则写入的数据长度与要覆盖的数据长度要一致才可以，不然会造成数据覆盖或数据完整性错误！*/
    puts("File contents:");
    rewind(fp);

    while (fscanf(fp,"%s",words)==1){
        puts(words);
    }
    puts("Done!");
    if (fclose(fp)!=0){
        fprintf(stderr,"Error closing file\n");
    }
    return 0;
}
/*	//将文件中的信息读取出来并且存储到temp中
	fscanf(fp, "%d\t%s\t%s\n", &temp.id, temp.name, temp.address);
 */
