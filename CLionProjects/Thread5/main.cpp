#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
/*其实，这里最常用的是使用关键字class，而且二者功能完全相同，这里的class和定义类时的class完全是两回事，
 * C++当时就是为了减少关键字，才使用了class。*/
/*typename难道仅仅在模板定义中起作用吗？其实不是这样，typename另外一个作用为：使用嵌套依赖类型(nested depended name)，如下所示：
复制代码
class MyArray
{
  public：
  typedef int LengthType;
  .....
}
template<class T>
void MyMethod( T myarr )
{
  typedef typename T::LengthType LengthType;
  LengthType length = myarr.GetLength;
}*/
template<typename Iterator,typename T>
struct accmulate_block{
    void operator()(Iterator first,Iterator last,T& result){
        result=std::accumulate(first,last,result);
    }
};
/*start：是迭代器的初始位置

end：是迭代器的最后一个位置。

注意：还可以在累加函数中传递一个附加参数，该参数指定要执行的操作的类型。

accumulate()具有附加参数的函数语法：

    accumulate(start, end, initial_sum, func);
在这里，func是要执行的附加操作。*/
class ss{

};
template <typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init){
    unsigned long const length=std::distance(first,last);
    if (!length){return init;}
    unsigned long const min_per_thread=25;
    unsigned long const max_threads=(length+min_per_thread-1)/min_per_thread;
    unsigned long const hardware_threads=std::thread::hardware_concurrency();
    unsigned long const num_threads=std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    unsigned long const block_size=length/num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);
    Iterator block_start=first;
    for (unsigned long i = 0; i <(num_threads-1) ; ++i) {
        Iterator block_end=block_start;
        std::advance(block_end,block_size);
        threads[i]=std::thread(accmulate_block<Iterator,T>(),block_start,block_end,std::ref(results[i]));
        block_start=block_end;
    }
    accmulate_block<Iterator,T>()(block_start,last,results[num_threads-1]);
    std::for_each(threads.begin(),threads.end(),std::mem_fn(&std::thread::join));
    return std::accumulate(results.begin(),results.end(),init);
}
/*distance( )函数
详细的定义可以参考如下代码：
function template
<iterator>
template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance (InputIterator first, InputIterator last);

作用是：返回两个迭代器之间的距离，也可以理解为计算两个元素 first 和 last 之间的元素数。
*/
int main() {
//
//    //创建一个 forward_list 容器
//    std::forward_list<int> mylist{1,2,3,4};
//    //it为前向迭代器，其指向 mylist 容器中第一个元素
//    std::forward_list<int>::iterator it = mylist.begin();
    using namespace std;
    vector<int> vt(1,2);
    int a=0;
    vector <int>::iterator iter_start=vt.begin();//起始地址
    vector <int>::iterator iter_end=vt.end();//结束地址
    parallel_accumulate(iter_start,iter_end,a);
    cout<<a<<endl;
    return 0;
}
/*std :: accumulate
累计范围内的值
返回将范围中的所有值累加[first,last)到init的结果。

默认操作是向上添加，但可以将不同的操作指定为binary_op。

accumulate (InputIterator first, InputIterator last, T init, BinaryOperation binary_op);

参数
first,last:
将迭代器输入到序列中的初始位置和最终位置。使用的范围是[first,last)，它包含所有的元件第一和最后一个，包括由指向的元件第一但不被指向的元素最后。

init
累加器的初始值。

binary_op
myfunction (int x, int y)；这样的函数时，init传入x，前面的范围和传入y，最后返回函数值。
std::minus()；返回init-范围和
int operator()(int x, int y)；和函数那个一样效果。

返回值
累积init：和范围内所有元素的结果[first,last)。
*/