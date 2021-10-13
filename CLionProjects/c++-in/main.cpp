#include <iostream>
#include <fstream>
const int SIZE=60;
int main() {
    using namespace std;
    ifstream inFile;
    char filename[SIZE];
    cout<<"Enter name of data file: ";
    cin.getline(filename,60);
    inFile.open(filename);
    if (!inFile.is_open()){
        cout<<"Could not open the file "<<filename<<endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum=0.0;
    int count=0;
    while (inFile.good()){
        //表示文件正常，没有读写错误，也不是坏的，也没有结束
        count++;
        sum+=value;
        inFile>>value;
        cout<<value<<endl;
    }
    if(inFile.eof()){
        cout<<"End of file reached.\n";
    } else if(inFile.fail()){
        cout<<"Input terminated by data mismatch.\n";
    } else{
        cout<<"Input terminate for unknown reason.\n";
    }

    if (count==0){
        cout<<"No data process.\n";
    } else{
        cout<<"Item read: "<<count<<endl;
        cout<<"Sum: "<<sum<<endl;
        cout<<"Average: "<<sum/count<<endl;
    }
    inFile.close();
    return 0;
}
