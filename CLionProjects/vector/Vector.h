//
// Created by lqc on 2021/10/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include "iostream"
namespace VECTOR{
    class Vector {
    public:
        enum Mode{RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1,double n2,Mode form=RECT);
        void reset(double n1,double n2,Mode form=RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const ;
        Vector operator*(double n) const ;

        friend Vector operator*(double n,const Vector & a);
        //
        friend std::ostream&operator<<(std::ostream & os,const Vector & v);

    };
}

/*
1. 第一个ostream&，返回的是ostream类对象的引用，为了进行连续的运算，如cout<<a<<b;
先进行cout<<a，运算玩了，返回cout的引用，就是返回了cout本身，原来的式子变为cout<<b;
这样就能连续写了，cout<<a<<b<<c<<........

2. 第二个ostream& out, out是随便取的名字，就是ostream类的对象，与cout用法一样，
通过<<将数据传到out里，所以输出时用cout<<a，这时就调用 operator<<(cout,a)， 把cout作为参数传入。
对于上述例子cout<<date<<endl;，就是执行了cout<<date.year<<'-'<<date.month<<'-'<<date.day;
 return cout；注意，这里就是cout，其中year等是基本类型，c++已经写好了）
再次说明cout并不特殊，就是预先定义好了的ostream类的对象。

3. 第三个const Date&，主要为了快速出入参数，如果不用&，将会复制一个参数，而不是将原来的对象直接传入，
 就会调用拷贝构造函数（如果没写的话编译器自动提供），浪费时间，有时还会产生错误，比如数据成员里有指针时，
 编译器提供的拷贝构造函数将会自动复制 一个指针，与原来的指针指向同一个地址，这样改变一个另一个也会改变，
 这是我们不想要的，我们需要拷贝时指针指向不同的地址，两个对象互不干扰，只是指针所指变量的值相等就行，
 这就需要自己写 拷贝构造函数，自己new等。 所以一般用&，加const防止意外修改。

*/
#endif //VECTOR_VECTOR_H
