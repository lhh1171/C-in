#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream outFile;
    //没该文件可以创建文件
    outFile.open("c.txt");

    cout<<"Enter the make and model of automobile: ";
    /*与 getline 一样，cin.getline 允许读取包含空格的字符串。它将继续读取，直到它读取至最大指定的字符数*/
    cin.getline(automobile,50);
    cout<<"Enter the model year: ";
    cin>>year;
    cout<<"Enter the original asking price: ";
    cin>>a_price;
    d_price=0.913*a_price;

    /*cout<<fixed 表示用一般的方式输出浮点数*/
    cout<<fixed;
    /*cout.precision()其实是输出流cout的一个格式控制函数，也就是在iostream中的一个成员函数。
     * precision()返回当前的浮点数的精度值，而cout.precision(val)其实就是在输出的时候设定输出值以新的浮点数精度值显示，
     * 即小数点后保留val位。*/
    /*小数点后两位*/
    cout.precision(2);
    /**/
    /*ios::showpoint 强制输出浮点数的小点和尾数0*/
    cout.setf(ios_base::showpoint);
    cout<<"make and model : "<<automobile<<endl;
    cout<<"year: "<<year<<endl;
    cout<<"Was asking $"<<a_price<<endl;
    cout<<"Now asking $"<<d_price<<endl;


    outFile<<fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile<<"make and model : "<<automobile<<endl;
    outFile<<"year: "<<year<<endl;
    outFile<<"Was asking $"<<a_price<<endl;
    outFile<<"Now asking $"<<d_price<<endl;


    outFile.close();
    return 0;
}
/*C++中cout.setf(ios::left,ios::adjustfield); cout.setf(ios::showpoint,ios::showpint);
cout.setf(ios::scientific,ios::floatfield);
分别表示什么

参考以下：

1.使用控制符控制输出格式
控制符 作用
dec 设置整数的基数为10
hex 设置整数的基数为16
oct 设置整数的基数为8
setbase(n) 设置整数的基数为n(n只能是16,10,8之一)
setfill(c) 设置填充字符c,c可以是字符常量或字符变量
setprecision(n) 设置实数的精度为n位.在以一般十进制小数形式输出时,n代表有效数字.在以fixed(固定小数位数)形式和scientific(指数)形式输出时,n为小数位数.
setw(n) 设置字段宽度为n位.
setiosflags(ios::fixed) 设置浮点数以固定的小数位数显示.
setiosflags(ios::scientific) 设置浮点数以科学计数法(即指数形式)显示.
setiosflags(ios::left) 输出数据左对齐.
setiosflags(ios::right) 输出数据右对齐.
setiosflags(ios::shipws) 忽略前导的空格.
setiosflags(ios::uppercase) 在以科学计数法输出E和十六进制输出字母X时,以大写表示.
setiosflags(ios::showpos) 输出正数时,给出“+”号.
resetiosflags 终止已设置的输出格式状态,在括号中应指定内容.
2.用流对象的成员控制输出格式
流成员函数 与之作用相同的控制符 作用
precision(n) setprecision(n) 设置实数的精度为n位.
width(n) setw(n) 设置字段宽度为n位.
fill(c) setfill(c) 设置填充字符c.
setf( ) setiosflags( ) 设置输出格式状态,括号中应给出格式状态,内容与控制符setiosflags括号中内容相同.
ubsetf( ) resetiosflags( ) 终止已设置的输出格式状态.
cout.width(10);
cout.setf(ios::hex);
3.设置格式状态的格式标志
格式标志 作用
ios::left 输出数据在本域宽范围内左对齐
ios::right 输出数据在本域宽范围内右对齐
ios::internal 数值的符号位在域宽内左对齐,数值右对齐,中间由填充字符填充
ios::dec 设置整数的基数为10
ios::oct 设置整数的基数为8
ios::hex 设置整数的基数为16
ios::showbase 强制输出整数的基数(八进制以0打头,十六进制以0x打头)
ios::showpoint 强制输出浮点数的小点和尾数0
ios::uppercase 在以科学计数法输出E和十六进制输出字母X时,以大写表示
ios::showpos 输出正数时,给出“+”号.
ios::scientific 设置浮点数以科学计数法(即指数形式)显示
ios::fixed 设置浮点数以固定的小数位数显示
ios::unitbuf 每次输出后刷新所有流
ios::stdio 每次输出后清除stdout,stderr
以小数形式,保留三位小数输出：
cout
*/