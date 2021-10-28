#include <iostream>
#include <vector>

int main() {
    using namespace std;
    vector<int> inev(1,2);
    int coun=0;
    vector<int>::iterator first=inev.begin();
    for (int i = 0; i <= 100; ++i) {
        first =inev.insert(first,i);
        coun++;
    }
//    while (first != inev.end()) {
//        // do some processing
//        // insert new value and reassign first, which otherwise would be invalid
//        inev.insert(first, 42);
//        ++first; // advance first just past the element we added
//    }

    for (vector<int>::iterator iterator=inev.begin(); iterator!=inev.end() ; ++iterator) {
        cout<<*iterator<<endl;
    }

    std::cout << coun << std::endl;
    return 0;
}
