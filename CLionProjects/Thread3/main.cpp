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
class  thread_guard{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):t(t_){}
    ~thread_guard(){
        if (t.joinable()){
            t.joinable();
        }
    }
    //拷贝构造函数和拷贝赋值运算符都被标记=delete,以确保他们不会由编译器自动提供
    thread_guard(thread_guard const &)=delete ;
    thread_guard operator=(thread_guard const &)=delete ;
};

void do_something_in_current_thread();

void f(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    do_something_in_current_thread();
}

void do_something_in_current_thread() {
    std::cout<<"do_something_in_current_thread"<<std::endl;
}

int main() {
    f();
    return 0;
}
