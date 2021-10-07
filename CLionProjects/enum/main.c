#include <stdio.h>
#include "string.h"
#include "stdbool.h"  //c99新特性
char  * s_gets(char * st,int n);
enum spectrum{red,orange,yellow,green,blue,violet};
const char * colors[]={"red","orange","yellow","green","blue","violet"};
#define LEN 30


int main() {
    char choice[LEN];
    enum spectrum color;
    bool color_is_found=false;

    puts("Enter a color {empty line to quit}:");
    while (s_gets(choice,LEN)!=NULL&&choice[0]!='\0'){
        for (color = red; color <=violet ; ++color) {
            printf("%s\n",choice);
            printf("%s\n",colors[color]);
            /*如果返回值 < 0，则表示 str1 小于 str2。
            如果返回值 > 0，则表示 str2 小于 str1。
            如果返回值 = 0，则表示 str1 等于 str2。*/
            if (strcmp(choice,colors[color])==0){
                color_is_found=true;
                break;
            }
        }
        if (color_is_found){
            switch (color) {
                case red: puts("Roses are red!");break;
                case orange:puts("Poppies are orange");break;
                case yellow:puts("Sunflowers are yellow");break;
                case green:puts("Grass are green");break;
                case blue:puts("Bluebells are blue");break;
                case violet:puts("Violets are violet");break;
            }
        } else{
            printf("I don't know about the color %s .\n",choice);
        }
        color_is_found=false;
        puts("Next color,please(empty line to quit):");
    }
    puts("Goodbye");
    return 0;
}

char  * s_gets(char * st,int n){
    char * ret_val;
    char * find;
    ret_val=fgets(st,n,stdin);
    if (ret_val){
        find=strchr(st,'\n');//查找换行符
        if (find){
            *find='\0';//将'\n'换成‘\0’
        } else{
            while (getchar()!='\n')continue; //
        }
    }
    return ret_val;
}