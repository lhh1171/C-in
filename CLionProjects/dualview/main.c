#include <stdio.h>
#include "stdbool.h"
#include "limits.h"
//位字符符号常量
//边框线样式
#define SOLLD  0
#define DOTTED 1
#define DASHED 2

//三原色
#define BLUE   4
#define GREEN  2
#define RED    1

//混合颜色
#define BLACK  0
#define YELLOW  (RED|GREEN)
#define MAGENTA (GREEN|BLUE)
#define CYAN    (RED|GREEN|BLUE)

#define OPAQUE  0x1
#define FILL_BLUE 0x8
#define FILL_GREEN 0x4
#define FILL_MASK  0x2
#define BORDER    0xE
#define BORDER_BLUE  0x800

#define BORDER_GREEN 0x400
#define BORDER_RED   0x200
#define BORDER_MASK  0xE00
#define B_SOLID      0
#define B_DOTTED     0x1000
#define B_DASHED     0x2000
#define STYLE_MASK   3000

const char * colors[8]={"black","red","green","yellow","blue","magenta","cyan","white"};
struct box_props{
    bool opaque :1;
    unsigned int fill_color:3;
    unsigned int:4;
    bool show_border:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
    unsigned int :2;
};

union Views{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);
char * itobs(int n,char * ps);
int main() {
    union Views box={{true,YELLOW,true,GREEN,DASHED}};
    char bin_str[8*sizeof(unsigned int )+1];

    printf("Original box setting :\n");
    show_settings(&box.st_view);
    printf("\nBox settiing using unsigned int view:\n");
    show_settings1(box.us_view);

    printf("bits are %s\n",itobs(box.us_view,bin_str));
    box.us_view&=~FILL_MASK;
    box.us_view|=(FILL_BLUE|FILL_GREEN);
    box.us_view^=OPAQUE;
    box.us_view|=BORDER_RED;
    box.us_view&=~STYLE_MASK;
    box.us_view|=B_DOTTED;
    printf("\nModified box settings:\n");
    show_settings1(&box.st_view);
    printf("\nBox setting using unsigned innt view :\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",itobs(box.us_view,bin_str));
    return 0;
}
void show_settings(const struct box_props * pb){
    printf("Box is %s.\n",pb->opaque==true?"opaque":"transparent");
    printf("The fill color is %s.\n",colors[pb->fill_color]);
    printf("Border %s.\n",pb->show_border==true?"shown":"not shown");
    printf("The border color is %s.\n",colors[pb->border_color]);
    printf("The border style is");
    switch (pb->border_style) {
        case SOLLD:printf("solid.\n");
            break;
        case DOTTED:printf("dotted.\n");
            break;
        case DASHED:printf("dashed.\n");
            break;
        default:printf("unknown type.\n");
    }
}

void show_settings1(unsigned short us){
    printf("box is %s.\n",(us&OPAQUE)==OPAQUE?"opaque":"transparent");
    printf("The fill color is %s.\n",colors[(us>>1)&07]);
    printf("Border %s .\n",(us&BORDER)==BORDER?"shown":"not shown");
    printf("The border style is");
    switch (us&STYLE_MASK) {
        case B_SOLID:printf("solid.\n");
            break;
        case B_DOTTED:printf("dotted.\n");
            break;
        case B_DASHED:printf("dashed.\n");
            break;
        default:printf("unknown type.\n");
            break;
    }
    printf("The border color is %s .\n",colors[(us>>9)&07]);
}

char * itobs(int n,char * ps){
    int i;
    const static int size=CHAR_BIT*sizeof(int);
    for ( i = 0; i >=0 ; i--,n>>=1) {
        ps[i]=(01&n)+'0';
    }
    ps[size]='\0';
    return ps;
}