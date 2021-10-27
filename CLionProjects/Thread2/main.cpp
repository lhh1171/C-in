#include <iostream>
#include <thread>

struct func{
    int i;
    func(int &i_) : i(i_) {
        std::cout<<"int"<<i_<<i<<std::endl;
    }

    /* func(int i) {};*/

/*首先, C++中的explicit关键字只能用于修饰只有一个参数的类构造函数,
 * 它的作用是表明该构造函数是显示的, 而非隐式的,
 * 跟它相对应的另一个关键字是implicit, 意思是隐藏的,
 * 类构造函数默认情况下即声明为implicit(隐式).*/
    static void do_something(int &i) {
        std::cout<<"something"<<i<<std::endl;
    }

    void operator()(){
        for (unsigned j = 0; j <10 ; ++j) {
            do_something(i);
        }
    }
};
void do_something_in_current_thread(){
    std::cout<<"do something"<<std::endl;
}
//等待线程结束
void f(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try {
        do_something_in_current_thread();
    } catch (...) {
        t.join();
        throw ;
    }
    t.join();
}
int main() {
    f();
    return 0;
}
